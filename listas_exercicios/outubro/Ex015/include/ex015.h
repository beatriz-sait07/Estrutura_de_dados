#include<stdbool.h>

typedef struct _node Node;
typedef struct _list List;

Node *Node_create(int val);
List *List_create();

void Node_Destroy(Node **Ref_node);
void List_Destroy(List **Ref_list);
bool is_Empty(const List *lista);
void Add_Last(List *L, int val);

int size_List(const List *L);                   // (a)
void InsertLeft_List(List *L, int val);         // (b)
void Merge_List(List *L1, List *L2);            // (c)
List *Intercalate_List(List *L1, List *L2);     // (d)
List *Copy_List(List *L);                       // (e)

void print_CircularList(const List *L);