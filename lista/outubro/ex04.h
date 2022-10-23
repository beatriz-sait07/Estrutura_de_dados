//inserir, remover, listar, pesquisar, gravar em ficheiro, ler de ficheiro, e contar o tam da lista

#include<stdbool.h>

//estruturas
typedef struct cadastro_struc Dados;
typedef struct node_simples Node;
typedef struct linkedlist List;

//funções
bool isNull(List *lista);
//void cadastro (Dados *p, char nome[], char rua[], char cell[]);
void cadastro (Dados *p, int num1, int num2, int md);
Node *create_node(Dados *p);
List *create_lista();
void insert_dados(List *lista, Dados *p);
void print_list(List *lista);


