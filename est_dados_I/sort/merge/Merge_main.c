#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Merge.h"

void tempo(Dados *vector, int size);

int main()
{
    int indc = 500;
    Dados *vector;

    srand(time(NULL));

    vector = (Dados*)malloc( indc * sizeof(int));
    if (vector == NULL)
    {
        printf("erro de alocacao!\n");
        exit(1);
    }
    tempo(vector,indc);

    indc = 1000;
    vector = (int*)realloc(vector, indc * sizeof(int));
    tempo(vector,indc);

    indc = 10000;
    vector = (int*)realloc(vector, indc * sizeof(int));
    tempo(vector,indc);

    indc = 500000;
    vector = (int*)realloc(vector, indc * sizeof(int));
    tempo(vector,indc);

    indc = 1000000;
    vector = (int*)realloc(vector, indc * sizeof(int));
    tempo(vector,indc);
    free(vector);

    printf("PROGRAMA FINALIZADO!\nVERIFIQUE NO ARQUIVO: 'bubble_sort.txt'\n\n");
    return 0;
}

void tempo(Dados *vector, int size)
{
    double tempo_execucao = 0.0;

    clock_t  begin = clock();

    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        int vetor = rand()%size;
        adicionar(vector, vetor);
    }
    mergesort(vector,0, size);

    clock_t end = clock();
    tempo_execucao += (double)(end - begin) / CLOCKS_PER_SEC;
    salva_dados(size,tempo_execucao);
}

/*              MERGE_SORT

está dando erro ao adicionar valores no vetor

*/
