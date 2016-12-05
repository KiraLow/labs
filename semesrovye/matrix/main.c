#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{

    int a,b,c,d;

    printf("Введите ширину первой матрицы \n");
    scanf("%d",&a);
    printf("Введите высоту первой матрицы \n");
    scanf("%d",&b);
    printf("Введите ширину второй матрицы \n");
    scanf("%d",&c);
    printf("Введите высоту второй матрицы \n");
    scanf("%d",&d);

    int matrix_one[a][b]; /* обьявляем массив первой матрицы */
    int matrix_two[c][d]; /* обьявляет массив второй матрицы */
    int i,j; /* счетчик */

    clock_t time; /* найдем время выполнения программы */
    time = clock();

/* Запись в двумерные массивы */

    for (i = 0; i < a; i++) {
        printf("Введите строку #%d\n", i + 1);
        for(j = 0; j < b; j++) {
            scanf("%2i", &matrix_one[i][j]); /* считываем сначала столбца, потом строки */
        }
    }
    for(i = 0; i < c; i++){
        printf("Введите строку #%d\n",i+1);
        for(j = 0; j < d; j++){
            scanf("%2i",&matrix_two[i][j]);
        }
    }
    /* Вывод матриц на экран */
    printf("\nПервая матрица:\n");
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            printf("%6i  ",matrix_one[i][j]);
        }
        printf("\n");
    }

    printf("\nВторая матрица:\n");
    for(i = 0; i < c; i++){
        for(j = 0; j < d; j++){
        printf("%6.0i",matrix_two[i][j]);
        }
        printf("\n");
    }

    /* Умножение  матриц */
    int matrix_mul[a][d];
    if (b==c){
        printf("\nУмножение матриц:\n");
            for(i = 0; i < a; i++){
                for(j = 0; j < d; j++){
                    int m;
                    matrix_mul[i][j] = 0;
                        for(m = 0; m < b; m++){
                            matrix_mul[i][j] += (matrix_one[i][m]*matrix_two[m][j]);
                        }
                }
            }
            for(i = 0; i < a; i++){
                for(j = 0; j < d; j++){
                    printf("%6.0i",matrix_mul[i][j]);
                }
                printf("\n");
            }
        time = clock() - time;
        printf("%f", (double)time/CLOCKS_PER_SEC); //время выполнения
    }
    else{
        printf("\nМатрицы не могут быть умножены.\n");
    }
    return 0;
}
