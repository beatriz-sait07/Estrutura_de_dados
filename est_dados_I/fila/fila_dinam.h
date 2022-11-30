#ifndef FILA_DINAM_H
#define FILA_DINAM_H

#include<stdbool.h>
#include<stddef.h>

typedef struct _node Node;
typedef struct _list List;
typedef struct _queue Queue;

//-----------------List-----------------
Node *Node_create(int val);
List *List_create();
void Destroy_List(List **Ref_list);
bool is_Empty_List(const List *L);
size_t List_size(const List *L);
void Add_Last_List(List *L, int val);
void Remove_First_List(List *L);
void print_List(const List *L);

//-----------------Queue-----------------
Queue *create_Queue();
void destroy_Queue(Queue **Q_Ref);

bool is_empty_Queue(const Queue *Q);
long size_Queue(const Queue *Q);
void print_Queue(const Queue *Q);

void enqueue_Queue(Queue *Q, int info);
int dequeue_Queue(Queue *Q);
int peek_Queue(const Queue *Q);

#endif