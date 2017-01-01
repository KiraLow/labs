#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int run,kol_step,j=0;
    char r;
    double G,a,diff, diff_Y,Y,step_for_x;
    const double pi=3.14;
    double g_1,g_2, diff_G,f_1,f_2,diff_F,F;
    float x1,x2,x_mod;
    run=1;
    do {
        printf("Введите первую границу параметра: \n");
        scanf("%f", &x_mod);

        printf("Введите вторую границу параметра: \n");
        scanf("%f", &x2);

        printf("Введите аргумент: \n");
        scanf("%lf", &a);

        printf("Введите количество шагов: \n");
        scanf("%i", &kol_step);
        step_for_x = (x2 - x_mod) / (kol_step -1);

        printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
        scanf("%s", &r);

        printf("Введите разницу между функциями) \n");
        scanf("%lf", &diff);

            switch (r) {
                case 'G':
                    while (kol_step > j) {
                        g_1 = -(8 * (12 * (a * a) + 68 * a * x_mod + 63 * (x_mod * x_mod)));
                        g_2 = (4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod));
                            if (g_2 <= 0.0000000001 && g_2 >= -0.00000001) {
                                printf("На ноль делить нельзя");
                            }
                            else {
                                G = g_1 / g_2;
                                printf("G = %.5lf ", G);
                                printf("step = %5.10lf ", step_for_x);
                                x_mod += step_for_x;
                                diff_G = -(8 * (12 * (a * a) + 68 * a * x_mod + 63 * (x_mod * x_mod))) /
                                           (4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod));
                                printf("diffG = %5.5lf \n ", diff_G);
                                if (diff < fabs(diff_G - G)) {
                                    step_for_x /=2;
                                    x_mod +=step_for_x;
                                    j-=1;
                                }
                            }
                            j+=1;
                        }
                    break;

                case 'F':
                    while (kol_step > j) {
                        f_1 = (sin(pi * (40 * (a * a) - 61 * a * x_mod + 7 * (x_mod * x_mod))));
                        f_2 = (pi * (40 * (a * a) - 61 * a * x_mod + 7 * (x_mod * x_mod)));
                        if (f_2 != 0.0 ) {
                            F = f_1/f_2;
                            printf("F = %.15lf", F);
                            printf("\tstep = %5.7lf", step_for_x);
                            x_mod += step_for_x;
                            diff_F = ((sin(pi * (40 * (a * a) - 61 * a * x_mod + 7 * (x_mod * x_mod)))) /(pi * (40 * (a * a) - 61 * a * x_mod + 7 * (x_mod * x_mod))));
                            printf("\tdiffF = %.15lf \n", diff_F);
                            if (diff < fabs(diff_F - F)) {
                                step_for_x /=2;
                                x_mod += step_for_x;
                                j-=1;
                            }
                        }
                        j+=1;
                    }
                    break;
                case 'Y':
                    while (x_mod <= x2) {
                        Y = -7 * (a * a) + 40 * a * x_mod + 63 * (x_mod * x_mod) + 1;
                        printf("Y = %lf", Y);
                        printf("\tstep = %5.15lf", step_for_x);
                        x_mod += step_for_x;
                        diff_Y = -7 * (a * a) + 40 * a * x_mod + 63 * (x_mod * x_mod) + 1;
                        printf("\tdiffY = %lf \n", diff_Y);
                        if (diff < fabs(diff_Y - Y)) {
                            step_for_x /= 2;
                            x_mod+=step_for_x;
                            j-=1;
                        }
                        j+=1;
                    }
                default:
                    printf("Что-то не то, давай еще раз \n");
            }
        printf("Вычислим еще раз? (1-да,2-нет) \n");
        scanf("%i", &run);
    }
    while (run==1);
    return 0;
}