#include <stdio.h>
#include <math.h>

int main()
{
    char r;
    double G,F,Y,a,x,run,y1,y2,step;
    const double pi=3.14;
    double start_f, end_f;
    run=1;
    do {

        printf("Введите x: \n");
        scanf("%lf", &x);

        printf("Введите a: \n");
        scanf("%lf", &a);

        printf("Введите,сколько значений x хотим: \n");
        scanf("%lf", &start_f);

        printf("Введите шаг: \n");
        scanf("%lf", &step);
            printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
            scanf("%s", &r);


            switch (r) {
                case 'G':
                    for (int i = 0; i < start_f; ++i) {
                        y1 = -(8 * (12 * (a * a) + 68 * a * x + 63 * (x * x)));
                        y2 = (4 * (a * a) + a * x - 5 * (x * x));
                        if (y2 == 0.0) {
                            printf("На ноль делить нельзя");
                            return 0;
                        }
                        else {
                            G = y1 / y2;
                            printf("G = %lf \n", G);
                            FILE *file;
                            file = fopen("file_G.txt", "ab+");
                            fprintf(file, "%lf \n", G);
                            x = x + step;
                        }
                    }
                    break;

                case 'F':
                    while (start_f < end_f) {
                        double f_1, f_2;
                        f_1 = (sin(pi * (40 * (a * a) - 61 * a * x + 7 * (x * x))));
                        f_2 = (pi * (40 * (a * a) - 61 * a * x + 7 * (x * x)));
                        if (f_2 == 0.0) {
                            printf("На ноль делить нельзя");
                            return 0;
                        }
                        else {
                            F = f_1 / f_2;
                            printf("F = %lf \n", F);
                            FILE *file;
                            file = fopen("file_F.txt", "ab+");
                            fprintf(file, "%lf \n", F);
                            x = x + step;
                            start_f = start_f + 1;
                        }
                    }

                    break;

                case 'Y':
                    while (start_f < end_f) {
                        Y = -7 * (a * a) + 40 * a * x + 63 * (x * x) + 1;
                        printf("Y = %lf \n", Y);
                        FILE *file;
                        file = fopen("file_Y.txt", "ab+");
                        fprintf(file, "%lf \n", Y);
                        x = x + step;
                        start_f = start_f + 1;
                    }
                    break;
            }

        printf("Вычислим еще раз? (1-да,2-нет) \n");
        scanf("%lf", &run);

    }
    while (run==1);

    return 0;
}