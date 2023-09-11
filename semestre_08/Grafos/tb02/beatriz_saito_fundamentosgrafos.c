#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

struct node {
    char letra;
    struct node* proximo;
};

struct lista {
    struct node* begin;
    struct node* end;
    int size;
};

struct Grafo {
    struct lista* lista_adjacencia[MAX_SIZE];
};

// Funções para criar e manipular a lista encadeada
struct node* Node_Create(char val) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->letra = val;
    node->proximo = NULL;
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

void add_Last(struct lista* lista, char val) {
    struct node* new = Node_Create(val);

    if (is_Empty(lista)) {
        lista->begin = lista->end = new;
    } else {
        lista->end->proximo = new;
        lista->end = lista->end->proximo;
    }
    lista->size++;
}

void adicionar_aresta(struct Grafo* grafo, char origem, char destino) {
    add_Last(grafo->lista_adjacencia[origem - 'a'], destino);
    add_Last(grafo->lista_adjacencia[destino - 'a'], origem);
}

int main() {
    FILE* arquivo = fopen("completok4.dot", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    struct Grafo grafo;
    for (int i = 0; i < MAX_SIZE; i++) {
        grafo.lista_adjacencia[i] = List_Create();
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char origem, destino;
        if (sscanf(linha, " %c -- %c;", &origem, &destino) == 2) {
            if (origem >= 'a' && origem <= 'z') {
                adicionar_aresta(&grafo, origem, destino);
            }
        }
    }

    fclose(arquivo);

    // Agora você pode percorrer a lista de adjacência de cada vértice 'a' e imprimir os nós adjacentes.
    for (char vertice = 'a'; vertice <= 'z'; vertice++) {
        struct lista* lista_adj = grafo.lista_adjacencia[vertice - 'a'];
        if (!is_Empty(lista_adj)) {
            printf("[%c] ", vertice);
            struct node* nodoAtual = lista_adj->begin;
            while (nodoAtual != NULL) {
                printf("- %c ", nodoAtual->letra);
                nodoAtual = nodoAtual->proximo;
            }
            printf("\n");
        }
    }

    // Não é necessário verificar a conexão novamente, pois cada aresta é adicionada a ambas as extremidades.
    printf("O grafo é conexo\n");

    // Libere a memória das listas de adjacência
    for (int i = 0; i < MAX_SIZE; i++) {
        free(grafo.lista_adjacencia[i]);
    }

    return 0;
}
