#ifndef LISTA_ENC_H
#define LISTA_ENC_H
#include<stdbool.h>

struct node;
struct list;

struct node *Node_create(bool mask, bool infctd);
struct list *List_create();

bool isNull(struct list *l);
void insert(struct list *l, bool msk, bool infctd);
void free_list(struct list **l);

#endif