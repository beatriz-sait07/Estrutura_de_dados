#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 26 // Número máximo de vértices

int cores[MAX];

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
    new->next = L->begin;
    if(is_Empty(L)){
        L->end = new;
    }
    L->begin = new; 
    L->size++;
}

void print(const struct lista* lista) {
    struct node* p = lista->begin;
    while (p != NULL) {
        printf("%c -> ", p->val);
        p = p->next;
    }
}

void adicio_aresta(struct lista** lista, char vetc1, char vetc2) {
    int index1 = vetc1 - 'a'; 
    int index2 = vetc2 - 'a'; 


    insert(lista[index1], vetc2);
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
    lista[i] = NULL;
    memoria_desalocada = true;
}

//-------------------------------ARQUIVO---------------------------------//
void leitura(struct lista** lista) {
    FILE* file = fopen("grafo1.dot", "r");

    if (file == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        char vetc1, vetc2;
        if (sscanf(line, " %c -- %c ;", &vetc1, &vetc2) == 2) {
            adicio_aresta(lista, vetc1, vetc2);
        }
    }

    fclose(file);
}

//-------------------------------COLORACAO---------------------------------//
void colorirGrafo(struct lista** lista, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        cores[i] = -1;
    }

    cores[0] = 0;

    bool disponiveis[MAX];
    for (int i = 0; i < numVertices; i++) {
        disponiveis[i] = true; 
    }

    for (int u = 1; u < numVertices; u++) {
        struct node* p = lista[u]->begin;
        while (p != NULL) {
            if (cores[p->val - 'a'] != -1) {
                disponiveis[cores[p->val - 'a']] = false; 
            }
            p = p->next;
        }

        int cr;
        for (cr = 0; cr < numVertices; cr++) {
            if (disponiveis[cr]) break; 
        }
        cores[u] = cr; 

        for (int i = 0; i < numVertices; i++) {
            disponiveis[i] = true;
        }
    }
}

//-------------------------------MAIN---------------------------------//
int main(){
    struct lista** lista = (struct lista**)malloc(MAX * sizeof(struct lista*));
    int numVertices = 0;
    for (int i = 0; i < 26; i++) {
        lista[i] = List_Create();
    }
    printf("Lista de adjacencia:\n");
    leitura(lista);
    for (int i = 0; i < MAX; i++) {
        if (!is_Empty(lista[i])) {
            insert1(lista[i], 'a' + i);
            print(lista[i]);
            numVertices++;
            printf("\n");
        }
    }
    
    colorirGrafo(lista, numVertices);
    
    printf("Cores dos vértices:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vértice %c tem cor %d\n", 'a' + i, cores[i]);
    }
}