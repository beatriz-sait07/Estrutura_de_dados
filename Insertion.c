#include<stdio.h>
#include<stdlib.h>
#include"Insertion.h"
long int cont_var = 0;
long int cont_troca = 0;
long int cont_comp = 0;

void insertion(int*vector, int size)
{
    int i =0, j =0, atual=0;
    //comparando o valor de uma posicao com os antecessores
    for(i=1; i<size; i++){ 
        atual = vector[i];
        j = i - 1;

        //Desloca os valores pra esquerda e insere:
        while(j >= 0 && atual < vector[j])
        {
            cont_comp += 1;
            vector[j + 1] = vector[j];
            j--;

            if(j == 0)break;
        }
        if(vector[j] != atual)cont_troca += 1;

        vector[j + 1] = atual;
    cont_var += 1;
    }
}

int salva_dados(int size, double tempo, int *vector)
{
    FILE *file = fopen("Insertion_sort.txt", "a");
    if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

    for(int i =0; i < size; i++)
    {
        fprintf(file,"|%d|", vector[i]);
    }

    fprintf(file, "dados do vetor de %d",size);
    fprintf(file, "\nnumero de trocas %ld", cont_troca);
    fprintf(file, "\nnumero de varedura do vetor: %ld", cont_var);
    fprintf(file, "\nnumero de comparacoes: %ld", cont_comp);
    fprintf(file, "\no tempo de execucao foi de: %.2f", tempo);
    fprintf(file, "\n\n------------------------------\n");
    fclose(file);
}
