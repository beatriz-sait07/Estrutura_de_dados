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
    printf("exercicio Nº04\n\n");

    Dados *pessoa;
    List *lista = create_lista();

    pessoa = cadastro("Susy", "Paranaiba, 866, Centro", "992063261" );
    insert_dados(pessoa, lista);

    pessoa = cadastro("Bia", "Paranaiba, 866, Centro", "993008608");
    insert_dados(pessoa, lista);

    pessoa = cadastro("luis", "Rua 7, 2350, Sao Joao", "996256304");
    insert_dados(pessoa, lista);

    pessoa = cadastro("joao", "Rua Augusta, 1361, Lapa", "982325000");
    insert_dados(pessoa, lista);

    print_list(lista);
    printf("buscando cadastro: bia\n");
    busca_elemento(lista,"Bia");
    printf("\nbuscando cadastro: antonio\n");
    busca_elemento(lista,"antonio");
    printf("\nexcluindo cadastro: luis\n");
    excluir_cliente(lista, "luis");
    print_list(lista);
    //destroy(&lista);
    printf("programa filanizado!\nVerifique no arq: resp_ex04.txt\n\n");
    return 0;
}

    /*Dados *pessoa2 = cadastro(pessoa2, "Luan", "Rua J, 3262, Sao Joao", "999620571" );
    Dados *pessoa3 = cadastro(pessoa3, "Maria", "Vieira Caastro, 2336, Lapa", "92063261" );
    */


