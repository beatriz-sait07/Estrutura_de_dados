#include"fila_est.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct _static_queue{
    int *data;
    int size;
    long capacity;
    long begin;
    long end;

}StaticQueue;

StaticQueue *create_StaticQueue(long capacity)
{
    StaticQueue *Q = (StaticQueue*)calloc(1, sizeof(StaticQueue));
    Q->data = (int *)calloc(capacity, sizeof(int)); // Alocando o vetor
    Q->capacity = capacity;
    Q->begin = 0;
    Q->end = 0;
    Q->size = 0;

    return Q;
}

void destroy_StaticQueue(StaticQueue **Q_Ref)
{
    StaticQueue *Q = *Q_Ref;
    free(Q->data);
    free(Q);

    *Q_Ref = NULL;
}

bool is_empty_StaticQueue(const StaticQueue *Q)
{
    return Q->size == 0;
}
bool is_full_StaticQueue(const StaticQueue *Q)
{
    return Q->size == Q->capacity;
}
long size_StaticQueue(const StaticQueue *Q)
{
    return Q->size;
}

int peek_StaticQueue(const StaticQueue *Q)
{
    if(is_empty_StaticQueue(Q)){
        fprintf(stderr, "Erro em peek()\n");
        fprintf(stderr, "A Fila esta vazia\n");
        exit(EXIT_FAILURE);
    }
    return Q->data[Q->begin];
}

void enqueue_StaticQueue(StaticQueue *Q, int info)
{
    if(is_full_StaticQueue(Q)){
        fprintf(stderr, "Erro em enqueue()\n");
        fprintf(stderr, "A Fila esta cheia\n");
        exit(EXIT_FAILURE);
    }
    Q->data[Q->end] = info;
    Q->end = (Q->end + 1) % Q->capacity; // Fila circular
    Q->size++;
}

int dequeue_StaticQueue(StaticQueue *Q)
{
    if(is_empty_StaticQueue(Q)){
        fprintf(stderr, "Erro em dequeue()\n");
        fprintf(stderr, "A Fila esta vazia\n");
        exit(EXIT_FAILURE);
    }
    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return val;
}

void print_StaticQueue(const StaticQueue *Q)
{
    long i, j; // J controla a quantidade de iteracoes e o I fica responsavel pela impressao
    for(j = 0, i = Q->begin; 
        j < Q->size; 
        j++, i = (i + 1) % Q->capacity){
        printf("| %d ", Q->data[i]);
    }
    printf("\n");
    printf("Capacity: %ld\n", Q->capacity);
    printf("Size: %ld\n", Q->size);
    printf("Begin: %ld\n", Q->begin);
    printf("End: %ld\n", Q->end);
}