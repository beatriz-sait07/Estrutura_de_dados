#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"select.h"

int cont_troca = 0;
int cont_var = 0;
int cont_comp = 0;
void swap (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection(int vector[],int size)
{
    for(int i = 0; i < size; i++)
    {
        int menor = i;
        for(int j = i; j < size; j++)
        {
            if(vector[j] < vector[menor])
            {
                menor = j;
            }
            // pode ser progressão ??
            if(menor == j || menor != j)cont_comp += 1;
            //cont_comp += 1;
            
        }
        if(i != menor)
        {
            swap(&vector[i], &vector[menor]);
            cont_troca += 1;
        }
    
    cont_var += 1;
        
    }
}

int print_vector(const int *vector, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("|%d|", vector[i]);
    }
    printf("\n\nnumero de trocas %d", cont_troca);
    printf("\n\nnumero de varedura do vetor: %d", (cont_var - 1));
    printf("\n\nnumero de comparacoes: %d\n", cont_comp);
}