//faca uma contagem regressiva de 0 a 10 e e calcule o tempo de execução do codigo total
//usando a funcao clock() da biblioteca time.h

#include <stdio.h>
#include <time.h>

int main(){
    clock_t t = clock();

    for(int i = 10; i >= 0; i--){
        printf("%d\n",i);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("O codigo levou %f segundos para executar\n", time_taken);
    return 0;
}
/*
3 --> t = clock, i=10 e i>=0 o i-- nao está incluso pq o decremento ainda não ocorreu!
20 pq o i vai ser menor que o 0 10x e vai ser decrementado 10x
10 imprime cada emento do i
1 --> t = clock - t
*/
