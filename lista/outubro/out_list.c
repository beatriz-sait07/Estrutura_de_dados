/*
pretende-se utilizar uma lista ligada simples para realizar a gestao de uma lista telefonica.
A lista dever ́a armazenar a morada de cada assinante. O programa dever ́a realizar as seguintes
funcoes: inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e
contar o numero de elementos na lista
*/

#include "ex04.h"
#include <stdio.h>
#include<stdlib.h>

int main(){
    printf("exercicio Nº04\n");
    //aloca o espaço para receber os dados pessoa
    Dados *pessoa; 
    //recebe os dados de pessoa
    cadastro(pessoa, "Bia", "Paranaiba, 866, Centro", "993008608");
    //cria a lista para receber pessoa
    List *lista = create_lista();
    //coloca os dados de pessoa na lista;
    insert_dados(pessoa, lista);
    //cria um novo dado
    cadastro(pessoa, "Susy", "Paranaiba, 866, Centro", "92063261" );
    insert_dados(pessoa, lista);
    print_list(lista);
    return 0;
}

    /*Dados *pessoa2 = cadastro(pessoa2, "Luan", "Rua J, 3262, Sao Joao", "999620571" );
    Dados *pessoa3 = cadastro(pessoa3, "Maria", "Vieira Caastro, 2336, Lapa", "92063261" );
    */


