/*
pretende-se utilizar uma lista ligada simples para realizar a gestao de uma lista telefonica.
A lista dever ́a armazenar a morada de cada assinante. O programa dever ́a realizar as seguintes
funcoes: inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e
contar o numero de elementos na lista
*/

#include "ex04.h"
#include <stdio.h>

int main(){
    printf("exercicio Nº04\n");
    Dados *pessoa;
    List *lista = create_lista();
    cadastro(pessoa, "bia", "paranaiba", "993008608");
    insert_dados(lista, pessoa);
    print_list(lista);
    return 0;
}
