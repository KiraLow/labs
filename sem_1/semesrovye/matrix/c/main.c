#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int choice = 1;
    int a, b, c, d;

    int choiceType;
    printf("Введите ширину первой матрицы \n");
    scanf("%d", &a);
    a -= 1;
    printf("Введите высоту первой матрицы \n");
    scanf("%d", &b);
    b -= 1;
    printf("Введите ширину второй матрицы \n");
    scanf("%d", &c);
    c -= 1;
    printf("Введите высоту второй матрицы \n");
    scanf("%d", &d);
    d -= 1;
    do {
        a += 1;
        b += 1;
        c += 1;
        d += 1;

            int matrix_one[a][b]; /* обьявляем массив первой матрицы */
            int matrix_two[c][d];

        int i, j; /* счетчик */

        clock_t time; /* найдем время выполнения программы */
        time = clock();

                for (i = 0; i < a; i++) {
                    for (j = 0; j < b; j++) {
                        matrix_one[i][j] = rand() % 100; /* считываем сначала столбца, потом строки */
                    }
                }
                for (i = 0; i < c; i++) {
                    for (j = 0; j < d; j++) {
                        matrix_two[i][j] = rand() % 100;
                    }
                }
                /* Вывод матриц на экран */
                printf("\nПервая матрица:\n");
                for (i = 0; i < a; i++) {
                    for (j = 0; j < b; j++) {
                        printf("%6i  ", matrix_one[i][j]);
                    }
                    printf("\n");
                }

                printf("\nВторая матрица:\n");
                for (i = 0; i < c; i++) {
                    for (j = 0; j < d; j++) {
                        printf("%6.0i", matrix_two[i][j]);
                    }
                    printf("\n");
                }

                /* Умножение  матриц */
                int matrix_mul[a][d];
                if (b == c) {
                    printf("\nУмножение матриц:\n");
                    for (i = 0; i < a; i++) {
                        for (j = 0; j < d; j++) {
                            int m;
                            matrix_mul[i][j] = 0;
                            for (m = 0; m < b; m++) {
                                matrix_mul[i][j] += (matrix_one[i][m] * matrix_two[m][j]);
                            }
                        }
                    }
                    for (i = 0; i < a; i++) {
                        for (j = 0; j < d; j++) {
                            printf("%i\t", matrix_mul[i][j]);
                        }
                        printf("\n");
                    }
                    time = clock() - time;
                    printf("%f", (double) time / CLOCKS_PER_SEC);
                } else {
                    printf("\nМатрицы не могут быть умножены.\n");
                }
        printf("Увеличим матрицы? :)");
        scanf("%i", &choice);
    } while (choice == 1);
    return 0;
}
