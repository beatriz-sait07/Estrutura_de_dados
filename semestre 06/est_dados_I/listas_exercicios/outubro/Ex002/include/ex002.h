#ifndef EX002_H
#define EX002_H


typedef struct _node Node;
typedef struct _linkedList LinkedList;

Node *node_create(int val);
LinkedList *list_create();

int add_last(LinkedList *L, int val);
void print_list(const LinkedList *L);
void remove_pair(LinkedList *L);

#endif