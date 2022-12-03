#include <stdio.h>
#include <stdlib.h>


int main(){

    int dig=999;
        while(dig != 0){
            printf("qual exercicio voce deseja executar ?\n 1 - vetor sem repeticao\n");
            printf("2 - \n");
            printf("respos: ");scanf("%d", &dig);
            
            if (dig == 1){
                int tam, i,j,val,vetor[tam], cont = 0;

                printf("qua tamanho do array: ");scanf("%d", &tam);

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

                for(i = 0; i < tam; i++)printf("|%d|", vetor[i]);
                
                printf("\nexercicio 1 executado com sucesso!\n");
            }

            if(dig == 2){

            }
        }

    return 0;
}