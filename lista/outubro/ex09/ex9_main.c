#include "ex9.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Info *pessoa;
    List *lista = create_lista();

    pessoa = cadastro("ESTUDANTE", "Bia", "31904", 3, "OOG-6111");
    insert_dados(pessoa, lista);
    pessoa = cadastro("FUNCIONARIO", "Marcia", "63016", 1, "OLN-3206");
    insert_dados(pessoa, lista);
    pessoa = cadastro("FUNCIONARIO", "Arnaldo", "15236", 9, "QAP-6938");
    insert_dados(pessoa, lista);
    pessoa = cadastro("FUNCIONARIO", "Luana", "86302", 7, "OOS-5204");
    insert_dados(pessoa, lista);
    pessoa = cadastro("ESTUDANTE", "Marcos", "79012", 4, "QAP-9803");
    insert_dados(pessoa, lista);
    print_list(lista);
    separa_dados(lista, pessoa);
    print_list(lista);
    //destroy(&lista);
    return 0;
}
