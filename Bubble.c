#include"Bubble.h"
#include <stdlib.h>
#include <stdio.h>

long int cont_varredura = 0;
long int cont_trocas = 0;
long int cont_comp = 0;

void bubble(int *vector, int size)
{
   int i, j, aux=0, comp=0;
   for(i=0; i < size-1; i++)
   {
      cont_varredura+=1;
      for(j=0; j<size-i-1; j++)
      {
         cont_comp+=1;
         if(vector[j] > vector[j + 1])
         {
            aux = vector[j];
            vector[j] = vector[j + 1];
            vector[j + 1] = aux;
            cont_trocas+=1;
         }
      }

         if(vector[i] == vector[i-1])
         {
            cont_varredura-=1;
            break;
         }
     }
}

int print_arq(int size, double tempo, int *vector)
{
   FILE *file = fopen("Bubble_sort.txt", "a");
   if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

   fprintf(file, "\n\nDADOS DO VETOR **%d**",size);
   fprintf(file, "\nnumero de trocas %ld", cont_trocas);
   fprintf(file, "\nnumero de varedura do vetor: %ld", (cont_varredura));
   fprintf(file, "\nnumero de comparacoes: %ld", cont_comp);
   fprintf(file, "\no tempo de execucao foi de: %.4f", tempo);
   fprintf(file, "\n\n------------------------------\n");
   fclose(file);
}

