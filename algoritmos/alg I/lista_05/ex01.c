#include <stdio.h>

int main (){
    int tam, i,j,val,vetor[tam], cont = 0;

    printf("qual tamanho do array: ");scanf("%d", &tam);

    // ja considerado que o usuario entrara com 1<= n <= 100

    for(i = 0; i < tam; i++) printf("|%d|", vetor[i]);
                
    return 0;
}