#include <stdio.h>
#include <math.h>

int main() {
    char r;
    double G, F, Y, G1, G2;
    const double pi = 3.14159265358979;
    double StepForX, StepForA;
    double x2, a2, xMod, aMod;
    double run = 1;
    int kol_step;
    do {

        printf("Введите первую границу для аргумента: \n");  /*Организовать ввод начального и конечного значений аргумента*/
        scanf("%lf", &xMod);

        printf("Введите вторую границу для аргумента: \n");
        scanf("%lf", &x2);

        printf("Введите первую границу для параметра: \n"); /*...и  параметра*/
        scanf("%lf", &aMod);

        printf("Введите вторую границу для параметра: \n");
        scanf("%lf", &a2);

        printf("Введите количество шагов: \n");  /*количество шагов расчета функций G, F, Y*/
        scanf("%i", &kol_step);

        StepForX = (x2 - xMod) / (kol_step - 1);
        StepForA = (a2 - aMod) / (kol_step - 1);

        printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
        scanf("%s", &r);
        int i = 0;
        int k = 0;

        double mass[255];

        switch (r) {
            case 'G':
                printf("Значение функции ");
                printf(" Значение X\n");
                while (xMod <= x2) {
                    G1 = -(8 * (12 * (aMod * aMod) + 68 * aMod * xMod + 63 * (xMod * xMod)));
                    G2 = (4 * (aMod * aMod) + aMod * xMod - 5 * (xMod * xMod));
                    if (G2 <= 0.00000000001 && G2 >= -0.00000000001) {
                        printf("На ноль делить нельзя");
                    } else {
                        G = G1 / G2;
                        printf("%12.5lf ", G);
                        printf("%10.5lf ", xMod);
                        printf("\n");
                        mass[i] = G;  /*сохранением результатов в массив*/
                        i += 1;
                        xMod += StepForX;
                        aMod += StepForA;
                    }
                }
                double minG = mass[0], maxG = mass[0];
                for (k = 0; k < i; ++k) {
                    if (mass[k] > maxG) {
                        maxG = mass[k];
                    }
                }
                printf("Максимальное значение в массиве - %lf\n", maxG);

                for (k = 0; k < i; ++k) {
                    if (mass[k] < minG) {
                        minG = mass[k];
                    }
                }
                printf("Минимальное значение в массиве - %lf\n", minG);

                break;

            case 'F':
                while (xMod <= x2) {
                    double F1, F2;
                    F1 = (sin(pi * (40 * (aMod * aMod) - 61 * aMod * xMod + 7 * (xMod * xMod))));
                    F2 = (pi * (40 * (aMod * aMod) - 61 * aMod * xMod + 7 * (xMod * xMod)));
                    if (F2 >= -0.000000000000001 && F2 <= 0.00000000000001) {
                        printf("На ноль не делим");
                    } else {
                        F = F1 / F2;
                        printf("F = %.15lf", F);
                        printf("\tпри x = %lf\n", xMod);
                        mass[i] = F;
                        i =+ 1;
                        xMod += StepForX;
                        aMod += StepForA;
                    }
                }
                double maxF = mass[0];
                for (k = 0; k < i; ++k) {
                    if (mass[k] > maxF) {
                        maxF = mass[k];
                    }
                }
                printf("Максимальное значение в массиве - %.20lf\n", maxF);
                double minF = mass[0];
                for (k = 0; k < i; ++k) {
                    if (mass[k] < minF) {
                        minF = mass[k];
                    }
                }
                printf("Минимальное значение в массиве - %.20lf\n", minF);
                break;

            case 'Y':
                while (xMod < x2) {
                    Y = -7 * (aMod * aMod) + 40 * aMod * xMod + 63 * (xMod * xMod) + 1;
                    printf("Y = %lf", Y);
                    printf("\tпри x = %lf\n", xMod);
                    mass[i] = Y;
                    i += 1;
                    xMod += StepForX;
                    aMod += StepForA;
                }
                double minY = mass[0], maxY = mass[0];
                for (k = 0; k < i; ++k) {
                    if (mass[k] > maxY) {
                        maxY = mass[k];
                    }
                }
                printf("Максимальное значение в массиве - %lf\n", maxY);

                for (k = 0; k < i; ++k) {
                    if (mass[k] < minY) {
                        minY = mass[k];
                    }
                }
                printf("Минимальное значение в массиве - %lf\n", minY);
                break;
            default:
                printf("Введенное значение не обнаружено, пожалуйста, введите букву выражения, которое хотите вычислить - F,G,Y\n");
        }
        printf("Вычислим еще раз? (1-да,2-нет) \n");
        scanf("%lf", &run);
    } while (run == 1);
    return 0;
}