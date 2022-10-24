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
    Dados *pessoa=cadastro(pessoa, 9, 7);
    List *lista = create_lista();
    insert_dados(lista, pessoa);
    print_list(lista);

    
    /*List *lista = create_lista();
    insert_dados(lista, cadastro("bia", 6,9));
    print_list(lista);*/
    return 0;
}
