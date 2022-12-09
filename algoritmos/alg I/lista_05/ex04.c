#include <stdio.h>

int main (){
    int tam;
    //printf("qual o tamanho do seu array: ");
    scanf("%d", &tam);
    int vet[tam], val, busca=0;
    //printf("digite valores para prencher o vetor:\n");
    for(int i=0; i<tam; i++){
        scanf("%d", &val);
        vet[i] = val;
    }

    //printf("qual valor voce deseja buscar dentro do array: ");
    scanf("%d", &busca);
    
    for(int i=0; i<tam; i++){
        if(busca == vet[i]) printf("o valor %d esta na posicao %d do vetor\n", vet[i], i);
    }
    
    return 0;
}