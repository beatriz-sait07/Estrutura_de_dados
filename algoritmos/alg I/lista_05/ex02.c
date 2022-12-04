#include <stdio.h>
#include <stdlib.h>

int main(){
    int veic;
                

    printf("quantidade de veiculos: "); scanf("%d", &veic);
    float vet[veic], tempo, melhor = 5.0, media=0;
    for(int i=0; i<veic; i++){
        printf("tempo do veiculo [%d]: ", i);scanf("%f", &tempo);
        vet[i] = tempo;
        if(vet[i] < melhor) melhor = vet[i];
    }

    for(int i=0; i<veic; i++) media += vet[i];
    printf("\nmelhor tempo: %.2f\n", melhor);
    printf("media: %.2f\n", (media/veic));


    return 0;
}