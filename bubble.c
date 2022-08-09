#include"bubble.h"
#include <stdlib.h>
#include <stdio.h>

int cont_varredura = 0;
int cont_trocas = 0;
int cont_comp = 0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vector[], int size)
{

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1; j++){

            if(vector[j] > vector[j+1]){

                swap(&vector[j], &vector[j+1]);
                cont_varredura = vector[j];
                if (cont_varredura == vector[j - 1]) break;
                cont_trocas += 1;
            }
            cont_comp += 1;
        }
        cont_varredura += 1;
    }
}


void print_arq(double tempo)
{
    FILE *file = fopen("dados bubble_sort.txt", "w");

    if(file == NULL)printf("nao foi possivel criar um arquivo!");

    fprintf(file, "o vetor foi analisado: %d\n", (cont_varredura - 1));
    fprintf(file,"nocorreu: %d trocas dentro do vetor ate ele se organizar\n", cont_trocas);
    fprintf(file,"quantidade de comparacoes: %d\n", cont_comp);
    fprintf(file, "o tempo gasto eh de: %f", tempo);
    fclose(file);
}