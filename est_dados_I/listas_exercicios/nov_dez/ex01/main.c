#include "ex001.h"
#include <stdio.h>
#include <stdlib.h>


int main (){

    Node *root = NULL;
    Aluno *aluno = NULL;

    aluno = ler_aluno("lucas", 101, 10.0);root = insert_(root, aluno);
    aluno = ler_aluno("Maria", 102, 4.9);root = insert_(root, aluno);
    aluno = ler_aluno("Jose", 103, 9.1);root = insert_(root, aluno);
    aluno = ler_aluno("beatriz", 104, 3.8);root = insert_(root, aluno);
    aluno = ler_aluno("Ana", 105, 6.5);root = insert_(root, aluno);
    aluno = ler_aluno("Paulo", 106, 1.8);root = insert_(root, aluno);
    aluno = ler_aluno("thalita", 107, 8.7);root = insert_(root, aluno);
    aluno = ler_aluno("Julia", 108, 3.5);root = insert_(root, aluno);
    aluno = ler_aluno("taynan", 109, 2.5);root = insert_(root, aluno);

    printf("imprimindo alunos com o modelo 'in order':\n");
    in_order(root);

    printf("aluno com a maior media:\n");
    imprimir_no(maior(root));

    destroy_node(root);
    return 0;
}