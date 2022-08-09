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
   
    int n;

    
    printf("escolha as opções a serem rodadas:\n");
    printf("1) 100k\n2) 500k\n3) 1M\n");
    scanf("%d", &n);

    switch (n)
    {

        case 1: printf("rodando um vetor de 100k\n");
        {
            printf("VOCE ESCOLHEU O VETOR DE 100K!\n");
            printf("aguarde...\n");
            bubble(vector,T);
        }
        break;

        case 2: printf("redando um vetor de 500k"); 
        {
            printf("VOCE ESCOLHEU O VETOR DE 500K!");
            printf("aguarde...\naguarde...\n");
            bubble(vector,TM);
        }
        break;

        case 3: printf("rodando um vetor de 1M");
        {
            printf("VOCE ESCOLHEU O VETOR DE 1M!");
            printf("aguarde...\naguarde...\n");
            bubble(vector,TAM);
        }
        break;
    
    default: printf("digite um numero valido!");
    }

    clock_t end = clock();
    tp_ex += (double)(end - begin)/ CLOCKS_PER_SEC;

    print_arq(tp_ex);

    return 0;
}