#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *result;
    int i = 0, n;

    printf("сколько квадратов будет крч");
    scanf("%i", &n);
    result = (int *) malloc(n * sizeof(int));


    for (i = 0; i <= n; ++i) {
        result[i] = i * i;
        printf("%i\n", result[i]);
    }

    free(result);
    return 0;
}
