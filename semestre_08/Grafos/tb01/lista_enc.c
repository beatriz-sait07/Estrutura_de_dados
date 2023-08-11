#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>
struct node {
    //char individuo[20]; // realmente preciso disso ?
    bool mascara;
    bool infectado;
    struct node *next;
};

struct list {
    long int size;
    struct node *begin;
};

struct node *Node_create(char *caracter) {
    struct node *Node = (struct node*)calloc(1, sizeof(struct node));
    Node->mascara = false;
    Node->infectado = false;
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

void insert(struct list *l, char caracter) {
    struct node *n = Node_create(caracter);
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

void print_list(const struct list *l) {
    struct node *aux = l->begin;
    if (aux != NULL) {
        printf("INICIO -> ");
        while (aux != NULL) {
            printf("%s -> ", aux->individuo[20]);
            aux = aux->next;
        }
        printf("NULL\n");
    } else {
        printf("A lista está vazia!\n");
    }

    printf("Tamanho = %ld\n", l->size);
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