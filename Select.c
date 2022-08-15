#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Select.h"

long int cont_troca = 0;
long int cont_var = 0;
long int cont_comp = 0;
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

            cont_comp += 1;

            
        }
        if(i != menor)
        {
            swap(&vector[i], &vector[menor]);
            cont_troca += 1;
        }
    
    cont_var += 1;
        
    }
}

int salva_dados(int size, double tempo)
{
    FILE *file = fopen("Selection_sort.txt", "a");
    if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

    fprintf(file, "dados do vetor de %d",size);
    fprintf(file, "\nnumero de trocas %ld", cont_troca);
    fprintf(file, "\nnumero de varedura do vetor: %ld", (cont_var - 1));
    fprintf(file, "\nnumero de comparacoes: %ld", cont_comp);
    fprintf(file, "\no tempo de execucao foi de: %.2f", tempo);
    fprintf(file, "\n\n------------------------------\n");
}