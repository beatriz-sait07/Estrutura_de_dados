#include "ex001.h"
#include <stdio.h>
#include <stdlib.h>


int main (){

    Node *root = NULL;
    Aluno *aluno = NULL;

    aluno = ler_aluno("Joao", 123, 7.5);root = insert_(root, aluno);
    aluno = ler_aluno("Maria", 456, 8.5);root = insert_(root, aluno);
    aluno = ler_aluno("Jose", 789, 9.5);root = insert_(root, aluno);
    aluno = ler_aluno("Pedro", 101, 10.0);root = insert_(root, aluno);
    aluno = ler_aluno("Ana", 112, 6.5);root = insert_(root, aluno);
    aluno = ler_aluno("Paulo", 113, 5.5);root = insert_(root, aluno);
    aluno = ler_aluno("Joana", 114, 4.5);root = insert_(root, aluno);
    aluno = ler_aluno("Julia", 115, 3.5);root = insert_(root, aluno);
    aluno = ler_aluno("Juliana", 116, 2.5);root = insert_(root, aluno);

    //imprimir_Aluno(aluno);
    in_order(root);
    destroy_node(root);
    return 0;
}