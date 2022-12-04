#include <stdio.h>

int main() {
    int tam1, tam2, val, i, j, k;
    printf("qual o tamanho do 1 vetor: ");scanf("%d", &tam1);
    printf("qual o tamanho do 2 vetor: ");scanf("%d", &tam2);


    int vet1[tam1], vet2[tam2], vetor[tam1], cont=0;

    //recebendo dados
    printf("dados do 1 vetor: ");
    for(i=0; i<tam1; i++){
        scanf("%d", &val);
        vet1[i] = val;
    }
    printf("dados do 2 vetor: ");
    for(j=0; j<tam2; j++){
        scanf("%d", &val);
        vet2[j] = val;
    }
    
    for(i=0; i<tam1; i++){
        for(j=0; j<tam2; j++){
            if(vet1[i] == vet2[j]){
                for(k=0; k<tam1; k++) vetor[k] = vet2[j];
            }
        }
    }

    //imprimindo valores antes de quaisquer alteracoes
    printf("vetor [1]: ");
    for(i=0; i<tam1; i++) printf("%d ", vet1[i]);
    printf("\nvetor [2]: ");
    for(i=0; i<tam2; i++) printf("%d ", vet2[i]);
    printf("\nvetor [3]: ");
    for(i=0; i<tam1; i++) printf("%d ", vetor[i]);

    
    return 0;
}