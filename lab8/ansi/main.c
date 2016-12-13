#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myRandForX(int axisX, int axisEnd);
int myRandForY(int axisY, int axisYend);

int main() {
    double rad;
    int axisStartForX, axisEnd, axisStartForY;
    double valuesX, valuesY;
    int i = 0,l = 0, kol_dot;

    printf("Введите параметры поиска\n\nНачальное значение оси: ");
    scanf("%i", &axisStartForX);
    axisStartForY = axisStartForX;

    printf("Конечное значение по оси");
    scanf("%i", &axisEnd);

    printf("Введите радиус окружности, в которой будем искать точки ");
    scanf("%lf", &rad);
    FILE *file;
    file = fopen("//home//iarven//prog//time.txt", "w+");

    for (kol_dot = 10; kol_dot < 5000; kol_dot+=100) { /*каждую итерацию увеличиваем
 * количество точек*/

        clock_t time; /* найдем время выполнения программы */
        time = clock();

        int x[kol_dot];
        int y[kol_dot];

        for (i = 0; i < kol_dot; ++i) {
            x[i] = myRandForX(axisStartForX, axisEnd);
            y[i] = myRandForY(axisStartForY, axisEnd);
        }

        i = 1 + rand() % (kol_dot - 1); /*тот же алгоритм, (250-1) */
        printf("Координаты случайно выбранной точки [%i,%i]\n", x[i], y[i]);

        i = 0;
        while (x[i] != 0) {
            if (x[i] * x[i] + y[i] * y[i] <= rad * rad) {
                l++; /*+1 к счетчику, принадлежит*/
            }
            i++;
        }
        printf("Количество точек, принадлежащих окружности составляет: %i\n", l);

        time = clock() - time;
        printf("%f\n", (double)time/CLOCKS_PER_SEC);
        fprintf(file, "Количество точек = %i", l);
        fprintf(file, "\t\tВремя%f\n", (double)time/CLOCKS_PER_SEC);
    }
    fclose(file);
}

int myRandForX(int x, int xEnd) {
    return x + rand() % (xEnd - x);
}

int myRandForY(int y, int yEnd) {
    return y + rand() % (yEnd - y);
}
