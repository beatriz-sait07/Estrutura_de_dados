#include <stdio.h>
#include <stdlib.h>

void ler_dados(int *vetor, int i){
    int j;
    for(j=0;j<i;j++){
        printf("[%d] =  ", j);
        scanf("%d", &vetor[j]);
    }
}

int main(){
    int *dados, num, i;

    printf("tamanho do array: ");
    scanf("%d", &num);

    dados = (int*) malloc(sizeof(int)*num);

    if(dados == NULL){
        printf("erro na alocação!");
    return 0;
    }

    ler_dados(dados, num);

    printf("\n-----------------------------\n");

    for(i = 0; i < num; i++){
        printf("[%d]  ", dados[i]);
    }

    free(dados);

return(0);
}
