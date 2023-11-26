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
    FILE* file = fopen("grafo3.dot", "r");

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

// //metodo kuratowski - kikibutovski
// bool planar(struct lista** lista) {
//     int i, j;
//     for (i = 0; i < MAX; i++) {
//         if (!is_Empty(lista[i])) {
//             for (j = 0; j < MAX; j++) {
//                 if (i != j && !is_Empty(lista[j])) {
//                     if (!eh_adj(lista[i], 'a' + j)) {
//                         // Se os vértices 'a' + i e 'a' + j não são adjacentes,
//                         // verifique se há um vértice 'a' + k tal que nenhum deles
//                         // seja adjacente a 'a' + k
//                         int k;
//                         for (k = 0; k < MAX; k++) {
//                             if (k != i && k != j) {
//                                 if (!eh_adj(lista[i], 'a' + k) && !eh_adj(lista[j], 'a' + k)) {
//                                     return true;
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     for (i = 0; i < MAX; i++) {
//         if (!is_Empty(lista[i])) {
//             for (j = 0; j < MAX; j++) {
//                 if (i != j && !eh_adj(lista[j], 'a' + i)) {
//                     // Se os vértices 'a' + i e 'a' + j não são adjacentes,
//                     // verifique se há um vértice 'a' + k tal que ambos sejam
//                     // adjacentes a 'a' + k
//                     int k;
//                     for (k = 0; k < MAX; k++) {
//                         if (k != i && k != j) {
//                             if (eh_adj(lista[i], 'a' + k) && eh_adj(lista[j], 'a' + k)) {
//                                 return true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return false; 
// }

bool isK5(struct lista** lista) {
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
bool isK33(struct lista** lista) {
    // Esta é uma implementação muito simplificada e não abrange todos os casos
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
    if (isK5(lista) || isK33(lista)) {
        return false;
    }
    return true;
}

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
    print(ciclo);

    for (int i = 0; i < MAX; i++) {
        if (no_ciclo[i]) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
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

    if (numVertices < 3) {
        printf("O grafo é planar (menos de 3 vertices)\n");
    } else if (planar(lista)) {
        printf("O grafo eh planar\n");
    } else {
        printf("O grafo nao eh planar\n");
    }

    printf("Lista de vertices da face externa:\n");
    lista_vertices_face_externa(lista, numVertices);

    return 0;
}