#include"Bubble.h"
#include <stdlib.h>
#include <stdio.h>

long int cont_varredura = 0;
long int cont_trocas = 0;
long int cont_comp = 0;

/*

verificar as contagens!!!!

*/
void bubble(int *vector, int size)
{
    int i, j, aux=0;
    for (i=0; i < size; i++) {
       for (j=0; j < size; j++) {
         if (vector[j] > vector[j + 1]) {
           aux = vector[j];
           vector[j] = vector[j + 1];
           vector[j + 1] = aux;
           if(aux != aux-1)cont_trocas += 1;
           if(vector[j] == vector[j-1])break;
         }
         cont_comp += 1;
       }
       cont_varredura += 1;
     }
}

int print_arq(int size, double tempo, int *vector)
{
    FILE *file = fopen("Bubble_sort.txt", "a");
    if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

    for(int i= 0; i < size; i++)
    {
        fprintf(file, "|%d|", vector[i]);
    }

    fprintf(file, "\n\ndados do vetor de %d",size);
    fprintf(file, "\nnumero de trocas %ld", cont_trocas);
    fprintf(file, "\nnumero de varedura do vetor: %ld", (cont_varredura - 1));
    fprintf(file, "\nnumero de comparacoes: %ld", cont_comp);
    fprintf(file, "\no tempo de execucao foi de: %.4f", tempo);
    fprintf(file, "\n\n------------------------------\n");
    fclose(file);
}

