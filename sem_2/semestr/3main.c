#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
const int N=4;
//нахождение детерминанта
double Det(int G, double M[4][4])
{
 if (G == 1)
 return M[0][0];
 else {
     double M1[4][4];
     int i, x, X, Y;
     double Res = 0;
     for (i = 0; i < G; i++) {
         for (Y = 1; Y < G; Y++) {
             x = 0;
             for (X = 0; X < G; X++)
             if (X != i)
             M1[Y-1][x++] = M[Y][X];
         }
         if (i % 2 == 0)
         Res += M[0][i] * Det(G - 1, M1);
         else
         Res -= M[0][i] * Det(G - 1, M1);
     }
     return Res;
 }
}

//Вывод на экран матрицы
printMas(double **V)
{
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j == 0) printf("\n");
            else printf("\t");
            printf("%7.2f", V[i][j]);
        }
    }
    printf("\n");
}

//создание матрицы и нахождение  детерминанта
double substation(int k, double **M, double **A, double *B)
{
    int i,j;
    for (i=0; i<N; i++) {
        for (j = 0; j < N; j++) {
            M[i][j] = A[i][j];
        }
    }
    for (i=0; i<N; i++){
        M[i][k] = B[i];
    }
     double Opr = Det(4, M);
     return Opr;
}

 main() {
     SetConsoleOutputCP(CP_UTF8);
     SetConsoleCP(CP_UTF8);
     int i, j, k;
     double A[4][4];
     for (i = 0; i < N; i++) {
         for (j = 0; j < N; j++) {
             A[i][j] = rand() % 10;
         }
     }

     double B[N];
     printf("Искомый столбец\n");
     for (k = 0; k < N; ++k) {
         B[k] = rand() % 10;
         printf("%lf\t", B[k]);
     }

//Вывод на экран исходной матрицы
     printf("\nИсходная матрица");
     printf(A);

//------Нахождение определителя исходной матрицы---------------------------
     printf("\nДетерминанты\n");
     double Op = Det(4, A);
     printf("Детерминант = %7.2f\n", Op);
//-------------------------------------------------------------------------

//***********************************
     //действия над новыми матрицами
     double M1[N][N];
     double Op1 = substation(0, M1, A, B);
     printf("Детерминант 2 = %7.2f\n", Op1);

     double M2[N][N];
     double Op2 = substation(1, M2, A, B);
     printf("Детерминант 3 = %7.2f\n", Op2);

     double M3[N][N];
     double Op3 = substation(2, M3, A, B);
     printf("Детерминант 4 = %7.2f\n", Op3);

     double M4[N][N];
     double Op4 = substation(3, M4, A, B);
     printf("Determinant 4 = %7.2f\n", Op4);


// Вывод решения
     printf("\nРешение\n");
     double x1 = Op1 / Op;
     printf("X1 = %7.2f\n", x1);
     double x2 = Op2 / Op;
     printf("X2 = %7.2f\n", x2);
     double x3 = Op3 / Op;
     printf("X3 = %7.2f\n", x3);
     double x4 = Op4 / Op;
     printf("X4 = %7.2f\n", x4);


     int n = 4;
     double defaultMas[20][20], c, x[10], copyMas[20][20];
     for (i = 1; i <= n; i++) {
         printf("\n");
         for (j = 1; j <= (n + 1); j++) {
             defaultMas[i][j] = rand() % 10;
             printf("%.2lf\t", defaultMas[i][j]);
         }
         printf("\n");
     }

     for (j = 1; j <= n; j++) {
         for (i = 1; i <= n; i++) {
             if (i != j) {
                 c = defaultMas[i][j] / defaultMas[j][j];
                 for (k = 1; k <= n + 1; k++) {
                     defaultMas[i][k] = defaultMas[i][k] - c * defaultMas[j][k];
                 }
             }
         }
     }
     printf("\nРешение:\n");
     for (i = 1; i <= n; i++) {
         x[i] = defaultMas[i][n + 1] / defaultMas[i][i];
         printf("x%d = %f\n", i, x[i]);
     }
 }
