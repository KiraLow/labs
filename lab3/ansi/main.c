#include <stdio.h>
#include <math.h>


int main()
{
    char r;
    double G,F,Y,a,x,x2,run,y1,y2,step;
    double razn_rez, razn;
    const double pi=3.14;
    double start_f;
    run=1;
    int i;
    do {

        printf("Введите первую границу изменения x: \n");
        scanf("%lf", &x);

        printf("Введите вторую границу изменения x: \n");
        scanf("%lf", &x2);

        printf("Введите a: \n");
        scanf("%lf", &a);

        printf("Введите шаг: \n");
        scanf("%lf", &step);

        printf("Введите букву выражения, которое xотите вычислить - G,F,Y) \n");
        scanf("%s", &r);

        printf("Введите разницу между функциями) \n");
        scanf("%lf", &razn);

           switch (r) {
            case 'G':
                for (x_mod=x; x_mod<=x2; x_mod+=step) {
                    if (((4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod))>=0.0001) || ((4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod))<=-0.0001)) {
                        G = -(8 * (12 * (a * a) + 68 * a * x_mod+ 63 * (x_mod * x_mod)))/(4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod));
                        printf("%lf\n", G);
                    }
                    razn_rez = -(8 * (12 * (a * a) + 68 * a * x_mod+ 63 * (x_mod * x_mod)))/(4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod));
                    if ((razn_rez-G)>razn){
                        step /=2;
                    }
                }
                break;

                case 'F':
                    for(i = 0; i < start_f; ++i) {
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
                    for(i = 0; i < start_f; ++i) {
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
