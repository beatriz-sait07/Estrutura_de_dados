#include<stdbool.h>

typedef struct _circ_node CircNode, Node;
typedef struct _circ_list CircList, List;

Node *Node_create(int val);
CircList *List_create();

void Node_Destroy(CircNode **Ref_node);
void List_Destroy(CircList **Ref_list);
bool is_Empty(const CircList *lista);
void Add_Last(CircList *L, int val);

int size_List(const CircList *L);                   // (a)
void InsertLeft_List(CircList *L, int val);         // (b)
void Merge_List(CircList *L1, CircList *L2);        // (c)
List *Intercalate_List(CircList *L1, CircList *L2); // (d)
List *Copy_List(CircList *L);                       // (e)

void print_CircularList(const CircList *L);