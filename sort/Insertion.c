#include<stdio.h>
#include<stdlib.h>
#include"Insertion.h"
long int cont_var = 0;
long int cont_troca = 0;
long int cont_comp = 0;

void insertion(int *vector, int size)
{
    cont_var = 0, cont_comp =0, cont_troca =0;
    int i =0, j =0, atual=0;
    //comparando o valor de uma posicao com os antecessores
    for(i=1; i<size; i++)
    {
        atual=vector[i];
        for(j=i; (j>0)&&(atual<vector[j-1]); j--)
        {
            cont_comp += 1;
            vector[j] = vector[j-1];
        }
        if(vector[j] != atual)cont_troca+= 1;
        vector[j] = atual;
        cont_var += 1;
    }
}

void salva_dados(const int *vector, int size, double tempo)
{
    FILE *file = fopen("Insertion_sort.txt", "a");
    if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

    fprintf(file, "\ndados do vetor de %d",size);
    fprintf(file, "\nnumero de trocas %ld", cont_troca);
    fprintf(file, "\nnumero de varedura do vetor: %ld", cont_var);
    fprintf(file, "\nnumero de comparacoes: %ld", cont_comp);
    fprintf(file, "\no tempo de execucao foi de: %.4f", tempo);
    fprintf(file, "\n\n------------------------------\n");
    fclose(file);
}
