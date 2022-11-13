#include "ex9.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Info *pessoa;
    List *lista_e = create_lista();
    List *lista_f = create_lista();

    /*pessoa = cadastro("F", "Bia", "31904", 3, "OOG-6111");
    insert_dados(lista_f, pessoa);
    pessoa = cadastro("F", "Marcia", "63016", 1, "OLN-3206");
    insert_dados(lista_f, pessoa);*/
    pessoa = cadastro("F", "Arnaldo", "15236", 9, "QAP-6938");
    insert_dados(lista_e, pessoa);
    pessoa = cadastro("F", "Marcos", "79012", 4, "QAP-9803");
    insert_dados(lista_e, pessoa);
    /*pessoa = cadastro("ESTUDANTE", "Luana", "86302", 7, "OOS-5204");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "luan", "734967", 2, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "marta", "25379", 0, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "susy", "74893", 12, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "julius", "53896", 16, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "maria", "025795", 11, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "isabella", "48526", 13, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "uriel", "19685", 18, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "julia", "16798", 10, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "rinaldo", "03794", 5, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "rodrigo", "79012", 6, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "lucas", "97826", 8, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "ana", "02354", 14, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "anabelle", "34852", 19, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "antonio", "96532", 17, "QAP-9803");
    estacionamento(lista_e, pessoa);
    pessoa = cadastro("ESTUDANTE", "wesley", "32564", 15, "QAP-9803");
    estacionamento(lista_e, pessoa);*/
    printf("_____________________________________\n\tLISTA DE ESTUDANTES\n");
    print_list(lista_e);
    printf("_____________________________________\n\tLISTA DE FUNCIONARIOS\n");
    print_list(lista_f);
    return 0;
}
