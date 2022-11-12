/*
A direção do IFMS considerou que existe um número excessivo de automóveis no esta-
cionamento da escola pelo que decidiu passar a cobrar pelo estacionamento aos alunos e
funcionários (nos quais se incluem os docentes). Pretende-se implementar um programa
que permita armazenar a informação dos arrendatários e respectivos lugares, utilizando
uma única lista duplamente ligada. A informação a armazenar é composta pelos seguintes
campos:
*/
#include "ex8.h"
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
    destroy(&lista);
    return 0;
}
