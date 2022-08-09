#include<stdio.h>
#include"select.h"
#define TAM 8

int main()
{
    int vetor[TAM] = {0,2,7,0,9,3,8,0};

    selection(vetor);
    print_vector(vetor);
    return 0;
}