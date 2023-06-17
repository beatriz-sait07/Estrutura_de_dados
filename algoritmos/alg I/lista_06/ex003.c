#include <stdio.h>
#include<stdlib.h>
//organizar vetor em ordem crescente (modelo bubble-sort)

int main(){
    int tam, val, del, cont = 0;

    //printf("qual sera o tamanho do vetor: ");
    scanf("%d", &tam);

    int vetor[tam];

    //printf("Digite os valores para seu vetor:\n");
    for(int i = 0; i < tam; i++){ //para nao haver repeticoes
        scanf("%d", &val);
        vetor[i] = val;
    }

    //printf("qual sera o elemento deseja remover: ");
    scanf("%d", &del);

    for(int i=0; i<tam; i++){
        if(vetor[i] == del){
            for(int j = i+1; j<tam; j++)vetor[j-1] = vetor[j];
            tam--;
        }    
    }

    for(int i=0; i<tam; i++) printf("%d ", vetor[i]);
    return 0;
}