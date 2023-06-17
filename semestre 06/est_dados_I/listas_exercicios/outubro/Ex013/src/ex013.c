#include<stdio.h>
#include<stdlib.h>
#include"ex013.h"

typedef struct _node{
    int val;
    int priority;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _list{
    Node *begin;
    Node *end;
    size_t size;
} List;

typedef struct _queue{
    List *data;
} Queue;

//-----------------List-----------------

Node *Node_create(int val, int priority)
{
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    node->priority = priority;

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
void Destroy_List(List **Ref_list)
{
    List *L = *Ref_list;
    Node *p = L->begin;

    while(p != NULL){
        Node *aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *Ref_list = NULL;
}
bool is_Empty_List(const List *L)
{
    return L->size == 0;
}
void Add_Last_List(List *L, int val, int priority)
{
    Node *new = Node_create(val, priority);
    new->prev = L->end;
    if(is_Empty_List(L)){
        L->begin = new;
    }else{
        L->end->next = new;
    }
    L->end = new;
    L->size++;
}
void print_List(const List *L)
{
    Node *p = L->begin;

    printf("Fila = ");
    while(p != NULL){
        printf("(%d)|%d| - ", p->priority, p->val);
        p = p->next;
    }
    printf("fim\n");
}

//-----------------Queue-----------------

Queue *create_Queue()
{
    Queue *Q = (Queue*)calloc(1, sizeof(Queue));
    Q->data = List_create();
    return Q;
}
void destroy_Queue(Queue **Q_Ref)
{
    Queue *Q = *Q_Ref;
    Destroy_List(&Q->data);
    free(Q);
    *Q_Ref = NULL;
}

void enqueue_Queue(Queue *Q, int info, int priority)
{
    Add_Last_List(Q->data, info, priority);
}

void print_Queue(const Queue *Q)
{
    print_List(Q->data);
}

void divide_Queue(Queue *Q, Queue *elements, Queue *remainder, int p)
{
    Node *aux = Q->data->begin;
    while(aux!=NULL){
        if(aux->priority <= p){
            enqueue_Queue(elements, aux->val, aux->priority);
        }else{
            enqueue_Queue(remainder, aux->val, aux->priority);
        }
        aux = aux->next;
    }
}