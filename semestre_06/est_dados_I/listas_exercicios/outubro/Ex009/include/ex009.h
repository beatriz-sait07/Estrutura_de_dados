#include <stdbool.h>

typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;

bool isNull(List *lista);
bool servidor (Info *p);
Info *cadastro (char *usuario, char *nome, char *id, int vaga, char *placa);
Node *create_node(Info *p);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(List *lista_est,  List *lista_serv, Info *p);
void estacionamento(List *lista, Info *p);
int size(List *lista1, List *lista2);
void print_list(List *lista, List *lista1);