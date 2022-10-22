/*
pretende-se utilizar uma lista ligada simples para realizar a gestao de uma lista telefonica.
A lista dever ́a armazenar a morada de cada assinante. O programa dever ́a realizar as seguintes
funcoes: inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e
contar o numero de elementos na lista
*/

#include "list_out.h"
#include <stdio.h>

int main(){
    printf("exercicio Nº04\n");
    List *lista = create_lista();
    char *nm = "bia", *ru = "augusta";
    insert_dados(lista, nm,ru);
    printf("fim de armazenamento!\n");
    print_list(lista);
    return 0;
}
