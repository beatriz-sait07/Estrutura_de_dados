#include"ex015.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int val;
    struct _node *next;
} Node;
typedef struct _list{
    Node *begin;
    Node *end;
    int size;
} List;

Node *Node_create(int val)
{
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->val = val;
    node->next = node;

    return node;
}
List *List_create()
{
    List *L = (List*)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void Node_Destroy(Node **Ref_node)
{
    free(*Ref_node);
    *Ref_node = NULL;
}
void List_Destroy(List **Ref_list)
{
    List *L = *Ref_list;
    Node *aux = NULL;
    Node *p = L->begin;

    for(int i=0; i< L->size; i++){
        aux = p;
        p = p->next;
        Node_Destroy(&aux);
    }
    free(L);
    *Ref_list = NULL;
}
bool is_Empty(const List *list)
{
    return list->size == 0;
}
void Add_Last(List *L, int val)
{
    Node *p = Node_create(val);
    if(is_Empty(L)){
        L->begin = L->end = p;
    }else{
        L->end->next = p;
        L->end = p;
        //Circular:
        p->next = L->begin;
    }
    L->size++;
}


// (a) - contar o numero de elementos numa lista circular;
int size_List(const List *L)
{
    return L->size;
}                   

// (b) - inserir um elemento a esquerda da cabeca da lista;
void InsertLeft_List(List *L, int val)
{
    Node *p = Node_create(val);

    if(is_Empty(L)){
        L->end = p;
    }else{
        p->next = L->begin;
        L->end->next = p;
    }
    L->begin = p;
    L->size++;
}

// (c) concatenar duas listas circulares;
void Merge_List(List *L1, List *L2)
{
    L1->end->next = L2->begin;
    L1->end = L2->end;
    L1->size += L2->size;
    L1->end->next = L1->begin;
}

// (d) intercalar duas listas;
List *Intercalate_List(List *L1, List *L2)
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
List *Copy_List(List *L)
{
    List *new = List_create();
    new = L;

    return new;
}


void print_CircularList(const List *L)
{
    if(is_Empty(L)){
        fprintf(stderr, "Erro em print_CircularList()\n");
        fprintf(stderr, "Lista Vazia!\n");
        exit(EXIT_FAILURE);
    }else{
        Node *p = L->begin;
        printf("Lista = ");
        do{
            printf("|%d|->", p->val);
            p = p->next;
        }while(p != L->begin);
        printf("Begin\n");
        printf("L->Begin: |%d|\n", L->begin->val);
        printf("L->End: |%d|\n", L->end->val);
        printf("L->End->Next: |%d|\n", L->end->next->val);
    }
}