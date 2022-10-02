#include<stdio.h>
#include<stdlib.h>
#include"encadeada_simples.h"
#include"dupla_encad.h"


int main (){
    printf("\nLISTA ENCADEADA SIMPLES\n\n");
    Lista *lista_end = Lista_create();
    add_inicio(lista_end, 2);
    insert_ordem(lista_end, 6);
    insert_ordem(lista_end, 12);
    insert_ordem(lista_end, 9);
    insert_ordem(lista_end, 6);
    insert_ordem(lista_end, 8);
    insert_ordem(lista_end, 16);
    insert_ordem(lista_end, 25);
    insert_ordem(lista_end, 13);
    insert_ordem(lista_end, 32);
    insert_ordem(lista_end, 3);
    insert_ordem(lista_end, 7);
    insert_ordem(lista_end, 19);
    insert_ordem(lista_end, 11);
    insert_ordem(lista_end, 14);
    print(lista_end);
    printf("\nexcluindo o primeiro elemento\n");
    remover_elemento(lista_end, 2);
    print(lista_end);
    printf("\nremovendo elementos iguais\n");
    remover_elemento(lista_end, 6);
    print(lista_end);
    printf("\nremovendo elemento do meio da lista\n");
    remover_elemento(lista_end, 12);
    print(lista_end);
    printf("\nremovendo elemento do final\n");
    remover_elemento(lista_end, 32);
    print(lista_end);
    printf("\nbuscando elemento na lista\n");
    busca_elemento(lista_end, 6);
    printf("\nremovendo todos os elementos\n");
    remover_todos_elementos(&lista_end);

    printf("\n\n---------------------------------------\n\n");

    printf("LISTA DUPLAMENTE ENCADEADA\n\n");
    List *lista_dupla_enc = create_list();
    printf("add no final da lista:\n");
    add_final_dupla(lista_dupla_enc, 3);
    add_final_dupla(lista_dupla_enc, 6);
    add_final_dupla(lista_dupla_enc, 5);
    add_final_dupla(lista_dupla_enc, 2);
    add_final_dupla(lista_dupla_enc, 8);
    add_final_dupla(lista_dupla_enc, 1);
    add_final_dupla(lista_dupla_enc, 15);
    add_final_dupla(lista_dupla_enc, 23);
    imprimir_lista(lista_dupla_enc);
    printf("\n\nprint invertido:\n");
    imprimir_invert(lista_dupla_enc);
    /*printf("\ndesalocando totalmente:\n");
    destroy_dupla(&lista_dupla_enc);
    imprimir_lista(lista_dupla_enc);*/

    return 0;
}