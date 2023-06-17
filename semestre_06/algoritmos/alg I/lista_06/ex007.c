#include <stdio.h>

int main(){
    int tam, val;
    printf("qual sera o tamanho do seu array: ");scanf("%d", &tam);

    int vet[tam];

    printf("digite %d numeros para seu array: ", tam);
    for(int i=0; i<tam; i++){
        scanf("%d", &val);
        vet[i]=val;
    }

    for(int i = 0; i < tam; i++) {
        if (vet[i] < 0) {
            for (int j = i+1; j < tam; j++) vet[j-1] = vet[j];
            tam--; 
        }
    }

    for(int i=0; i<tam; i++) printf("%d ", vet[i]);

    return 0;
}