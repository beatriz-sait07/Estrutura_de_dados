#include "ex9.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Info *pessoa;
    List *lista_a = create_lista();
    List *lista_s = create_lista();

    pessoa = cadastro("aluno", "Arnaldo", "15236", 1, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 2, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 3, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 4, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 5, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 6, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 7, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 8, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 9, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 10, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 11, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 12, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 13, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 14, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 15, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 16, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 17, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 18, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 19, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 20, "QAP-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "Arnaldo", "15236", 21, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    printf("CONTROLE DO ESTACIONAMENTO: \n");
    print_list(lista_a, lista_s);

    printf("\n\n");
    return 0;
}
