#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

double function_G(double argument, double parrametr);

int main() {

    double G, g1; /*переменная, хранящая значение функции*/
    char rec[6] = {0};
    double border_arg_start;
    int kol_step;
    char sel; /*выбор буквы функции*/
    double x_values[500];
    double a_values[500];
    double function_values[500];
    char run,adaptive; /*проверка на рестарт, проверка на адаптивный шаг*/
    run = '1';

    do {

        printf("%s", "Введите первую границу для аргумента");
        scanf("%s", rec);
        border_arg_start = atof(rec);

        printf("%s", "Введите вторую границу для аргумента");
        scanf("%s", rec);
        double border_arg_end;
        border_arg_end = atof(rec);

        printf("%s", "Введите первую границу для параметра");
        scanf("%s", rec);
        double border_param_start;
        border_param_start = atof(rec);

        printf("%s", "Введите вторую границу для параметра");
        scanf("%s", rec);
        double border_param_end;
        border_param_end = atof(rec);

        printf("%s", "Введите количество шагов");
        scanf("%s", rec);
        kol_step = atoi(rec);

        double step_for_arg = (border_arg_end - border_arg_start) / kol_step - 1;
        double step_for_param = (border_param_end - border_param_start) / kol_step - 1;

        printf("%s", "Введите букву выражения, которое хотите вычислить");
        scanf("%s", &sel);

        printf("%s", "Включаем адапливный шаг?\nЕсли да, то количество шагов изменится с:\n"
                "Введи 'y' если хочешь все поломать\nи любую другую букву или число, чтобы не включать этот ад");
        scanf("%s",&adaptive);

        double argument = border_arg_start;
        double parrametr = border_param_start;
        FILE *file;
        file = fopen("//home//iarven//prog//result.txt", "ab+");

        switch (sel) {
            case 'G':
                printf("%s", "Значение функции ");
                printf("%s", "Значение параметра");
                printf("%s", "Значение аргумента\n ");
                int i = 0;
                int k=0;
                for (i = 0; i < kol_step; ++i) {
                    g1 = function_G(argument, parrametr);
                    printf("%10.5lf", g1);
                    fprintf(file, "%lf", g1);
                    argument += step_for_arg;
                    printf("%15.3lf %.2lf", argument, step_for_arg);
                    fprintf(file, "%lf", argument);
                    parrametr += step_for_param;
                    printf("%15.3lf %.2lf\n", parrametr,step_for_param);
                    fprintf(file, "%lf", parrametr);
                    printf("\n");
                    x_values[k] = parrametr;
                    a_values[k] = argument;
                    function_values[k] = g1;
                    k+=1;
                    double g2 = function_G(argument,parrametr);
                    if (adaptive == 'y') {
                        if (fabs(g2 - g1) > 10) {
                            step_for_param /= 2;
                            step_for_arg /= 2;
                            i -= 1;
                        }
                    }
                }
                int l = 0;
                while (l < kol_step) {
                    printf("%.5lf ",function_values[l]);
                    l+=1;
                }

                int j = 1;
                double min_param = function_values[0];
                for (j = 1; j < kol_step; ++j) {
                    if (min_param>function_values[j])
                        min_param = function_values[j];
                }
                printf("\nминимум x - %lf\n", min_param);

                char *explain;
                char *function_temp;
                for (j = 0; j < kol_step; ++j) {
                    sprintf(function_temp, "%.3lf", function_values[j]);
                    strcat(explain, function_temp);
                }
                printf("%s", explain);

                printf("%s","Введите подстроку(шаблон для поиска)");
                char example[200];
                scanf("%s", example);

                char *result;
                result = strstr(explain,example);
                if (result != NULL) {
                    do {
                        result = strstr(explain,example);
                        double len_example = strlen(example);
                        double diff = result - example;
                        double blya = len_example + diff;
                        for (j = 0; j <= blya; ++j) {
                            memset(explain,'/',j);
                            if (j == blya) {
                                i+=1;
                            }
                        }
                    } while (result != NULL);
                printf("\nСКОЛЬКО?1", i);
                }

                break;
            default:
                printf("Не умничай, и бей по клавишам точнее! Нет такой функции.");
                return 0;
        }
    } while (run == 1);
}

double function_G(double argument1, double parrametr1) {
    if ((4 * (argument1 * argument1) + argument1 * parrametr1 - 5 * (parrametr1 * parrametr1)) < 0.0000000001 &&
        (4 * (argument1 * argument1) + argument1 * parrametr1 - 5 * (parrametr1 * parrametr1)) > -0.0000000000001) {
        printf("Ошибка. Деление на ноль невозможно");
        return 0;
    } else {
        double G1 =
                -(8 * (12 * (argument1 * argument1) + 68 * argument1 * parrametr1 + 63 * (parrametr1 * parrametr1))) /
                (4 * (argument1 * argument1) + argument1 * parrametr1 - 5 * (parrametr1 * parrametr1));
        return G1;
    }
}

