#include<stdio.h>
#include<stdlib.h>
#include"Float_vector.h"
#include"Merge.h"

int main ()
{    
    FloatVector *vector = create(8);
    for(int i = 0; i < capacity(vector); i++)
    {
        int var = rand()%10;
        append(vector, var);
    }
    //print(vector);
    printf("\n\norganizando...");
    
    int inicio = get(vector, 0);
    int fim = get(vector,size(vector));
    mergesort(&vector, inicio, fim);
    //print();

    return 0;
}