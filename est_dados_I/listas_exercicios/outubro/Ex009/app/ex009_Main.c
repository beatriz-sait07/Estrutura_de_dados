#include "ex009.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Info *pessoa;
    List *lista_a = create_lista();
    List *lista_s = create_lista();

    pessoa = cadastro("servidor", "Arnaldo", "15236", 1, "QAP-6938");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("servidor", "Marcos", "79012", 2, "QAE-9803");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "rosana", "44678", 3, "POT-5412");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "lucas", "41096", 4, "AFR-4574");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "bianca", "79663", 5, "MJG-6834");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "luan", "65731", 6, "AGR-3479");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "maria", "02145", 7, "PLJ-9668");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "jose", "85697", 8, "HUO-8570");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "davi", "65379", 9, "OOI-0035");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "antonio", "32048", 10, "AAS-9684");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "maristela", "20345", 11, "CRQ-2248");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "sergio", "9863", 12, "OQA-9975");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "emilly", "79658", 13, "PLU-5571");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "diogo", "67529", 14, "BMH-1577");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "brenda", "62435", 15, "GRT-4857");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "andre", "57854", 16, "QTA-3105");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "moises", "35024", 17, "OOP-2504");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "gabriel", "75168", 18, "UHT-9678");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "mauricio", "36528", 19, "POL-1096");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "pedro", "75813", 20, "KJJ-7684");insert_dados(lista_a, lista_s,pessoa);
    pessoa = cadastro("aluno", "luffy", "78562", 21, "UYI-3869");insert_dados(lista_a, lista_s,pessoa);
    printf("CONTROLE DO ESTACIONAMENTO: \n");
    print_list(lista_a, lista_s);

    printf("\n\n");
    return 0;
}
