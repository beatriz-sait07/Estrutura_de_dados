#include <stdio.h>

int main (){
    int resul[6], aposta[6], i, j, k, cont=0;

    //lacos para leitura de dados
    //printf("resultado da mega-sena: \n");
    for(i=0; i<6; i++)scanf("%d", &resul[i]);

    //printf("digite suas apostas: \n");
    for(j=0; j<6; j++) scanf("%d", &aposta[j]);


    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if(resul[i] == aposta[j]) cont += 1;
        }
    }

    //laco para imprimir dados
    //printf("resultado: ");
    for(i=0; i<6; i++) printf("%d ", resul[i]);
    //printf("\naposta: ");
    for(j=0; j<6; j++) printf("%d ", aposta[j]);
    printf("\n%d\n", cont);
    return 0;
}