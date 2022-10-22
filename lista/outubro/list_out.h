//inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e contar o tam da lista

#include<stdbool.h>

//estruturas
typedef struct cadastro Dados;
typedef struct node_simples Node;
typedef struct linkedlist List;

//funções
bool _isNull(List *lista);
Node *create_node(char *nome, char *rua);
List *create_lista();
void insert_dados(List *list, char *n, char *r);
void print_list(List *lista);


