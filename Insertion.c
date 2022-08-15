#include<stdio.h>
#include<stdlib.h>
#include"Insertion.h"
long int cont_var = 0;
long int cont_troca = 0;
long int cont_comp = 0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertion(int*vector, int size)
{
    int i, j, atual;
    //comparando o valor de uma posicao com os antecessores
    for(i=1; i<size; i++){ 
        atual = i;

        if(vector[atual] != atual)cont_troca += 1;

        //Desloca os valores pra esquerda e insere:
        while(atual < vector[atual - 1])
        {
            swap(&vector[atual],&vector[atual - 1]);
            atual --;
        
            cont_comp += 1;
            
            if(atual == 0)break;
        }

        //if(vector[j] != atual)cont_troca += 1;

    cont_var += 1;
    }
}

int dados_arq(const int *vector, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("|%d|", vector[i]);
    }

    printf("\nquantidades de trocas: %ld\n", cont_troca);
    printf("quantidades d e varredura: %ld\n", cont_var);
    printf("quantidade de comparacoes: %ld\n", cont_comp);
}