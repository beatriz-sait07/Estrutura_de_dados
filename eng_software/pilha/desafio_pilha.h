#include<stdbool.h>

typedef struct _double_node DoubleNode, Node;
typedef struct _double_list DoubleList, List;

Node *create_node(int val);
List *create_list();

void destroy_pilha(List **ref_pilha);
bool _isNull_pilha(const List *pilha);
void add_final_pilha(List *list, int val);
void imprimir_pilha(const List *list);
void merge_pilha(List *pilha, List *pilha1);