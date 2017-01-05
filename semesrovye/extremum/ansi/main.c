#include <stdio.h>
double F(double x)
{
    return  x*x*4+x*2;
}
int main() {
    double a,b,f1,f2,e,x,x1,x2;

    printf("%s", "Введите точку a, начало интервала: ");
    scanf("%lf", &a); /* число 1 в интервале */

    printf("%s", "Введите точку b, конец интервала: "); /* число 2 в интервале */
    scanf("%lf", &b);

    printf("%s", "Введите точность, с которой хотите найти минимум: "); /* точность */
    scanf("%lf", &e);

    do {
        x=(a+b)/2;

        f1 = F (x - e);
        f2 = F (x + e);
        if (f1<f2)
            b=x;
        else
            a=x;
    }
    while (b-a<e);
    printf("результат = %lf \n", F(a));

}
