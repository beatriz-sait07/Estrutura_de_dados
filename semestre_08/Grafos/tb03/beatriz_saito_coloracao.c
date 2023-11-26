#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 26 // Número máximo de vértices

int cores[MAX];

bool disponiveis[MAX];


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
    FILE* file = fopen("grafo5.dot", "r");

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

bool isSafe(int v, struct lista** lista, int color[], int c) {
    struct node* p = lista[v]->begin->next; // Ignora o primeiro nó, pois é o próprio vértice
    while (p != NULL) {
        if (color[p->val - 'a'] == c) return false;
        p = p->next;
    }
    return true;
}

bool graphColoringUtil(struct lista** lista, int m, int color[], int v, int numVertices) {
    if (v == numVertices) return true; // Todos os vértices estão coloridos

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, lista, color, c)) {
            color[v] = c;

            if (graphColoringUtil(lista, m, color, v + 1, numVertices)) return true;

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void colorirGrafo(struct lista** lista, int numVertices) {
    int color[MAX];
    for (int i = 0; i < numVertices; i++) color[i] = 0;

    int m = numVertices; // Número máximo de cores. Você pode ajustar este valor conforme necessário
    if (!graphColoringUtil(lista, m, color, 0, numVertices)) {
        printf("Solução não existe");
        return;
    }

    // Print das cores
    printf("Cores dos vértices:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vértice %c tem cor %d\n", 'a' + i, color[i]);
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

    //---------------------------Free--------------------------------//
    for (int i = 0; i < 26; i++) {
        if (!is_Empty(lista[i])) {
            free_List(lista, i);
        } else {
            free(lista[i]);
        }
    }
    
    free(lista);

    if(memoria_desalocada == true) return printf("lista totalmente desalocada\n\n");
    else return printf("erro ao desalocar a memoria!\n\n");
}