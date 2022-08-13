#include"bubble.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define test 50
#define T 100000
#define TM 500000
#define TAM 1000000


int main (int argc, char const *argv[])
{
    double tp_ex = 0.0;
    clock_t begin = clock();


        int vector[T];
        printf("VOCE ESCOLHEU O VETOR DE 100K!\n");
        printf("aguarde...\n");
        for(int i =0;i<T; i++){
            vector[i] = rand()%T;
        }
        bubble(vector,T);
        printf("dados do vetor de 100K armazenados! \n\n");


        int vector[TM];
        printf("VOCE ESCOLHEU O VETOR DE 500K!");
        printf("aguarde...\naguarde...\n");
        for(int i=0;i<TM; i++){
            vector[i] = rand()%TM;
        }
        bubble(vector,TM);

        int vector[TAM];
        printf("VOCE ESCOLHEU O VETOR DE 1M!");
        printf("aguarde...\naguarde...\n");
        for(int i=0;i<TAM; i++){
            vector[i] = rand()%TAM;
        }
        bubble(vector,TAM);

    clock_t end = clock();
    tp_ex += (double)(end - begin)/ CLOCKS_PER_SEC;

    print_arq(tp_ex);

    return 0;
}