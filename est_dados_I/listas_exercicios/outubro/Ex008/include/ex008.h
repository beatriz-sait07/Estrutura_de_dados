#include <stdbool.h>

typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;

bool isNull(List *lista);
Info *cadastro (char *usuario, char *nome, char *id, int vaga, char *placa);
Node *create_node(Info *p);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(Info *p, List *lista);
void print_list(List *lista);