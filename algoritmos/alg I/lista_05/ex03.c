#include <stdio.h>

//nao entendi exatamente o que foi pedido, mas fiz o que eu compreendi

int main (){
    int m, n, val=0;
    //printf("quantidade de vetor: ");
    scanf("%d", &m);
    //printf("tamanho do vetor: ");
    scanf("%d", &n);

    int vet[m], i, j, maior=0, menor=0, pos_maior, pos_menor;  

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            //printf("vetor [%d] valor para posicao [%d]: ", i, j);
            scanf("%d", &val);
            vet[j] = val;
            if(j == 0) menor = maior = vet[j];
            if(vet[j] > maior){
                maior = vet[j];
                pos_maior = j;

            } 
            else {
                menor = vet[j];
                pos_menor = j;
            }
        }
        printf("%d %d\t %d %d\n", maior, pos_maior, menor, pos_menor);
        maior = menor  = 0;
    }
    
    for(i=0; i<m; i++){
        
        printf("\n");
    }
    return 0;
}