#include"bubble.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int cont_varredura = 0;
int cont_trocas = 0;
int cont_comp = 0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vector[], int size)
{

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1; j++){

            if(vector[j] > vector[j+1]){
                swap(&vector[j], &vector[j+1]);
                cont_varredura = vector[j];
                if (cont_varredura == vector[j - 1]) break;
                cont_trocas += 1;
            }
        }
        cont_varredura += 1;
    }
}


int print_novo_vetor(const int *vector, int size)
{
    for(int i=0; i<size; i++){
        printf("|%d", vector[i]);
    }
    printf("\no vetor foi analisado: %d\n", cont_varredura);
    printf("nocorreu: %d trocas dentro do vetor ate ele se organizar\n", cont_trocas);
    printf("quantidade de comparacoes: %d\n", cont_comp);
}
