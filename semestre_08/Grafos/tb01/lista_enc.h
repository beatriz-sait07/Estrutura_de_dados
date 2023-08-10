#ifndef LISTA_ENC_H
#define LISTA_ENC_H
#include<stdbool.h>

struct node;
struct list;

struct node *Node_create(char caracter);
struct list *List_create();

bool isNull(struct list *l);
void insert(struct list *l, char caracter);
void free_list(struct list *l);
void print_list(const struct list *l);
void free_l(struct list **l);

#endif