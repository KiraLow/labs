#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
int main() {
    char symb = 'q';
    char *tmp, *b;
    int i = 1;
    tmp = malloc(2 * sizeof(char));
    b = malloc(sizeof(char));
    *tmp = NULL;
    *b = NULL;
    while (symb != ' ') {
        gets(&symb);
        if ((symb == 'e') || (symb == 'E') || (symb == 'u') || (symb == 'U') || (symb == 'o') || (symb == 'O') ||
            (symb == 'a') || (symb == 'A') || (symb == 'i') || (symb == 'I')) {
            sprintf(b, "%s", &symb);
            strcat(tmp, b);
            tmp = realloc(tmp, 1 + sizeof(char));
        }
    }
    printf("%s", tmp);
    return 0;
}
