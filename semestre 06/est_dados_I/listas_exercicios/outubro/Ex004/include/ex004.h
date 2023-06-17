//inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e contar o tam da lista

#include<stdbool.h>

//estruturas
typedef struct cadastro_struc Dados;
typedef struct node_simples Node;
typedef struct linkedlist List;

//funções
bool isNull(List *lista);
Dados *cadastro (char *nome, char *rua, char *cell);
Node *create_node(Dados *p);
List *create_lista();
void destroy(List **ref_lista);
void insert_dados(Dados *p, List *lista);
int tam_lista(const List *lista);
Dados *busca_elemento(List *lista, char *nome);
void excluir_cliente(List *lista, char *nome);
void print_list(List *lista);
