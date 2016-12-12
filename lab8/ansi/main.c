#include <stdio.h>
#include <stdlib.h>

int myRandForX(int axisX, int axisXend);
int myRandForY(int axisY, int axisYend);

int main() {
    double rad;
    int axisStartForX, axisXend, axisYend, axisStartForY;
    double valuesX, valuesY;
    int i = 0,l = 0,kol_dot;
    int x[250];
    int y[250];

    printf("Введите параметры поиска\n\nНачальное значение оси: ");
    scanf("%i", &axisStartForX);
    axisStartForY = axisStartForX;

    printf("Конечное значение по оси X: ");
    scanf("%i", &axisXend);

    printf("Конечное значение по оси Y: ");
    scanf("%i", &axisYend);

    kol_dot = 1 + rand() % (249);
    for (i = 0; i < kol_dot; ++i) {
        x[i] = myRandForX(axisStartForX, axisXend);
        y[i] = myRandForY(axisStartForY, axisYend);
    }

    i = 1 + rand() % (249); /*тот же алгоритм, (250-1) */
    printf("Координаты случайно выбранной точки [%i,%i]\n", x[i],y[i]);


    printf("Введите радиус окружности, в которой будем искать точки ");
    scanf("%lf", &rad);

    i=0;
    while (x[i] != 0) {
        if (x[i] * x[i] + y[i] * y[i] <= rad * rad) {
            l++; /*+1 к счетчику, принадлежит*/
        }
        i++;
    }
    printf("Количество точек, принадлежащих окружности составляет: %i\n",l);
}

int myRandForX(int x, int xEnd) {
    return x + rand() % (xEnd - x);
}

int myRandForY(int y, int yEnd) {
    return y + rand() % (yEnd - y);
}