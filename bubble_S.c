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
    for(int i = 0; i < T; i++){
        vector[i] = rand()%T;
    }

    bubble(vector,T);
    print_novo_vetor(vector, T);

    clock_t end = clock();
    tp_ex += (double)(end - begin)/ CLOCKS_PER_SEC;

    printf("tempo de execucao: %fs",tp_ex);
   
    return 0;
}

  /*int n;

    
    printf("escolha as opções a serem rodadas:");
    printf("1) 100k\n2) 500k\n3) 1M\n");

    switch (n)
    {

        case 1: printf("rodando um vetor de 100k");
        {
            bubble(vector,TAM);
            print_novo_vetor(vector, T);
        }
        break;

        case 2: printf("redando um vetor de 500k"); 
        {
            bubble(vector,TAM);
            print_novo_vetor(vector, TM);
        }
        break;

        case 3: printf("rodando um vetor de 1M");
        {
            bubble(vector,TAM);
            print_novo_vetor(vector, 8);
        }
        break;
    
    default: printf("digite um numero valido!");
    }*/