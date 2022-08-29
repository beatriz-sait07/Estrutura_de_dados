#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Bubble.h"

void tempo(int *vector, int size);

int main()
{
    int indc = 500;
    int * vector;

    srand(time(NULL));

    vector = (int*)malloc( indc * sizeof(int));
    if (vector == NULL)
    {
        printf("erro de alocacao!\n");
        exit(1);
    }
    tempo(vector,indc);

    indc = 1000;
    vector = (int*)realloc( vector, indc * sizeof(int));
    tempo(vector,indc);

    indc = 10000;
    vector = (int*)realloc( vector, indc * sizeof(int));
    tempo(vector,indc);

    indc = 500000;
    vector = (int*)realloc( vector, indc * sizeof(int));
    tempo(vector,indc);

    indc = 1000000;
    vector = (int*)realloc( vector, indc * sizeof(int));
    tempo(vector,indc);

    free(vector);
    return 0;
}

void tempo(int *vector, int size)
{
    double tempo_execucao = 0.0;

    clock_t  begin = clock();

    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        vector[i] = rand()%size;
    }
    bubble(vector, size);

    clock_t end = clock();
    tempo_execucao += (double)(end - begin) / CLOCKS_PER_SEC;
    print_arq(size,tempo_execucao,vector);
}