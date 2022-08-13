#include "bubble.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VET1 100000
#define VET2 500000
#define VET3 1000000

int main (int argc, char const *argv[])
{
    double tempo_execucao = 0.0;
    clock_t begin = clock();
    
    /*int vector[VET1];
    for(int i = 0; i < VET1; i++)
    {
        vector[i] = rand() % VET1;
    }
    print_novo_vetor(vector, VET1);
    bubble(vector, VET1);
    printf("\n\ndados do vetor 100k foram armazenados!\n ABRA O ARQUIVO: dados bubble_sort.txt");

    printf("\n\n\niniciando analise do vetor de 500K");
    */
    int vetor[VET2];
    for (int j = 0; j < VET2; j++)
    {
        vetor[j] = rand() % VET2;
    }
    //print_novo_vetor(vetor, VET2);
    bubble(vetor, VET2);
    printf("\n\ndados -do vetor de 500k foram armazenados!\nABRA O ARQUIVO: dados bubble_sort.txt");
    printf("\n\n");

    clock_t end = clock();
    tempo_execucao += (double)(end - begin) /  CLOCKS_PER_SEC;
    print_arq(tempo_execucao);
    return 0;
}