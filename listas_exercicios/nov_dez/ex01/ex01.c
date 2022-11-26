#include "ex01.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node{
    int alt, idade;
    struct _double_node *next;
    struct _double_node *prev;
}DoubleNode, Node;

typedef struct _double_list{
    Node *inicio;
    Node *fim;
    size_t size, capacity;
}List, List;