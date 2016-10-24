#include <stdio.h>
#include <math.h>
int main()
{
    char r;
    double G,F,Y,a,x;
    const double pi=3.14;
    printf("Введите x: \n");
    scanf ("%lf", &x);

    printf("Введите a: \n");
    scanf ("%lf", &a);

    printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
    scanf ("%s", &r);

    switch (r){
        case 'G':
            G=-((8*((12*(a*a) +68*a*x+63*(x*x)))) / (4*(a*a)+a*x-5*(x*x)));
            printf("G = %lf \n", G);
            break;

        case 'F':
            F=(sin(pi*(40*(a*a)-61*a*x+7*(x*x))))/(pi*(40*(a*a)-61*a*x+7*(x*x)));
            printf("F = %lf \n", F);
            break;

        case 'Y':
            Y=-7*(a*a)+40*a*x+63*(x*x)+1;
            printf("Y = %lf \n", Y);
            break;
    }

    return 0;
}
