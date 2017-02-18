#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int n = 1000, yInt[1000], xInt[1000], a, j, i;
    float yFloat[1000], xFloat[1000];
    double xDouble[1000], yDouble[1000];
    double end, dif_int[1000],dif_double[1000],dif_float[1000];
    clock_t time,start;
    scanf("%i", &a);
    FILE *v;
    v = fopen("/home/vlad/Prg/semesrovye/saxpy/ansi/text.txt", "w+");
    for (i = 0; i < 1000; i++) {
        xInt[i] = rand() % 100 + 1;
        yInt[i] = rand() % 100 + 1;
        xFloat[i] = rand() % 100 + 1;
        yFloat[i] = rand() % 100 + 1;
        xDouble[i] = rand() % 100 + 1;
        yDouble[i] = rand() % 100 + 1;
    }
    for (j = 0; j < 4; ++j) {
        time = clock();
        fprintf(v, "Цикл №%i\n",j);
        for (i = 0; i < n; ++i) {
            yInt[i] = a * xInt[i] + yInt[i];
            if (i == 0) {
                fprintf(v, "В числах типа int :)\n");
                end = clock();
                dif_double[i] = end - time;
                fprintf(v, "При проходе в %i время будет равным %.10lf\t\n", i, dif_int[i]/CLOCKS_PER_SEC);
            }
            if ((i == 100) || (i == 200) || (i == 300) || (i == 400) || (i == 500)) {
                end = clock();
                dif_int[i] = end - time;
                fprintf(v, "При проходе в %i время будет равным %.10lf\t\n", i, dif_int[i]/CLOCKS_PER_SEC);

            }
        }
        time = clock();
        for (i = 0; i < n; ++i) {
            yFloat[i] = a * xFloat[i] + yFloat[i];
            if (i == 0) {
                fprintf(v, "В числах типа float :)\n");
                end = clock();
                dif_double[i] = end - time;
                fprintf(v, "При проходе в %i время будет равным %.10lf\t\n", i, dif_float[i]/CLOCKS_PER_SEC);
            }
            if ((i == 100) || (i == 200) || (i == 300) || (i == 400) || (i == 500)) {
                end = clock();
                dif_float[i] = end - time;
                fprintf(v, "При проходе в %i время будет равным %.10lf\t\n", i, dif_float[i]/CLOCKS_PER_SEC);
            }
        }
        time = clock();
        for (i = 0; i < n; ++i) {
            yDouble[i] = a * xDouble[i] + yDouble[i];
            if (i == 0) {
                fprintf(v, "В числах типа double :)\n");
                end = clock();
                dif_double[i] = end - time;
                fprintf(v, "При проходе в %i время будет равным %.10lf\t\n", i, dif_double[i]/CLOCKS_PER_SEC);
            }
            if ((i == 100) || (i == 200) || (i == 300) || (i == 400) || (i == 500)) {
                end = clock();
                dif_double[i] = end - time;
                fprintf(v, "При проходе в %i время будет равным %.10lf\t\n", i, dif_double[i]/CLOCKS_PER_SEC);
            }
        }
    }

    fclose(v);
    return 0;
}