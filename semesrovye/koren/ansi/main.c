#include <stdio.h>

int main() {
    double x,y,yi;

    printf("Найдем значение квадратного корня числа, введите его: ");
    scanf("%lf", &x);

    yi = x;
    do {
        y = yi; /* y = 25 */
        yi = (y + x / y) / 2; /*yi = 1*/
    }
    while ((y - yi) >= 0.0001);
    printf("результат = %.3lf \n", y);
            return 0;
    }
