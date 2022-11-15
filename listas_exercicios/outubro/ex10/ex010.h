#include <stdbool.h>

typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;

bool isNull(List *lista);
Node *create_node(char *string);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(List *lista, char *s);
void print_list(List *lista);
