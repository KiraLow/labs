#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char r;
    double G, F, Y, G1, G2;
    const double pi = 3.14159265358979;
    double StepForX, StepForA;
    double x2, a2, xMod, aMod;
    int kol_step = 0,j = 0, cnt = 0;
    double run = 1;
    char rec[100],result[255] = {0},temp[255],example[255] = {0};
    do {

        printf("Введите первую границу для аргумента: \n");  /*Организовать ввод начального и конечного значений аргумента*/
        scanf("%s", rec);
        xMod = atof(rec);  /*использовать функции преобразования из строки в число*/

        printf("Введите вторую границу для аргумента: \n");
        scanf("%s", rec);
        x2 = atof(rec);

        printf("Введите первую границу для параметра: \n"); /*...и  параметра*/
        scanf("%s", rec);
        aMod = atof(rec);

        printf("Введите вторую границу для параметра: \n");
        scanf("%s", rec);
        a2 = atof(rec);

        printf("Введите количество шагов: \n");  /*количество шагов расчета функций G, F, Y*/
        scanf("%s", rec);
        kol_step = atoi(rec);
        double mass[kol_step];

        StepForX = (x2 - xMod) / (kol_step - 1);
        StepForA = (a2 - aMod) / (kol_step - 1);

        printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
        scanf("%s", &r);
        int i = 0;
        int k = 0;

        switch (r) {
            case 'G':
                printf("Значение функции ");
                printf(" Значение X\n");
                while (kol_step > j) {
                    G1 = -(8 * (12 * (aMod * aMod) + 68 * aMod * xMod + 63 * (xMod * xMod)));
                    G2 = (4 * (aMod * aMod) + aMod * xMod - 5 * (xMod * xMod));
                    if (G2 <= 0.00000000001 && G2 >= -0.00000000001) {
                        printf("На ноль делить нельзя");
                    } else {
                        G = G1 / G2;
                        printf("%12.5lf ", G);
                        printf("%13.5lf ", xMod);
                        printf("\n");
                        mass[i] = G;  /*сохранением результатов в массив*/
                        i += 1;
                        xMod += StepForX;
                        aMod += StepForA;
                        j+=1;
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
                int l = 0;
                for (l = 0; l < i; ++l) {
                    sprintf(temp, "%lf", mass[l]);
                    strcat(result,temp);
                }
                printf("*Полученный массив результатов представить в виде одной строки*\n%s\n",result);

                int i=0,k=0,m=0,num2 = 0;
                /*Поиск подстроки*/
                scanf("%s", example);
                l=0;
                m=0;
                while (m != 255 && example[m] !=0) {  /*подсчитывающую количество четных цифр в введенном числе*/
                    if ((example[m] % 2) == 0) {
                        m++;
                        l++;
                    } else {
                        m++;
                    }

                }

                printf("%i",l);

                int n=0;
                while (n<strlen(result)) {
                    if (strstr(result,example) - result + 1 < strlen(result)) {
                        i++;  /*В найденной последовательности найти строку совпадающую с шаблоном*/
                        n = (int) (strstr(result, example) - result + 1);
                        while (k!=n) {
                            result[k] = '/';
                            k++;
                        }
                        k=0;
                    }
                    if (strstr(result,example) == 0)
                        break;
                }
                printf("Найдено совпадений: %i\n",i); /*Вывести количество найденных совпадений в исходной строке*/

                break;

            case 'F':
                while (xMod < x2) {
                    double F1, F2;
                    F1 = (sin(pi * (40 * (aMod * aMod) - 61 * aMod * xMod + 7 * (xMod * xMod))));
                    F2 = (pi * (40 * (aMod * aMod) - 61 * aMod * xMod + 7 * (xMod * xMod)));
                    if (F2 >= -0.00000000001 && F2 <= 0.000000001) {
                        F = F1 / F2;
                        printf("F = %lf", F);
                        printf(" при x = %lf", xMod);
                        mass[i] = F;
                        i =+ 1;
                        xMod += StepForX;
                        aMod += StepForA;
                    }
                }
                double minF = mass[0], maxF = mass[0];
                for (k = 0; k < i; ++k) {
                    if (mass[k] > maxF) {
                        maxF = mass[k];
                    }
                }
                printf("Максимальное значение в массиве - %lf\n", maxF);

                for (k = 0; k < i; ++k) {
                    if (mass[k] < minF) {
                        minF = mass[k];
                    }
                }
                printf("Минимальное значение в массиве - %lf\n", minF);
                break;

            case 'Y':
                while (xMod < x2) {
                    Y = -7 * (aMod * aMod) + 40 * aMod * xMod + 63 * (xMod * xMod) + 1;
                    printf("Y = %lf", Y);
                    printf(" при x = %lf", xMod);
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
