#include<stdbool.h>

typedef struct _double_node DoubleNode, Node;
typedef struct _double_list Lista_dupla, List;

Node *Node_create(int val);
List *List_create();

void destroy(Lista_dupla **ref_list); //fazer
bool _isNull(const Lista_dupla *list); // fazer
void add_comeco(Lista_dupla *list, int val);
void add_final(Lista_dupla *list, int val); // fazer
void imprimir_lista(const Lista_dupla *list); 
void imprimir_invert(const Lista_dupla *list); //fazer
void remover_elemento(Lista_dupla *list, int val); // fazzer