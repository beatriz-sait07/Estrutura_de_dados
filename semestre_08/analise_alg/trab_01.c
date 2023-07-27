#include <stdio.h>
#include <time.h>

int main(){
    clock_t t = clock();

    for(int i = 10; i >= 0; i--){
        printf("%d\n",i);
    }

    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\nO codigo levou %f segundos para executar\n", time);
    return 0;
}
/*
antes:
5 --> t = clock, i=10 e i>=0 o i-- nao está incluso pq o decremento ainda não ocorreu!
durante:
10 pq o i vai ser menor que o 0 10x e vai ser decrementado 10x
depois:
10 imprime cada emento do i
1 --> t = clock - t
1 --> time = t/CLOCKS_PER_SEC
1 --> imprime o time
1 --> return 0
f(x) = 5 + 20 + 10 + 1 + 1 + 1 + 1 = 39
*/
