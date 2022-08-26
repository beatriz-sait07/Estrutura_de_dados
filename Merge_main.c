#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Merge.h"

int main()
{
    int tam =10;
    Dados *vector = create(tam);

    srand(time(NULL));
    for(int i=0; i < tam; i++)
    {
        int var = rand()%10;
        adicionar(vector,var);
    }
    salva_dados(vector);

    mergesort(vector, 0, tam - 1);
    printf("\n\nordenando...\n\n");
    
    salva_dados(vector);
     
    
    return 0;
}