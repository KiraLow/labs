#include <stdio.h>
#include <math.h>
int main()
{
    double G,F,Y,a,x;
    const double pi=3.14;
    printf("Введите x: \n");
    scanf ("%lf", &x);

    printf("Введите a: \n");
    scanf ("%lf", &a);

    G=-((8*((12*(a*a) +68*a*x+63*(x*x)))) / (4*(a*a)+a*x-5*(x*x)));
    F=(sin(pi*(40*(a*a)-61*a*x+7*(x*x))))/(pi*(40*(a*a)-61*a*x+7*(x*x)));
    Y=-7*(a*a)+40*a*x+63*(x*x)+1;

    printf("G =  %f \n", G);
    printf("F =  %f \n", F);
    printf("Y =  %f \n", Y);

    return 0;
}