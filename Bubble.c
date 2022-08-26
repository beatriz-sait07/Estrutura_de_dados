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
    int i, j, aux=0, comp=0, ant=0;
    for (i=0; i < size; i++) {
       for (j=0; j < size; j++) {
         if (vector[j] > vector[j + 1]) {
            aux = vector[j];
            ant = aux;
            vector[j] = vector[j + 1];
            vector[j + 1] = aux;
            printf("|%d|->|%d|\n",vector[j],vector[j+1]);
         }
            if(ant>vector[j])cont_trocas += 1;
          cont_comp += 1;
          printf("+ comparaçao\n");
       }
       if(vector[i] == vector[i-1])
          {
            printf("parou!\n");
            break;
          }
       cont_varredura += 1;
       printf("+ varredura\n");
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

