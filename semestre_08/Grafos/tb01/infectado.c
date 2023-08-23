#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "infectado.h"

void leitura_arq(struct list **l){
    FILE *file = fopen("infectado.csv", "r");
    char aux = fgetc(file);

    while(aux != EOF){
        printf("%c", aux);
        aux = fgetc(file);
    }
}

int main (){

        struct list **lista = (struct list **) malloc(8 * sizeof(struct list *));

    // Verifique se a alocação de memória foi bem-sucedida
    if (lista == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    leitura_arq(lista);

    free(lista);

    return 0;
}