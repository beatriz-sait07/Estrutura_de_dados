#include <stdbool.h>

typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;

bool isNull(List *lista);
bool isFull(List *lista);
Info *cadastro (char *usuario, char *nome, int *id, int vaga, int placa);
Node *create_node(Info *p);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(Info *p, List *lista);
int tam_lista(const List *lista);
void print_list(const List *lista);