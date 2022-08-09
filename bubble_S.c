#include"bubble.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define T 8
#define TM 50
#define TAM 10


int main (int argc, char const *argv[])
{
    double tp_ex = 0.0;
    clock_t begin = clock();

    int vector[T] = {7,3,0,1,3,8,2,9};

    bubble(vector,T);
    print_novo_vetor(vector, T);
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

    clock_t end = clock();
    tp_ex += (double)(end - begin)/ CLOCKS_PER_SEC;

    printf("tempo de execusao foi de %fs\n", tp_ex);

    return 0;
}