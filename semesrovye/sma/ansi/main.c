#include <stdio.h>
#include <stdlib.h>

int main() {
    int mas[10];
    int i, j, l;
    int dot[12];
    for(i = 0; i < 10; i++) {
        mas[i] = rand() % 9 + 1;
    }
    for (j = 0; j < 10; j++) {
        printf("%i", mas[j]);
    }
    printf("\n");
    for (l = 0;l < 10; l++) {
        if (l == 0) {
            dot[l] = mas[l];
            printf("%i", dot[l]);
        } else {
            dot[l] = (mas[l - 1] + mas[l] + mas[l+1]) / 3;
            printf("%i", dot[l]);
        }
    }
    return 0;
}