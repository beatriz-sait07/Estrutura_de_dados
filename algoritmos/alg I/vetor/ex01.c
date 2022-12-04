#include <stdio.h>

int main (){
    int tam, i,j,val,vetor[tam], cont = 0;

    printf("qual tamanho do array: ");scanf("%d", &tam);

    // ja considerado que o usuario entrara com 1<= n <= 100
    for(i = 0; i < tam; i++){
        printf("valor para posicao [%d]: ", i);scanf("%d", &val);
        vetor[i] = val;

        for(j = 0; j <= i-1 ; j++){
            if(val == vetor[j]){
                cont = 1;
                break;
            }
        }
        if(cont == 1){
            cont = 0;
            i -= 1;
            tam -= 1; 
        } else vetor[i] = val;
    }
    for(i = 0; i < tam; i++) printf("|%d|", vetor[i]);
                
    return 0;
}