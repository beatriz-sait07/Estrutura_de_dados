#include <stdio.h>
#include <stdlib.h>


int main(){

    int dig=999;
    switch(dig){
        printf("qual exercicio voce deseja executar ?\n 1 - vetor sem repeticao\n");
        printf("2 - ");
        printf("respos: ");scanf("%d", &dig);
        
        if (dig == 1){
            int ex1, aux=0;
            printf("voce esta executando o exercicio numero 01!\n");
            printf("quantos numero deseja digitar ?\nresp: ");scanf("%d", &ex1);

            int vet[ex1], val, i;
            
            for(i=0; i<ex1; i++){
                printf("digite um valor para a posicao [%d]: ", i);scanf("%d", &val);
                vet[i] = val;
            }
            for(i=0; i<ex1; i++){
                aux = vet[i];
                if(aux != vet[i+1])
                printf("|%d|", vet[i]);
            }
        }
        if(dig == 2){

        }
    }
return 0;
}