#include<stdio.h>
#include<stdlib.h>
#include"insertion.h"

void insertion(int*vector, int size)
{
    int i, j, atual;
    //comparando o valor de uma posicao com os antecessores
    for(i=1; i<size; i++){ 
        //Desloca os valores pra esquerda e insere:
        atual = vector[i];
        for(j=i; (j>0) && (atual < vector[j-1]); j--){
            vector[j] = vector[j-1];
        }
        vector[j] = atual;

    }
}

int dados_arq(const int *vector, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("|%d|", vector[i]);
    }
}