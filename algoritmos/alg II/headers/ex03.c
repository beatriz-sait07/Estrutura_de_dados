// varrer vetor (aritmética de ponteiro)

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int preencher(int* vet, int tam, int n)
{
    for(int i = 0; i < 3; i++){
        vet[n];
    }

    return 0;
}

int main (){
    int ar;
    int *array = &ar;

    int vetor[3];

    printf("digite os valores para o array: ");
    for(int i = 0; i < 3; i++){
        scanf("%d", &ar);
        vetor[i] = ar;
    }

    preencher(vetor, 3, ar);

    printf("\n-----------------------------\n");
    
    for(int i=0; i < 3; i++){
        printf("vetor[%d] = [%d]\n", i, *(vetor + i));
    }

    return 0;
}
