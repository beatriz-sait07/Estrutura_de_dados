#include "binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Tree *t = create_tree();

    int dig = 1, size=0, elem;
    while(dig != 0){
        printf("\n\t0 - sair\n\t1 - inserir um valor\n\t2 - remover um valor\n\t3 - consultar um valor\n\t4 - consultar simetria da arvore\n");
        printf("\t5 - imprimir dados da arvore\n\t6 - imprime arvore\n\t7 - profundidade\n\t8 - destruir a arvore\n");
        printf("qual operacao deseja realizar: ");
        scanf("%d", &dig);

        if(dig == 1){
            int escolha;
            printf("escolha:\n1 - arvore aleatoria\n2 - arvore simetrica\nresp: ");scanf("%d", &escolha);

            if(escolha == 1){
                srand(time(NULL));
                int i=0, igual, vet[255];
                printf("quantos valores deseja inserir: ");scanf("%d", &size);
                do{
                    vet[i] = rand()%100;
                    igual = 0;
                    for(int j=0; j<i; j++){
                        if(vet[j] == vet[i])igual = 1;
                    }
                    if(igual == 0)i++;
                }while(i<size);
                for(i=0;i<size; i++){
                    insert(t, vet[i]);
                }
            } else {
                int vet[7] = {40 , 20, 60, 10, 30, 50, 70};
                for(int i=0; i<7; i++){
                    insert(t, vet[i]);
                }
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
            validando_simetria_arvore(t);
        }
        if(dig == 5){
            in_order(t);
            pre_order(t);
            pos_order(t);
        }
        if(dig == 6){
            draw_tree(t);
        }
        if(dig == 7){
            profundidade_ar(t);
        }
        if(dig == 8){
            destroy_tree(t);
        }

        if(dig > 9){
            printf("\nesta opcao nao existe!\n");
            printf("\n\t0 - sair\n\t1 - inserir um valor\n\t2 - remover um valor\n\t3 - consultar um valor\n\t4 - consultar simetria da arvore\n");
            printf("\t5 - imprimir dados da arvore\n\t6 - imprime arvore\n\t7 - profundidade\n\t8 - destruir a arvore\n");
            printf("qual operacao deseja realizar: ");
            scanf("%d", &dig);
        }
    }

    return 0;
}