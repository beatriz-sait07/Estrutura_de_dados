#include"bubble.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main (int argc, char const *argv[])
{
    int vetor[8] = {7, 3, 0, 1, 3, 8, 2, 9};
    printf("|%d", vetor[8]);
    bubble(vetor,8);
    print_novo_vetor(vetor, 8);

    return 0;
}