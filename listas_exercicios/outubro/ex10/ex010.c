#include "ex010.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct cad_inf {
    char *string;
} Info;

typedef struct node_simples {
    Info *cadastro_if;
    struct node_simples *next;
    struct node_simples *prev;
    
} Node;

typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int size_list;
} List;