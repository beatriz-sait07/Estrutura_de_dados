#include"ex016.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct _circ_node{
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
}CircNode, Node;

typedef struct _circ_list{
    Node *begin;
    Node *end;
    size_t size;
}CircList, List;

Node *Node_create(int val)
{
    CircNode *cnode = (CircNode*)calloc(1, sizeof(CircNode));
    cnode->val = val;
    cnode->next = cnode;
    cnode->prev = cnode;

    return cnode;
}
CircList *List_create()
{
    CircList *L = (CircList*)calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void Node_Destroy(CircNode **Ref_node)
{
    free(*Ref_node);
    *Ref_node = NULL;
}
void List_Destroy(CircList **Ref_list)
{
    CircList *L = *Ref_list;
    CircNode *aux = NULL;
    CircNode *p = L->begin;

    for(int i=0; i< L->size; i++){
        aux = p;
        p = p->next;
        Node_Destroy(&aux);
    }
    free(L);
    *Ref_list = NULL;
}
bool is_Empty(const CircList *lista)
{
    return lista->size == 0;
}
void Add_Last(CircList *L, int val)
{
    CircNode *p = Node_create(val);
    if(is_Empty(L)){
        L->begin = L->end = p;
    }else{
        L->end->next = p;
        p->prev = L->end;
        L->end = p;
        //Circular:
        L->begin->prev = p;
        p->next = L->begin;
    }
    L->size++;
}

// (a) - contar o numero de elementos numa lista circular;
int size_List(const CircList *L)
{
    return L->size;
}                   

// (b) - inserir um elemento a esquerda da cabeca da lista;
void InsertLeft_List(CircList *L, int val)
{
    CircNode *p = Node_create(val);

    if(is_Empty(L)){
        L->end = p;
    }else{
        p->next = L->begin;
        L->begin->prev = p;
        p->prev = L->end;
        L->end->next = p;
    }
    L->begin = p;
    L->size++;
}

// (c) concatenar duas listas circulares;
void Merge_List(CircList *L1, CircList *L2)
{
    L2->begin->prev = L1->end;
    L1->end->next = L2->begin;
    L1->end = L2->end;
    L1->size += L2->size;
    L1->begin->prev = L1->end;
    L1->end->next = L1->begin;
}

// (d) intercalar duas listas;
List *Intercalate_List(CircList *L1, CircList *L2)
{
    if(!is_Empty(L1) && !is_Empty(L2)){
        List *new = List_create();
        // Inicia no segundo pra simplificar
        Node *aux1 = L1->begin->next;
        Node *aux2 = L2->begin->next;

        // Coloca os dois primeiros ja que comeca no segundo
        Add_Last(new, L1->begin->val);
        Add_Last(new, L2->begin->val);

        // Colocando um elemento de cada ate chegar no fim de alguma lista
        while(aux1 != L1->begin && aux2 != L2->begin){
            Add_Last(new, aux1->val);
            Add_Last(new, aux2->val);
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        if(aux1 == L1->begin){
            aux1 = aux2;
            L1 = L2;
        }
        while(aux1 != L1->begin){
            Add_Last(new, aux1->val);
            aux1 = aux1->next;
        }

        return new;
    }
}

// (e) fazer uma copia da lista;
List *Copy_List(CircList *L)
{
    List *new = List_create();
    new = L;

    return new;
}


void print_CircularList(const CircList *L)
{
    if(is_Empty(L)){
        fprintf(stderr, "Erro em print_CircularList()\n");
        fprintf(stderr, "Lista Vazia!\n");
        exit(EXIT_FAILURE);
    }else{
        CircNode *p = L->begin;
        printf("Lista = ");
        do{
            printf("|%d|->", p->val);
            p = p->next;
        }while(p != L->begin);
        printf("Begin\n");
        printf("L->Begin: |%d|\n", L->begin->val);
        printf("L->End: |%d|\n", L->end->val);
        printf("L->Begin->Prev: |%d|\n", L->begin->prev->val);
        printf("L->End->Next: |%d|\n", L->end->next->val);
    }
}
