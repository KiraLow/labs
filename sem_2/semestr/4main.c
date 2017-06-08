#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
    fstream f;
    string file_name;
    long total=0;
    int code[256] = {0};
    float entr=0, prob;

    cout << "Input file name: " ;
    cin >> file_name;
    f.open( file_name.c_str(), ios::in | ios::binary);
    if( !f ) {
        cout << "Error: open file" << file_name << endl;
        return 1;
    }

    float start_time =  clock();
    char ch;
    f.unsetf(ios::skipws);
    while( !f.eof() ) {
        f >> ch;
        if( !f.eof() ) {
            code[(int)ch]++;
            total++;
        }
    }
    f.close();

    for( int i=0; i < 256; i++ ) {
        if( code[i] == 0 )
            continue;
        prob=code[i]/(float)total;
        entr-=prob*log(prob)/log(2.0f);
    }
    float end_time = clock(); // конечное время
    float search_time = end_time - start_time;

    cout << "Bytes: " << total << endl;
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << "Entropy: " << entr << endl;
    cout.precision(10);
    cout << "Time: " << search_time<< endl;

    _getch();
    return 0;
}
