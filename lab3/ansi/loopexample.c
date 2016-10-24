#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "lab3.h"

int main()
{
    char r;
    double G,F,Y,a,x,run,y1,y2, step;
    const double pi=3.14;
    int start_f, end_f;
    run=1;

    do {

        printf("Введите x: \n");
        scanf("%lf", &x);

        printf("Введите a: \n");
        scanf("%lf", &a);

        printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
        scanf("%s", &r);

        printf("введите начало функции");
        scanf("%i", &start_f);

        printf("введите конец функции");
        scanf("%i", &end_f);

        printf("введите шаг");
        scanf("%lf", &step);

        switch (r) {
            case 'G':
                while (start_f < end_f) {
                    y1 = -(8 * (12 * (a * a) + 68 * a * x + 63 * (x * x)));
                    y2 = (4 * (a * a) + a * x - 5 * (x * x));
                    if (y2 <= 0.0001) {
                        printf("На ноль делить нельзя");
                    } else {
                        G = y1 / y2;
                        printf("G = %lf \n", G);
                        writeValueToDataFile(x, F);
                        x=x+step;
                    }
                }
                    break;

            case 'F':
                F = (sin(pi * (40 * (a * a) - 61 * a * x + 7 * (x * x)))) /
                    (pi * (40 * (a * a) - 61 * a * x + 7 * (x * x)));
                printf("F = %lf \n", F);
                break;

            case 'Y':
                Y = -7 * (a * a) + 40 * a * x + 63 * (x * x) + 1;
                printf("Y = %lf \n", Y);
                break;
        }
        printf("Вычислим еще раз? (1-да,2-нет) \n");
        scanf("%lf", &run);

    }
    while (run==1);

    return 0;
}