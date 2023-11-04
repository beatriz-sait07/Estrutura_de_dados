#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool memoria_desalocada = false;

//----------------------------------- Lista de adjacência ----------------------------------
struct node {
    char val;
    struct node* next;
};

struct lista {
    struct node* begin;
    struct node* end;
    int size;
    char inicio;
};

struct node* Node_Create(char val) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->next = NULL;
    return node;
}

struct lista* List_Create() {
    struct lista* lista = (struct lista*)malloc(sizeof(struct lista));
    lista->begin = NULL;
    lista->end = NULL;
    lista->size = 0;
    return lista;
}

bool is_Empty(const struct lista* lista) {
    return lista->size == 0 || lista->begin == NULL;
}

void insert(struct lista* lista, char val) {
    struct node* new = Node_Create(val);

    if (is_Empty(lista)) {
        lista->begin = lista->end = new;
    } else {
        lista->end->next = new;
        lista->end = lista->end->next;
    }
    lista->size++;
}

void insert1(struct lista *L, char val)
{
    struct node *new = Node_Create(val);
    new->next = L->begin; // Novo Noh aponta pro Noh de inicio
    if(is_Empty(L)){
        L->end = new;
    }
    L->begin = new; // Proximo da lista vira o novo Noh
    L->size++;
}

void print(const struct lista* lista) {
    struct node* p = lista->begin;
    while (p != NULL) {
        printf("%c -> ", p->val);
        p = p->next;
    }
}

// Função para adicionar uma aresta a partir de um arquivo .dot
void addEdge(struct lista** lista, char vetc1, char vetc2) {
    int index1 = vetc1 - 'a'; // Converte o caractere em um índice
    int index2 = vetc2 - 'a'; // Converte o caractere em um índice

    // Adicione vetc2 à lista de vetc1
    insert(lista[index1], vetc2);
    // Adicione vetc1 à lista de vetc2 (já que é um gráfico não direcionado)
    insert(lista[index2], vetc1);
}

void free_List(struct lista** lista, int i) {
    struct node* p = lista[i]->begin;
    struct node* aux = NULL;
    while (p != NULL) {
        aux = p->next;
        free(p);
        p = aux;
    }
    free(lista[i]);
    lista[i] = NULL; // Define a lista como NULL após a desalocação
    memoria_desalocada = true;
}

//------------------------------------- Leitura do arq ---------------------------------------
void leitura(struct lista** lista) {
    FILE* file = fopen("grafo3.dot", "r");

    if (file == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    char line[100]; // Assuma que uma linha do arquivo tem no máximo 100 caracteres

    while (fgets(line, sizeof(line), file)) {
        char vetc1, vetc2;
        if (sscanf(line, " %c -- %c ;", &vetc1, &vetc2) == 2) {
            // Se a linha corresponder ao padrão "vetc1 -- vetc2;", adicione a aresta
            addEdge(lista, vetc1, vetc2);
        }
    }

    fclose(file);
}

//---------------------------------------- FUNCOES-------------------------------
//Verificar se o grafo é regular
bool grafo_reg(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    int grauPadrao = -1; // Grau do primeiro vértice não vazio

    // Encontre o grau do primeiro vértice não vazio (se existir)
    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            grauPadrao = lista[i]->size;
            break;
        }
    }
    // Verifique se todos os vértices têm o mesmo grau do grau padrão
    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i]) && lista[i]->size != grauPadrao) {
            return false; // O grafo não é regular
        }
    }
    return true; // O grafo é regular
}

//-----------------------------------------MAIN-----------------------------------------
int main() {
    struct lista** lista = (struct lista**)malloc(26 * sizeof(struct lista*)); // 26 letras do alfabeto
    int numVertices = 0; // Assumindo que há 26 vértices, 'a' a 'z'
    for (int i = 0; i < 26; i++) {
        lista[i] = List_Create();
    }
    printf("Lista de adjacencia:\n");
    leitura(lista);
    for (int i = 0; i < 26; i++) {
        if (!is_Empty(lista[i])) {
            insert1(lista[i], 'a' + i);
            print(lista[i]);
            numVertices++;
            printf("\n");
        }
    }

    printf("-------------------------------------\n\n");
    printf("Grafo regular: %s\n\n", grafo_reg(lista) ? "Verdadeiro" : "Falso");

    free(lista);
    return 0;
}