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

            if(menor == j || menor != j)cont_comp += 1;

            
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
    FILE *file = fopen("dados_selection_sort.txt", "a");
    if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

    fprintf(file, "dados do vetor de %d",size);
    fprintf(file, "\nnumero de trocas %d", cont_troca);
    fprintf(file, "\nnumero de varedura do vetor: %d", (cont_var - 1));
    fprintf(file, "\nnumero de comparacoes: %d", cont_comp);
    fprintf(file, "\no tempo de execucao foi de: %.2f", tempo);
    fprintf(file, "\n\n------------------------------\n");
}