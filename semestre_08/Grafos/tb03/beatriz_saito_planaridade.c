#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 26 // Número máximo de vértices

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
    lista[i] = NULL; // Define a lista como NULL após a desalocação
    memoria_desalocada = true;
}

//-------------------------------ARQUIVO---------------------------------//
void leitura(struct lista** lista) {
    FILE* file = fopen("grafo.dot", "r");

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

bool eh_adj(const struct lista* lista, char val) {
    struct node* p = lista->begin;
    while (p != NULL) {
        if (p->val == val) {
            return true;
        }
        p = p->next;
    }
    return false;
}


//-----------------------------PLANARIDADE------------------------------//
bool k5(struct lista** lista) {
    for (int i = 0; i < MAX - 4; i++) {
        for (int j = i + 1; j < MAX - 3; j++) {
            if (!eh_adj(lista[i], 'a' + j)) continue;

            for (int k = j + 1; k < MAX - 2; k++) {
                if (!eh_adj(lista[i], 'a' + k) || !eh_adj(lista[j], 'a' + k)) continue;

                for (int l = k + 1; l < MAX - 1; l++) {
                    if (!eh_adj(lista[i], 'a' + l) || !eh_adj(lista[j], 'a' + l) || !eh_adj(lista[k], 'a' + l)) continue;

                    for (int m = l + 1; m < MAX; m++) {
                        if (eh_adj(lista[i], 'a' + m) && eh_adj(lista[j], 'a' + m) && eh_adj(lista[k], 'a' + m) && eh_adj(lista[l], 'a' + m))
                            return true; // Encontrou um K5
                    }
                }
            }
        }
    }
    return false; // Não encontrou um K5
}

bool k3(struct lista** lista) {
    for (int i = 0; i < MAX - 5; i++) {
        for (int j = i + 1; j < MAX - 4; j++) {
            if (eh_adj(lista[i], 'a' + j)) continue;

            for (int k = j + 1; k < MAX - 3; k++) {
                if (eh_adj(lista[i], 'a' + k) || eh_adj(lista[j], 'a' + k)) continue;
                // Agora, verifique os outros três vértices para formar o K3,3
                for (int l = k + 1; l < MAX - 2; l++) {
                    for (int m = l + 1; m < MAX - 1; m++) {
                        for (int n = m + 1; n < MAX; n++) {
                            if (eh_adj(lista[l], 'a' + m) && eh_adj(lista[l], 'a' + n) && eh_adj(lista[m], 'a' + n))
                                continue; // Os vértices l, m, n formam um K3

                            if (eh_adj(lista[i], 'a' + l) && eh_adj(lista[i], 'a' + m) && eh_adj(lista[i], 'a' + n) &&
                                eh_adj(lista[j], 'a' + l) && eh_adj(lista[j], 'a' + m) && eh_adj(lista[j], 'a' + n) &&
                                eh_adj(lista[k], 'a' + l) && eh_adj(lista[k], 'a' + m) && eh_adj(lista[k], 'a' + n))
                                return true; // Encontrou um K3,3
                        }
                    }
                }
            }
        }
    }
    return false; // Não encontrou um K3,3
}

bool planar(struct lista** lista) {
    if (k5(lista) || k3(lista)) {
        return false;
    }
    return true;
}

//------------------------------FACES-----------------------------------//
void encontrar_ciclo(struct lista** lista, int numVertices, bool visitados[], int v, int parent, struct lista* ciclo, bool no_ciclo[]) {
    visitados[v] = true;
    insert(ciclo, 'a' + v);
    no_ciclo[v] = false;

    struct node* p = lista[v]->begin;
    while (p != NULL) {
        int aux = p->val - 'a';
        if (!visitados[aux]) {
            encontrar_ciclo(lista, numVertices, visitados, aux, v, ciclo, no_ciclo);
        } else if (aux != parent) {
            no_ciclo[aux] = true;
        }
        p = p->next;
    }
}

void lista_vertices_face_externa(struct lista** lista, int numVertices) {
    struct lista* ciclo = List_Create();
    bool visitados[MAX] = {false};
    bool no_ciclo[MAX] = {true};

    encontrar_ciclo(lista, numVertices, visitados, 0, -1, ciclo, no_ciclo);
    //print(ciclo);

    for (int i = 0; i < MAX; i++) {
        if (no_ciclo[i]) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n\n");
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
    printf("\n\n");
    if (numVertices <= 3) {
        printf("O grafo é planar (menor ou igual a 3 vertices)\n\n");
    } else if (planar(lista)) {
        printf("O grafo eh planar\n\n");
    } else {
        printf("O grafo nao eh planar\n\n");
    }

    printf("Lista de vertices da face externa:\n");
    lista_vertices_face_externa(lista, numVertices);


//-------------------------------Free------------------------------//
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

    return 0;
}