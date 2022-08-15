#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Insertion.h"


int main()
{
    int size = 5;
    int vetor[] = {23, 4, 67, -8, 21};
    insertion(vetor, size);
    dados_arq(vetor, size);
   
    return 0;
}
