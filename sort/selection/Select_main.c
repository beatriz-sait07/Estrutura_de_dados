#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Select.h"

void tempo(int *vector, int size);

int main()
{
    long int T = 500;
    int * vector;

    vector = (int*)malloc( T * sizeof(int));
    if (vector == NULL)
    {
        printf("erro de alocacao!\n");
        exit(1);
    }
    tempo(vector,T);

    T = 1000;
    vector = (int*)realloc( vector, T * sizeof(int));
    tempo(vector,T);

    T = 10000;
    vector = (int*)realloc( vector, T * sizeof(int));
    tempo(vector,T);

    T = 500000;
    vector = (int*)realloc( vector, T * sizeof(int));
    tempo(vector,T);

    T = 1000000;
    vector = (int*)realloc( vector, T * sizeof(int));
    tempo(vector,T);

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
    selection(vector, size);

    clock_t end = clock();
    tempo_execucao += (double)(end - begin) / CLOCKS_PER_SEC;
    salva_dados(size, tempo_execucao, vector);
}