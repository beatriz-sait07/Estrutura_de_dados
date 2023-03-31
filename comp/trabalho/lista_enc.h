
#include <stdbool.h>

typedef struct _node_simples{
    char letra;
    struct _node_simples *next;
}Node;

typedef struct _lista_simples{
    Node *inicio;
    Node *fim;
    char *token_list;
    int size;    //obrigatório já que necessia-se saber o tamanho
}Lista;
bool isNull(const Lista *list);
Node *Node_create(int val);
Lista *Lista_create();
void add_Last(Lista *l, char val);
void print_List(Lista *l);