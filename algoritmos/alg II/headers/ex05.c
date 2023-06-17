#include <stdio.h>
#include <stdlib.h>

using namespace std;

int preencher(int* vet, int tam, int n)
{
    for(int i = 0; i < tam; i++){
        vet[n];
    }

    return 0;
}

int main (){
    int ar;
    int *array = &ar;

    int vetor[3];
    int valor;

    printf("qual o tamanho do seu vetor: ");
    scanf("%d", &valor);

    printf("digite os valores para o array: ");
    for(int i = 0; i < valor; i++){
        scanf("%d", &ar);
        vetor[i] = ar;
    }

    

    preencher(vetor, valor, ar);

    printf("\n-----------------------------\n");

    for(int i=0; i < valor; i++){
        printf("vetor[%d] = [%d]\n", i, *(vetor + i));
    }

    return 0;
}
