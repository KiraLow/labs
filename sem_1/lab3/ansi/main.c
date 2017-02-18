#include <stdio.h>
#include <math.h>

int main() {
    double G, F, Y, a, x1, x2, b, min_value, max_value;
    int i, j;
    char r;
    const double pi = 3.14;
    double pr = 1;

    nachalo:

    printf("%s", "Введите  x1: ");
    scanf("%lf", &x1);

    printf("%s", "Введите x2 ");
    scanf("%lf", &x2);

    printf("%s", "Введите a: ");
    scanf("%lf", &a);

    printf("%s", "Введите параметр шага  ");
    scanf("%lf", &b);

    double mas[200];
    j = 0;
    max_value = 0;
    min_value = 0;
    printf("Введите букву выражения, которое хотите вычислить - G,F,Y) \n");
    scanf ("%s", &r);

    switch (r) {
        case 'G':
            while (x1 <= x2) {
                if ((45 * (pow(a, 2)) - 29 * a * x1 + 4 * (pow(x1, 2))) != 0)
                    G = -(16 * ((pow(a, 2) + 24 * a * x1 - 27 * (pow(x1, 2))))) /
                        (45 * (pow(a, 2)) - 29 * a * x1 + 4 * (pow(x1, 2)));
                    printf("X = %.3lf \t| Y = %.3lf\n", x1, G);
                    x1 = x1 + b;
                    mas[j] = G;
                    if (j <= 0.000001 && j >= -0.000001) {
                        max_value = G;
                        min_value = G;
                    }
                    if (G > max_value) max_value = mas[j];
                    if (G < min_value) min_value = mas[j];
                    j += 1;
            }
            printf(" Максимальное значение  = %9.3lf\n Минимальное значение = %9.3lf\n", max_value, min_value);
            break;

        case 'F':
            while (x1 <= x2) {
                F = -(atan(pi * (10 * (a * a) + 13 * a * x1 - 30 * (x1 * x1))));
                printf("%f\n", F);
                x1 = x1 + b;
                mas[j] =F;
                j += 1;
                j = 0;
                max_value = mas[0];
                min_value = mas[0];
                j += 1;
                if (mas[j] > max_value)
                    max_value = mas[j];
                if (mas[j] < min_value)
                    min_value = mas[j];

                printf(" Максимальное значение  = %9.3lf\n Минимальное значение = %9.3lf\n", max_value, min_value);

            }

            break;

        case 'Y':
            while (x1 <= x2) {
                Y = (log(2 * pow(a, 2) + 19 * a * x1 + 9 * pow(x1, 2) + 1)) / log(10);
                printf("%f\n", Y);
                x1 = x1 + b;
                mas[j] = Y;
                j += 1;
                j = 0;
                max_value = mas[0];
                min_value = mas[0];
                j += 1;
                if (mas[j] > max_value)
                    max_value = mas[j];
                if (mas[j] < min_value)
                    min_value = mas[j];

                printf(" Максимальное значение  = %9.3lf\n Минимальное значение = %9.3lf\n", max_value, min_value);

            }

            break;

        default:
            printf("ne verno vvedena function \n");

    }
    printf("Вычислим еще раз? (1-да,2-нет) \n");
    scanf("%lf", &pr);
    if (pr == 1)
        goto nachalo;
    return 0;
}