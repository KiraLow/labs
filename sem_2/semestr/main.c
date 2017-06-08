#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

double fun(double, double);

double ln(double);
double Det(int, double);

void euler();

void Integ();

void Gauss();

void calc(double step, int start, int end);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char change;
    printf("Введите:"
                   "1 - метод Эйлера;\n"
                   "2 - Интегрирование;\n");
    scanf("%s", &change);
    switch (change) {
        case '1':
            euler();
            break;
        case '2':
            Integ();
            break;
    }
}

void Integ() {
    printf("Вычислить определённый интеграл:"
                   "b"
                   "∫dx/ln x"
                   "a\n");
    double step, end, start, x, S = 0;
    int stepCnt;
    printf("b = \n");
    scanf("%lf", &end);
    printf("a = \n");
    scanf("%lf", &start);
    printf("Количество шагов\n");
    scanf("%i", &stepCnt);
    double x1[stepCnt];
    step = (end - start) / stepCnt;
    int l = 0;
    for (x = start; x < end; x += step) {
        x1[l] = ln(x);
        S = S + x1[l];
        printf("%lf\t", x1[l]);
        printf("%lf\n", x);
        l++;

    }
    S = S * step;
    printf("Метод прямоугольников.\n\tПлощадь криволинейной трапеции = %lf\n", S);

    int i, j;
    double x2[stepCnt], f2[stepCnt];
    for (i = 0; i <= stepCnt; i++) {
        x2[i] = i * step;
        f2[i] = ln(x2[i]);
        printf("%lf\t%lf\n", x2[i], f2[i]);
    }
    double sum = 0;
    for (j = 1; j <= (stepCnt - 1); j++) {
        sum = sum + f2[j];
    }
    S = (step / 2) * (f2[0] + 2 * sum + f2[stepCnt]);
    printf("Метод трапеций.\n\tПлощадь криволинейной трапеции = %lf\n", S);


    step = (end - start) / (2 * stepCnt);
    double x3[2 * stepCnt], f3[2 * stepCnt];
    for (i = 0; i <= (2 * stepCnt); ++i) {
        x3[i] = start + i * step;
        f3[i] = ln(x3[i]);
        printf("%lf\t%lf\n", x3[i], f3[i]);
    }
    sum = 0;
    int cnt = 1;
    for (j = 0; j < stepCnt; j++) {
        sum = sum + f3[cnt];
        cnt += 2;
    }
    double sum2;
    sum2 = 0;
    cnt = 2;
    for (j = 0; j < (stepCnt - 1); j++) {
        sum2 = sum2 + f3[cnt];
        cnt += 2;
    }
    printf("%lf, %lf", sum, sum2);
    S = (step / 3) * (4 * sum + 2 * sum2 + f3[stepCnt * 2]);

    printf("Метод Симпсона.\n\tПлощадь криволинейной трапеции = %lf\n", S);
}

void euler() {
    double step;
    int start, end;
    printf("Задача 0. Метод Эйлера\n");
    printf("%s", "Найти частное решение дифференциального уравнения y' + 2y = x^2,\n"
            "соответствующее начальному условию y(0) = 1, методом Эйлера\n"
            "на отрезке[a,b] с шагом h. Построить таблицу приближённого решения.\n\n");
    printf("Введите a\n");
    scanf("%i", &start);
    printf("Введите b\n");
    scanf("%i", &end);
    printf("Введите шаг\n");
    scanf("%lf", &step);
    printf("Нужно найти и построить ломаную,\n"
                   "которая приближает график функции на промежутке [%i,%i]\n"
                   "Поскольку длина этого промежутка равна %i, а шаг составляет %lf,\n"
                   "то наша ломаная будет состоять из %lf отрезков\n", start, end, end - start, step,
           abs(end - start) / step);
    calc(step, start, end);
}

void calc(double step, int start, int end) {
    int temp = (int) (abs(end - start) / step), i;
    double x[temp], y[temp], hf[temp], f[temp];
    x[0] = 0;
    y[0] = 1;
    f[0] = pow(x[0], 2) - 2 * y[0];
    hf[0] = step * f[0];
    for (i = 1; i <= abs(end - start) / step + 1; ++i) {
        x[i] = x[i - 1] + step;
        y[i] = y[i - 1] + hf[i - 1];
        f[i] = fun(x[i], y[i]);
        hf[i] = step * f[i];
        printf("%lf \t %lf \t %lf \t %lf\n", x[i], y[i], f[i], hf[i]);
    }
}

double fun(double a, double b) {
    double i;
    i = pow(a, 2) - 2 * b;
    return i;
}

double ln(double a) {
    return 7 / (log(a) + 4.5);
}

