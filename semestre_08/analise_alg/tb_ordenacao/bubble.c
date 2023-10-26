#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *vetor, int tamanho){
    int i, aux;
    if(tamanho > 1){
        for(i = 0; i < tamanho - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
        bubble(vetor, tamanho - 1);
    }
}

void tempo_bs_rec(int *vector, int size)
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
    printf("\nTempo de execução do BubbleSort Recursivo: %.6f segundos\n", tempo_execucao);
}

void bubble2(int *vetor, int tamanho){
    int i, j, aux;
    for(i = 0; i < tamanho - 1; i++){ // 2 + (n-1)*n
        for(j = 0; j < tamanho - 1; j++){ // 2 + ((n-1)n-1)*n
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void tempo_bs(int *vector, int size)
{
    double tempo_execucao = 0.0;

    clock_t  begin = clock();

    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        vector[i] = rand()%size;
    }
    bubble2(vector, size);

    clock_t end = clock();
    tempo_execucao += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTempo de execução do BubbleSort Iterativo: %.6f segundos\n", tempo_execucao);
}

int main(){
    int tam = 90000;

    int *vetor = (int*) malloc(tam * sizeof(int));


    srand(time(NULL));

    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 10000;
    }

    tempo_bs(vetor, tam);

    tempo_bs_rec(vetor, tam);

    return 0;
}