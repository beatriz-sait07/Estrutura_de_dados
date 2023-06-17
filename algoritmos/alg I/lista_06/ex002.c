#include <stdio.h>
//organizar vetor em ordem crescente (modelo bubble-sort)

int main(){
    int tam, val, aux=1;

    //printf("qual sera o tamanho do vetor: ");
    scanf("%d", &tam);

    int vetor[tam];

    //printf("Digite os valores para seu vetor:\n");
    for(int i=0; i<tam; i++){
        scanf("%d", &val);
        vetor[i] = val;
    }

    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if(vetor[i]>vetor[j]){
                int swap = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = swap;
            }
        }
    }

    for(int i=0; i<tam; i++) printf("%d ", vetor[i]);
    return 0;
}