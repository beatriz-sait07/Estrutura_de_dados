#include <stdbool.h>

typedef struct _node_simples{
    char letra;
    struct _node_simples *next;
}Node;

typedef struct _lista_simples{
    Node *inicio;
    Node *fim;
    char *token_list;
    char *operador; //nao sei se irei usar
    char **identificador; // nao sei se irei usar
    char **erro; //nao sei se irei usar
    int size;
}Lista;
bool isNull(const Lista *list);
Node *Node_create(int val);
Lista *Lista_create();
void add_Last(Lista *l, char val);
void print_List(Lista *l);