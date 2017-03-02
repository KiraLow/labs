#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    char *result;
    result = NULL;
    char name;
    int i, change = 0, counter;
    char *b = NULL;

    result = (char *) malloc(4 * sizeof(char));
    b = malloc(sizeof(char));

    while (change == 0) {
        printf("Введите имя");
        scanf("%s", &name);
        sprintf(b, "%s", &name);
        strcat(result, b);
        printf("Продолжим ввод? 0 - да");
        scanf("%i", &change);
        result = (char *) realloc(result, 4 + sizeof(result));
    }
    printf("%s", result);
}