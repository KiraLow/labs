#include <stdio.h>

int main() {
    double x,y,e,yi;

    printf("%s", "Найдем значение квадратного корня числа, введите его: ");
    scanf("%lf", &x);
    getchar();

    printf("%s", "Введите точность, с которой хотите вычислить: ");
    scanf("%lf", &e);
    getchar();
    yi = x;
    do {
        y = yi; /* y = 25 */
        yi = (y + x / y) / 2; /*yi = 1*/
    }
    while ((y-yi)>=e);
    printf("результат = %2.0lf \n", y);
            return 0;
    }
