#include <stdbool.h>

typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;

bool isNull(List *lista);
Node *create_node(char *string);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(List *lista, char *s);
List *list_sec(List *lista);
void cop_first_list(List *first, List *sec);
void validar(List *sec);
void imprimir_lista(const List *list);

