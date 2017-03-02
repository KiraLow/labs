#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {

    struct data {
        char name[15];
        double value;
    };

    int n = 1;
    int i, change = 0, counter = 0;

    struct data *client;
    client = (struct data*)malloc(sizeof(struct data) * n);

    /* char *b = NULL;
    char *resultName = NULL;

    resultName = malloc(5 * sizeof(char));*/

    while (change != 3) {
        printf("Введите имя");
        scanf("%s", client[counter].name);
        /* sprintf(b, "%s %s", client[counter].name, " "); */
        printf("Введите стоимость");
        scanf("%lf", &client[counter].value);

        /* strcat(resultName, b); */
        printf("Продолжим ввод? 0 - да");
        scanf("%i", &change);
        counter++;
        client = realloc(client, sizeof(struct data) * (counter+1));
        /* resultName = (char *) realloc(resultName, 5 + sizeof(resultName)); */
    }
    int j;
    /* printf("%s", resultName); */
    for (j = 0; j < counter; ++j) {
        printf("%s\t", client[j].name);
        printf("%lf\t\n", client[j].value);
    }
free(client);
}