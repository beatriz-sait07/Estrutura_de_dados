#include "../include/ex001.h"
#include <stdio.h>
#include <stdlib.h>


int main (){

    Tree *T = create_tree();

    insert(T, "Lucas", 101, 10.0);
    insert(T, "Maria", 102, 4.9);
    insert(T, "Jose", 103, 9.1);
    insert(T, "Beatriz", 104, 3.8);
    insert(T, "Ana", 105, 6.5);
    insert(T, "Paulo", 106, 1.8);
    insert(T, "Thalita", 107, 8.7);
    insert(T, "Julia", 108, 3.5);
    insert(T, "Taynan", 109, 2.5);

    printf("Aluno com a maior media:\n");
    abb_alunoComMaiorMedia(T);

    printf("Quantidade de alunos aprovados: %d\n", abb_contaAprovados(T));

    return 0;
}