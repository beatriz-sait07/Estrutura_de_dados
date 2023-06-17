#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include<stdbool.h>
#include<stddef.h>

typedef struct _node Node;
typedef struct _list List;
typedef struct _queue Queue;

//-----------------List-----------------
Node *Node_create(int val, int priority);
List *List_create();
void Destroy_List(List **Ref_list);
bool is_Empty_List(const List *L);
void Add_Last_List(List *L, int val, int priority);
void print_List(const List *L);

//-----------------Queue-----------------
Queue *create_Queue();
void destroy_Queue(Queue **Q_Ref);

void print_Queue(const Queue *Q);

void enqueue_Queue(Queue *Q, int info, int priority);

void divide_Queue(Queue *Q, Queue *elements, Queue *remainder, int p);

#endif