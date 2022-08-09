#include<stdio.h>
#include"select.h"
#define TAM 8

void swap (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


void selection(int vector[])
{
    for(int i = 0; i < TAM; i++)
    {
        int menor = i;
        for(int j = i; j < TAM; j++)
        {
            if(vector[j] < vector[menor])
            {
                menor = j;
            }
        }
        swap(&vector[i], &vector[menor]);
    }
}

int print_vector(const int *vector)
{
    for(int i = 0; i < TAM; i++)
    {
        printf("\n");
        printf("|%d|", vector[i]);
        printf("\n");
    }
}