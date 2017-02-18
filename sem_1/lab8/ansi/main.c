#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int amt(int amtDot); /*amt(amount) - количество*/

int main() {
    double rad;
    int axis = -5, axisEnd = 5;
    double valuesX, valuesY;
    int i = 0, l = 0, amtDot, m = 0, n;
    double perfectDot[2];

    printf("Введите радиус окружности, в которой будем искать точки ");
    scanf("%lf", &rad);
    FILE *file;
    file = fopen("//home//iarven//prog//time.txt", "w+");

    for (amtDot = 100; amtDot <= 5000; amtDot += 100) { /*каждую итерацию увеличиваем количество точек*/
        clock_t time; /* найдем время выполнения программы */
        time = clock();

        double x[amtDot];
        double y[amtDot];

        for (i = 0; i < amtDot; ++i) {                 /*здесь есть функция генерации значений))*/
            x[i] = -5 + rand() % 9;
            y[i] = -5 + rand() % 9;
        }
        if (amtDot == 10) {
            i = 1 + rand() % 9; /*тот же алгоритм, (250-1) */
            perfectDot[1] = x[i];
            perfectDot[2] = y[i];
            printf("Наша точка: {%lf,%lf}",perfectDot[1],perfectDot[2]);
        }

        while (m != amtDot) {
            if (sqrt((pow(perfectDot[1] - x[m], 2)) + (pow(perfectDot[2] - y[m], 2))) <= rad) {
                l++; /*+1 к счетчику, принадлежит*/
            }
            m++;
        }
        printf("При %i количестве точек, количество точек, принадлежащих окружности составляет: %i\n", amtDot,l);

        time = clock() - time;
        printf("Время выполнения = %f\n", (double) time / CLOCKS_PER_SEC);
        fprintf(file, "Количество точек = %i", l);
        fprintf(file, "\t\tВремя%f\n", (double) time / CLOCKS_PER_SEC);
    }
    fclose(file);
}

