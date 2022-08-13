#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"select.h"
#define T 4

int main()
{
    int vector[T];
    double tempo_ex = 0.0;
    clock_t begin = clock();

    srand(time(NULL));

    //vector[T] = (int*)calloc( T, sizeof(int));
    for(int i =0;i<T; i++)
    {
        vector[i] = rand()%T;
        printf("|%d|", vector[i]);
    }

    printf("\n\n");
    selection(vector,T);
    print_vector(vector,T);

    //free(vector);
    return 0;
}