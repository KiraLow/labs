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
    double result_value[255];
    int kol_step = 0, j = 0,in = 0,l = 0;
    double run = 1;
    char rec[100], result[255] = {0}, temp[255], example[255] = {0};
    struct functionValues {
        double mass[100];
    }functionG;
    FILE *file;
    file = fopen("/home/vlad/Prg/lab7/result1.txt", "w+");
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

        while (kol_step > j) {
            G1 = -(8 * (12 * (aMod * aMod) + 68 * aMod * xMod + 63 * (xMod * xMod)));
            G2 = (4 * (aMod * aMod) + aMod * xMod - 5 * (xMod * xMod));
            if (G2 <= 0.00000000001 && G2 >= -0.00000000001) {
                printf("На ноль делить нельзя");
                return 0;
            } else {
                G = G1 / G2;
                functionG.mass[in] = G;
                fprintf(file, "%lf\n", functionG.mass[in]);
                fflush(file);
                i += 1;
                xMod += StepForX;
                aMod += StepForA;
                j += 1;
                in++;

            }
        }
        functionG.mass[0] = '\0';
        int i1 = 0;
        printf("Обнулили массив: \n");
        for (i1 = 0; i1 < kol_step; ++i1) {
            printf("%lf", mass[i1]);
        }
        printf("\n");
        fclose(file);
        FILE *file1;
        file1 = fopen("/home/vlad/Prg/lab7/result1.txt", "r+");
        if (file1 == 0)
        {
            printf("не открыли файл, сорян\n");
            exit(1);
        }
        for (l = 0; l < kol_step; ++l) {
            fscanf(file1, "%lf", &result_value[l]);
        }

        double minG = functionG.mass[0], maxG = functionG.mass[0];

        for (k = 0; k < i; ++k) {
            if (result_value[k] > maxG) {
                maxG = result_value[k];
            }
        }
        printf("Максимальное значение в массиве - %lf\n", maxG);

        for (k = 0; k < i; ++k) {
            if (result_value[k] < minG) {
                minG = result_value[k];
            }
        }
        printf("Минимальное значение в массиве - %lf\n", minG);

        for (l = 0; l < i; ++l) {
            sprintf(temp, "%lf", result_value[l]);
            strcat(result, temp);
        }
        printf("*Полученный массив результатов представить в виде одной строки*\n%s\n", result);

        int m = 0;
        /*Поиск подстроки*/
        scanf("%s", example);
        l = 0;
        m = 0;
        while (m != 255 && example[m] != 0) {  /*подсчитывающую количество четных цифр в введенном числе*/
            if ((example[m] % 2) == 0) {
                m++;
                l++;
            } else {
                m++;
            }
        }
        printf("Количество четных чисел = %i\n", l);
        i = 0, k = 0;
        int n = 0;
        while (n < strlen(result)) {
            if (strstr(result, example) - result + 1 < strlen(result)) {
                i++;  /*В найденной последовательности найти строку совпадающую с шаблоном*/
                n = (int) (strstr(result, example) - result + 1);
                while (k != n) {
                    result[k] = '/';
                    k++;
                }
                k = 0;
            }
            if (strstr(result, example) == 0)
                break;
        }
        printf("Найдено совпадений: %i\n", i); /*Вывести количество найденных совпадений в исходной строке*/

        fclose(file);
        printf("Вычислим еще раз? (1-да,2-нет) \n");
        scanf("%lf", &run);
    } while (run == 1);
    return 0;
}