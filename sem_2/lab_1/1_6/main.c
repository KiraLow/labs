#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    char symb = 'q';
    char *tmp = NULL, *b = NULL;
    int i = 1;

    tmp = malloc(2 * sizeof(char));
    b = malloc(sizeof(char));

    while (symb != 'w') {
        scanf("%s", &symb);
        getchar();
        if ((symb == 'e') || (symb == 'E') || (symb == 'u') || (symb == 'U') || (symb == 'o') || (symb == 'O') ||
            (symb == 'a') || (symb == 'A') || (symb == 'i') || (symb == 'I')) {
            sprintf(b, "%s", &symb);
            strcat(tmp, b);
            tmp = realloc(tmp, 1 + sizeof(char));
        }
    }
    return 0;

}