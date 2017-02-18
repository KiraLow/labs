#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int *i, *result, *n;
    i = NULL;
    result= NULL;
    n = NULL;

    n = (int *) malloc(sizeof(int));

    scanf("%i", n);

    i = (int *) malloc(sizeof(int));
    result = (int *) malloc(*n * sizeof(int));

    for ((*i) = 0; (*i) <= (*n); ++(*i)) {
        result[*i] = (*i) * (*i);
        printf("%i\t|\t%i\n", *i, result[*i]);
    }

};