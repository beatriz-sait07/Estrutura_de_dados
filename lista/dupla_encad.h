#include<stdbool.h>

typedef struct _double_node DoubleNode, Node;
typedef struct _double_list DoubleList, List;

Node *create_node(int val);
List *create_list();

void destroy_dupla(List **ref_list); //fazer
bool _isNull_dupla(const List *list); // fazer
void add_comeco_dupla(List *list, int val);
void add_final_dupla(List *list, int val); // fazer
void imprimir_lista(const List *list);
void imprimir_invert(const List *list); //fazer
void remover_elemento_dupla(List *list, int val); // fazer