#include "./lista_enc.h"
#include <stdio.h>
#include <stdlib.h>
struct node {
    bool mascara;
    bool infectado;
    struct node *next;
};

struct list {
    long int size;
    struct node *begin;
};

struct node *Node_create(bool mask, bool infctd) {
    struct node *Node = (struct node*)calloc(1, sizeof(struct node));
    Node->mascara = mask;
    Node->infectado = infctd;
    Node->next = NULL;
    return Node;
}

struct list *List_create() {
    struct list *l = (struct list*)calloc(1, sizeof(struct list));
    l->begin = NULL;
    l->size = 0;
    return l;
}

bool isNull(struct list *l) {
    return l->size == 0;
}

void insert(struct list *l, bool msk, bool infctd) {
    struct node *n = Node_create(msk, infctd);
    if (isNull(l)) {
        l->begin = n;
    } else {
        struct node *aux = l->begin;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = n;
    }
    l->size++;
}


void free_list(struct list **l) {
    struct list *lista = *l;
    struct node *p = lista->begin;
    struct node *aux = NULL;
    while (p != NULL) {
        aux = p->next;
        free(p);
        p = aux;
    }
    free(lista);
    *l = NULL;
    printf("Lista liberada com sucesso!\n");
}


//pense no caso de inserir os dados como uma tabela verdade e a cada true aumenta 25% de chance de ser infectado