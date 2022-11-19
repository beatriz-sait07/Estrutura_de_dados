#include "binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Tree *t = create_tree();

    int dig = 1;
    int size=0;
    while(dig != 0){
        srand(time(NULL));
        int elem;
        /*    for(int i=0; i<100; i++){
                elem = rand()%100;

            }*/

        printf("\n\t0 - sair\n\t1 - inserir um valor\n\t2 - remover um valor\n\t3 - consultar um valor\n\t4 - consultar simetria da arvore\n\t5 - imprimir arvore\n\t");
        printf("qual operacao deseja realizar: ");
        scanf("%d", &dig);

        if(dig == 0){
            destroy_tree(t);
        }
        if(dig == 1){
            //printf("\ninsira um valor: ");scanf("%d", &elem);
            printf("quantos valores deseja inserir: ");scanf("%d", &size);
            srand(time(NULL));
            for(int i=0; i<size; i++){
                elem = rand()%size;
                insert(t, elem);
            }
        }
        if(dig == 2){
            printf("\ninsira um valor para ser removido: ");scanf("%d", &elem);
            remover_arvore(t, elem);
        }
        if(dig == 3){
            printf("\ninsira um valor para ser encontrado na arvore: ");scanf("%d", &elem);
            buscar(t, elem);
        }
        if(dig == 4){
            printf("nao foi feito ainda\n");
        }
        if(dig == 5){
            in_order(t);
            pre_order(t);
            pos_order(t);
        }
        if(dig > 5){
            printf("\nesta opcao nao existe!\n");
            printf("\t0 - sair\n\t1 - inserir um valor\n\t2 - remover um valor\n\t3 - consultar um valor\n\t4 - consultar simetria da arvore\n\t5 - imprimir arvore\n\t");
            printf("qual operacao deseja realizar: ");
            scanf("%d", &dig);
        }
    }



    /*insert(t, 10);
    insert(t, 6);
    insert(t, 3);
    insert(t, 1);
    insert(t, 2);
    insert(t, 15);
    pre_order(t);
    in_order(t);
    pos_order(t);
    buscar(t, 3);
    buscar(t, 26);

    remover_arvore(t, 15);
    remover_arvore(t, 1);
    pre_order(t);
    in_order(t);
    pos_order(t);*/

    return 0;
}