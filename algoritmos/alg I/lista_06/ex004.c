#include <stdio.h>

int main() {
    int tam1, tam2, tam3, val, i, j, k;
    printf("qual o tamanho do 1 vetor: ");scanf("%d", &tam1);
    printf("qual o tamanho do 2 vetor: ");scanf("%d", &tam2);

    tam3 = tam1+tam2;

    int vet1[tam1], vet2[tam2], vetor[tam3], cont=0;

    //recebendo dados
    for(i=0; i<tam1; i++){
        printf("vetor[1], elemento: ");scanf("%d", &val);
        vet1[i] = val;
    }
    for(j=0; j<tam2; j++){
        printf("vetor[2], elemento: ");scanf("%d", &val);
        vet2[j] = val;
    }

    //criar 3 vetor apartir do 2 primeiros - sem repeticao
    for(i=0; i<tam1; i++) vetor[i] = vet1[i];
    for(i=tam1; i<tam3; i++) vetor[i] = vet2[i-tam1];

    //imprimindo valores antes de quaisquer alteracoes
    printf("vetor [1]: ");
    for(i=0; i<tam1; i++) printf("%d ", vet1[i]);
    printf("\nvetor [2]: ");
    for(i=0; i<tam2; i++) printf("%d ", vet2[i]);
    printf("\nvetor [3]: ");
    for(i=0; i<tam3; i++) printf("%d ", vetor[i]);

    //remove o numeros repedidos
    for(i=0; i<tam3; i++) {
        for(j=i+1; j<tam3;) {
            if(vetor[j] == vetor[i] ) {
                for(k=j; k<tam3; k++) vetor[k] = vetor[k + 1];
                tam3--;
            }
            else j++;
        }
    }


    printf("\nsem repeticao e em ordem crescente.\nvetor[3]: ");
    for(i=0; i<tam3; i++) printf("%d ", vetor[i]);

    return 0;
}