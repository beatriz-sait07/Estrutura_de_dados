#ifndef EX01_H
#define EX01_H
#include<stdbool.h>

typedef struct _double_node DoubleNode, Node;
typedef struct _double_list DoubleList, List;

Node *create_node(int val);
List *create_list();

void destroy_dupla(List **ref_list);
bool _isNull_dupla(const List *list);
void add_final_dupla(List *list, int val); 
void imprimir_lista(const List *list);

#endif