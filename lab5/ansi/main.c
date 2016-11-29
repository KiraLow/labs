#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    char r;
    double G, F, Y, g_1, g_2;
    const double pi = 3.14159265358979;
    double step_for_x, step_for_a;
    double x1, x2, a1, a2, x_mod, a_mod;
    char rec[100];
    char change[255];
    double run = 1;
    int kol_step;

    do {

        printf("%s", "Введите первую границу для аргумента: \n");
        scanf("%s", rec);
        x1 = atof(rec);

        printf("%s", "Введите вторую границу для аргумента: \n");
        scanf("%s", rec);
        x2 = atof(rec);

        printf("%s", "Введите первую границу для параметра: \n");
        scanf("%s", rec);
        a1 = atof(rec);

        printf("%s", "Введите вторую границу для параметра: \n");
        scanf("%s", rec);
        a2 = atof(rec);

        printf("%s", "Введите количество шагов: \n");
        scanf("%s", rec);
        kol_step = (int) atof(rec);

        step_for_x = (x2 - x1) / kol_step;
        step_for_a = (a2 - a1) / kol_step;

        printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
        scanf("%s", &r);
        int i = 0;
        int j = 0;
        x_mod = x1;
        a_mod = a1;
        double mass[3][kol_step];
        switch (r) {
            case 'G':
                printf("Значение функции ");
                printf(" Значение X\n");
                int m = 0;
                for (m = 0; m < kol_step; ++m) {
                    g_1 = -(8 * (12 * (a_mod * a_mod) + 68 * a_mod * x_mod + 63 * (x_mod * x_mod)));
                    g_2 = (4 * (a_mod * a_mod) + a_mod * x_mod - 5 * (x_mod * x_mod));
                    if (g_2 != 0) {
                        G = g_1 / g_2;
                        printf("%12.0lf ", G);
                        printf("%10.0lf ", x_mod);
                        printf("%10.0lf ", a_mod);
                        printf("\n");
                        mass[0][j] = G;
                        mass[1][j] = x_mod;
                        mass[2][j] = a_mod;
                        x_mod += step_for_x;
                        a_mod += step_for_a;
                        j+=1;
                    }
                }
                printf("значения \n");
                int k = 0;
                int l = 0;
                char mass0[300], mass1[300];
                for (k = 0; k < kol_step; k++) {
                    sprintf(mass0, "%.2lf ", mass[0][k]);/* в общем тут в массив mass0  я кладу первую строчку (ибо 0 это первая строчка) массива mass */
                    sprintf(mass1, "%.2lf ", mass[1][k]);/* тут вторую строчку в другой массив, mass 1*/
                    strcat(mass0,mass1); /* бай бай*/
                    printf("%s", mass0); /* выводим - профит!*/ /* ща попробую*/
                }

                    break;

                    case 'F':
                        while (x_mod < x2) {
                            double f_1, f_2;
                            f_1 = (sin(pi * (40 * (a_mod * a_mod) - 61 * a_mod * x_mod + 7 * (x_mod * x_mod))));
                            f_2 = (pi * (40 * (a_mod * a_mod) - 61 * a_mod * x_mod + 7 * (x_mod * x_mod)));
                            if (f_2 != 0.0) {
                                F = f_1 / f_2;
                                printf("F = %lf", F);
                                printf(" при x = %lf", x_mod );
                                mass[0][j] = F;
                                mass[1][j] = x_mod;
                                mass[2][j] = a_mod;
                                x_mod += step_for_x;
                                a_mod += step_for_a;
                            }
                        }
                    break;

                    case 'Y':
                        while (x_mod < x2) {
                            Y = -7 * (a_mod * a_mod) + 40 * a_mod * x_mod + 63 * (x_mod * x_mod) + 1;
                            mass[0][j] = Y;
                            mass[1][j] = x_mod;
                            mass[2][j] = a_mod;
                            printf("Y = %lf", mass[i][j]);
                            x_mod += step_for_x;
                            a_mod += step_for_a;
                        }
                    break;

                    default:
                        printf("Что то не то, введи еще раз");
                }
                printf("Вычислим еще раз? (1-да,2-нет) \n");
                scanf("%lf", &run);
    }
    while (run == 1);
    return 0;
}