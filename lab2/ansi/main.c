#include <stdio.h>
#include <math.h>

int main()
{
    int r;
    double G,Y,a,x;
    double F_res, f_1, f_2;
    const double pi=3.14;
    printf("Введите x: \n");
    scanf ("%lf", &x);

    printf("Введите a: \n");
    scanf ("%lf", &a);

    printf("1 - вычислить функцию G, 2 - вычислить функцию F, 3 - вычислить функцию Y) \n");
    scanf ("%i", &r);  /* ввод значения для выбора функции */

    switch (r){
        case 1:
            if ((4 * (a * a) + a * x - 5 * (x * x)) >= -0.00000001 && (4 * (a * a) + a * x - 5 * (x * x)) <= 0.00000001) { /* проверка входных значений на принадлежность области определения функции */
                printf("Входные значения не принадлежат области определения функции. (Введите другие значения)");
            } else {
                G = -((8 * ((12 * (a * a) + 68 * a * x + 63 * (x * x)))) / (4 * (a * a) + a * x - 5 * (x * x)));
                printf("G = %lf \n", G);
            }
            break;

        case 2:
            f_1 = sin(pi*(40*(a*a)-61*a*x+7*(x*x)));
            f_2 = (pi*(40*(a*a)-61*a*x+7*(x*x)));
            if (f_2 >= -0.00000001 && f_2 <= 0.00000000001) { /* проверкa входных значений на принадлежность области определения функции */
                printf("Входные значения не принадлежат области определения функции. (Введите другие значения)");
            }
            else {
                F_res = sin(f_1 / f_2);
                printf("F = %lf \n", F_res);
            }
            break;

        case 3:
            Y=-7*(a*a)+40*a*x+63*(x*x)+1;
            printf("Y = %lf \n", Y);
            break;

        default:
            printf("Нет такой функции");
    }
    return 0;
}