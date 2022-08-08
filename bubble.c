#include"bubble.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int *cont_varrecao = 0;

void swap (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble (int vector [], int size)
{
    for(int i=0; i < size - 1; i++)
    {
        for(int j=0; i < size - 1; j++)
        {
            if(vector[j] > vector[j + 1])
            {
                swap(&vector[j], &vector[j + 1]);
            }
        }
        int cont = 0;
        cont += 1;
    }
}

void quant_var(int *vector, int size)
{
    bubble(vector,size);
    printf("%d")
}

void tempo(int vet[], int size)
{

}


void print_novo_vetor(int *vector, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("|%d|", vector[i]);
    }
}
