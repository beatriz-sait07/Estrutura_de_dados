#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Merge.h"
//criando o vetor e alocando dinamicamente
typedef struct dados_vetor
{
    int capac, size,*array, *troca;
}Dados;

bool _isFull(const Dados *vector)
{
    return vector->size == vector->capac;
}
Dados *create(int tam)
{
    Dados *arr = (Dados *)calloc(1, sizeof(Dados));
    arr->capac = tam; //quantidade de array
    arr->size = 0;
    arr->array = (int*)calloc(arr->capac, sizeof(int));

return arr;
}

int size(const Dados *vector)//retorna o tamanho do vetor
{
    return vector->size;
}

int at(const Dados *vector,int pos)//retorna o valor com o tratamento de erros dentro
{
    if(pos<0 || pos>=vector->size)
    {
        fprintf(stderr, "posicao invalida!\n");
        fprintf(stderr, "index [%d] fora do limite permitido",vector->array[pos]);
        exit(EXIT_FAILURE);
    }
return vector->array[pos];
}


int get(const Dados *vector, int indc)
{
    return vector->array[indc];
}

void adicionar(Dados *vector, int valor)
{
    if(_isFull(vector))
    {
        fprintf(stderr, "erro ao adicionar, vetor cheio!\n");
    }
    vector->array[vector->size++] = valor;
}
int set(Dados *vector, int index, int novo_valor)
{
    if(index<0 || index>=vector->size)
    {
        fprintf(stderr, "posicao indisponivel!\n");
        exit(EXIT_FAILURE);
    }
    vector->array[index] = vector->troca[novo_valor];
    return novo_valor;
}

void destroy(Dados **busc_vector)
{
    Dados *arr = *busc_vector;
    free(arr->array); //desaloca elemento/elemento
    free(arr); //desaloca o vetor inteiro
    *busc_vector = NULL;
}

void merge(Dados *vector, int inicio, int meio, int fim)
{
    //pivo
    int i, j, k;
    //inicio de cada vetor
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
 
    //subvetores
    int esq[n1], dir[n2];
 
    
    for (i = 0; i < n1; i++)esq[i] = at(vector, inicio + 1);
    for (j = 0; j < n2; j++)dir[j] = at(vector,meio + 1 + j);
 
    i = 0, j = 0; 
    //pivo vetor principal
    k = inicio; 

    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            //vector[k] = at(esq[n1],i);
            set(vector,k,esq[i]);
            i++;
        }
        else {
            //vector[k] = at(dir[n2],j);
            set(vector,k,dir[j]);
            j++;
        }
        k++;
    }
 
    //sobra
    while (i < n1) {
        //vector[k] = at(esq[n1],i);
        set(vector,k,esq[i]);
        i++;
        k++;
    }

    while (j < n2) {
        //vector[k] = at(dir[n2],j);
        set(vector,k,dir[j]);
        j++;
        k++;
    }
}

void mergesort(Dados *vector, int inicio, int fim)
{
    if (inicio < fim) {
        //calcula o meio do vetor
        int meio = inicio + (fim - inicio) / 2;
        //divide o vetor
        mergesort(vector, inicio, meio);
        mergesort(vector, meio + 1, fim);
        //ordena apos finalizar a divisão
        merge(vector, inicio, meio, fim);
    }
}

void salva_dados(const Dados *vector)
{
    for(int i=0; i<(vector->size); i++)
    {
        printf("|%d|",vector->array[i]);
    }
}