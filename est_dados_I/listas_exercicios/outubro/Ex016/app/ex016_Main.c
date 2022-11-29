#include"ex016.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    CircList *L1 = List_create();
    CircList *L2 = List_create();
    int elementos=0;

    puts("---------------------\n");
    puts("(b) inserir um elemento a esquerda da cabeca da lista");

    InsertLeft_List(L1, 5);
    InsertLeft_List(L1, 4);
    InsertLeft_List(L1, 3);
    InsertLeft_List(L1, 2);
    InsertLeft_List(L1, 1);
    print_CircularList(L1);

    puts("---------------------\n");
    puts("(a) contar o numero de elementos numa lista circular");

    elementos = size_List(L1);
    printf("%d elementos\n", elementos);

    puts("\n---------------------\n");
    puts("Criando a segunda lista:");

    InsertLeft_List(L2, 10);
    InsertLeft_List(L2, 9);
    InsertLeft_List(L2, 8);
    InsertLeft_List(L2, 7);
    InsertLeft_List(L2, 6);
    print_CircularList(L2);

    puts("\n---------------------\n");
    puts("(d) intercalar duas listas");

    CircList *New = Intercalate_List(L1, L2);
    print_CircularList(New);

    puts("\n---------------------\n");
    puts("(c) concatenar duas listas circulares");

    Merge_List(L1, L2);
    print_CircularList(L1);

    puts("\n---------------------\n");
    puts("(e) fazer uma copia da lista");

    CircList *copia = Copy_List(New);
    print_CircularList(New);

    puts("\n---------------------\n");

    List_Destroy(&L1);

return 0;
}
