#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    char b[2];
    char symb = 'q';
    char *tmp = NULL;
    int i = 1;

    tmp = malloc(2 * sizeof(char));

    while (symb != ' ') {
        gets(&symb);
        if ((symb == 'e') || (symb == 'E') || (symb == 'u') || (symb == 'U') || (symb == 'o') || (symb == 'O') ||
            (symb == 'a') || (symb == 'A') || (symb == 'i') || (symb == 'I')) {
            sprintf(b, "%s", &symb);
            strcat(tmp, b);
            tmp = (char *)realloc(tmp, 1 + sizeof(char));
        }
    }

    printf("%s", tmp);
    return 0;

}
