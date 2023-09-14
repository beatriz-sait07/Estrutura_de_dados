#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool memoria_desalocada = false;

struct node {
    char val;
    struct node* next;
};

struct lista {
    struct node* begin;
    struct node* end;
    int size;
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

void add_Last(struct lista* lista, char val) {
    struct node* new = Node_Create(val);

    if (is_Empty(lista)) {
        lista->begin = lista->end = new;
    } else {
        lista->end->next = new;
        lista->end = lista->end->next;
    }
    lista->size++;
}

void print(const struct lista* lista) {
    struct node* p = lista->begin;
    while (p != NULL) {
        printf("%c -> ", p->val);
        p = p->next;
    }
}

// Função para adicionar uma aresta a partir de um arquivo .dot
void addEdge(struct lista** lista, char vertex1, char vertex2) {
    int index1 = vertex1 - 'a'; // Converte o caractere em um índice
    int index2 = vertex2 - 'a'; // Converte o caractere em um índice

    // Adicione vertex2 à lista de vertex1
    add_Last(lista[index1], vertex2);
    // Adicione vertex1 à lista de vertex2 (já que é um gráfico não direcionado)
    add_Last(lista[index2], vertex1);
}

void grafo(struct lista** lista) {
    FILE* file = fopen("grafo2.dot", "r");

    if (file == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    char line[100]; // Assuma que uma linha do arquivo tem no máximo 100 caracteres

    while (fgets(line, sizeof(line), file)) {
        char vertex1, vertex2;
        if (sscanf(line, " %c -- %c ;", &vertex1, &vertex2) == 2) {
            // Se a linha corresponder ao padrão "vertex1 -- vertex2;", adicione a aresta
            addEdge(lista, vertex1, vertex2);
        }
    }

    fclose(file);
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
//------------------------------------- FIM DA LISTA ---------------------------------------

// Função auxiliar DFS para verificar a conexidade do grafo

//01) Verificar se o grafo é conexo
void DFS(struct lista** lista, int vertex, bool* visited) {
    visited[vertex] = true;

    struct node* current = lista[vertex]->begin;
    while (current != NULL) {
        int neighbor = current->val - 'a';
        if (!visited[neighbor]) {
            DFS(lista, neighbor, visited);
        }
        current = current->next;
    }
}

bool isConexo(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    // Inicialize um array de booleanos para marcar os vértices visitados
    bool visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Encontre o primeiro vértice não nulo (se existir)
    int startVertex = -1;
    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            startVertex = i;
            break;
        }
    }

    // Se não houver vértices não nulos, o grafo é trivialmente conexo
    if (startVertex == -1) {
        return true;
    }

    // Execute uma DFS a partir do primeiro vértice não nulo
    DFS(lista, startVertex, visited);

    // Verifique se todos os vértices foram visitados
    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i]) && !visited[i]) {
            return false; // Não é conexo
        }
    }

    return true; // É conexo
}

//02) Verificar se o grafo tem loops
bool loop(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        struct node* current = lista[i]->begin;
        while (current != NULL) {
            if (current->val == 'a' + i) {
                return true; // Loop encontrado
            }
            current = current->next;
        }
    }
    return false; // Não há loops
}

//03) Verificar se o grafo tem arestas paralelas
bool ArestasParalelas(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        struct node* current = lista[i]->begin;
        while (current != NULL) {
            int neighbor = current->val - 'a';
            struct node* check = current->next; // Comece a verificação a partir do próximo nó

            while (check != NULL) {
                if (check->val == current->val) {
                    return true; // Aresta paralela encontrada
                }
                check = check->next;
            }
            current = current->next;
        }
    }
    return false; // Não há arestas paralelas
}

//04) Calcular o grau de cada vértice
void GrauVertices(struct lista** lista, int grau[]) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        grau[i] = 0; // Inicialize o grau do vértice como 0

        struct node* current = lista[i]->begin;
        while (current != NULL) {
            grau[i]++; // Incrementa o grau para cada aresta incidente
            current = current->next;
        }
    }
}

//05) Calcular o grau mínimo e máximo do grafo
void calcularGrauMinimoMaximo(struct lista** lista) {
    int numVertices = 0; // Inicializa o número de vértices com zero
    // Calcula o número de vértices com base nas listas de adjacência
    for (int i = 0; i < 26; i++) { // Assumindo 26 letras do alfabeto
        if (!is_Empty(lista[i])) {
            numVertices++;
        }
    }
    int grauMinimo = numVertices; // Inicializa o grau mínimo com o número máximo possível
    int grauMaximo = 0;
    for (int i = 0; i < numVertices; i++) { // Assumindo 26 letras do alfabeto
        int grauVertice = 0;
        struct node* p = lista[i]->begin;
        while (p != NULL) {
            grauVertice++;
            p = p->next;
        }
        // Atualiza o grau mínimo e máximo
        if (grauVertice < grauMinimo) {
            grauMinimo = grauVertice;
        }
        if (grauVertice > grauMaximo) {
            grauMaximo = grauVertice;
        }
    }
    // Imprime o grau mínimo e máximo para cada vértice
    // for (int i = 0; i < numVertices; i++) { // Assumindo 26 letras do alfabeto
    //     int grauVertice = 0;
    //     struct node* p = lista[i]->begin;
    //     while (p != NULL) {
    //         grauVertice++;
    //         p = p->next;
    //     }
    //     if (grauVertice > 0) {
    //         printf("Vértice %c: Grau %d\n", 'a' + i, grauVertice);
    //     }
    // }
    // Imprime o grau mínimo e máximo do grafo

    printf("\n05) Grau mínimo do grafo: %d\n", grauMinimo);
    printf("    Grau máximo do grafo: %d\n", grauMaximo);
}

//06) Calcular a ordem do grafo
bool isSimples(struct lista** lista) {
    for (int i = 0; i < 26; i++) {
        struct node* p = lista[i]->begin;
        while (p != NULL) {
            int vizinho = p->val;

            // Verifique se há um laço (aresta para o próprio vértice)
            if (vizinho == i) {
                return false;
            }

            // Verifique se há múltiplas arestas entre os mesmos vértices
            struct node* q = p->next;
            while (q != NULL) {
                if (q->val == vizinho) {
                    return false;
                }
                q = q->next;
            }

            p = p->next;
        }
    }
    return true; // O grafo é simples
}

//07) Calcular a ordem do grafo
int ordemDoGrafo(struct lista** lista) {
    int ordem = 0;
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            ordem++;
        }
    }
    return ordem;
}

//08) Verificar se o grafo é multigrafo
bool isMultigrafo(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        struct node* current = lista[i]->begin;
        while (current != NULL) {
            int neighbor = current->val - 'a';
            int count = 0; // Contador para contar as arestas entre o par de vértices

            // Percorre novamente a lista para contar as arestas entre o mesmo par de vértices
            struct node* check = lista[i]->begin;
            while (check != NULL) {
                if (check->val == current->val) {
                    count++;
                }
                check = check->next;
            }

            if (count > 1) {
                return true; // Mais de uma aresta entre o mesmo par de vértices
            }

            current = current->next;
        }
    }
    return false; // Não há múltiplas arestas entre o mesmo par de vértices
}

//09) Verificar se o grafo é completo
bool completo(struct lista** lista) {
    int numVertices = 4; // No seu exemplo, há 4 vértices (a, b, c, d)
    bool grafoCompleto = true; // Assumimos inicialmente que o grafo é completo

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j) {
                bool arestaExiste = false;
                struct node* current = lista[i]->begin;
                while (current != NULL) {
                    if (current->val == 'a' + j) {
                        arestaExiste = true;
                        break;
                    }
                    current = current->next;
                }

                if (!arestaExiste) {
                    grafoCompleto = false; // O grafo não é completo
                    break; // Saia do loop interno
                }
            }
        }
        if (!grafoCompleto) {
            break; // Saia do loop externo se o grafo não for completo
        }
    }

    return grafoCompleto;
}

bool isGrafoRegular(struct lista** lista) {
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

void generatePasseios(struct lista** lista, char start, bool* visited, char* path, int index, int numVertices) {
    visited[start - 'a'] = true;
    path[index++] = start;

    if (index == numVertices) { // Se o passeio estiver completo (5 vértices no total)
        for (int i = 0; i < numVertices; i++) {
            printf("%c ", path[i]);
        }
        printf("\n");
    } else {
        struct node* current = lista[start - 'a']->begin;
        while (current != NULL) {
            char nextVertex = current->val;
            if (!visited[nextVertex - 'a']) {
                generatePasseios(lista, nextVertex, visited, path, index, numVertices);
            }
            current = current->next;
        }
    }

    visited[start - 'a'] = false; // Marcar o vértice como não visitado para outros passeios
}

//-----------------------------------------MAIN-----------------------------------------
int main() {
    struct lista** lista = (struct lista**)malloc(26 * sizeof(struct lista*)); // 26 letras do alfabeto
    int numVertices = 0; // Assumindo que há 26 vértices, 'a' a 'z'
    for (int i = 0; i < 26; i++) {
        lista[i] = List_Create();
    }
    printf("Lista de adjacencia:\n");
    grafo(lista);
    for (int i = 0; i < 26; i++) {
        if (!is_Empty(lista[i])) {
            printf("%c: ", 'a' + i);
            print(lista[i]);
            numVertices++;
            printf("\n");
        }
    }
    printf("--------------------------------------");
    printf("\n\n01) O grafo eh %s\n", isConexo(lista) ? "conexo" : "nao conexo");
    printf("\n02) O grafo %s loops\n", loop(lista) ? "tem" : "nao tem");
    printf("\n03) O grafo %s arestas paralelas\n", ArestasParalelas(lista) ? "tem" : "nao tem");

    int grau[26]; // Array para armazenar os graus dos vértices
    GrauVertices(lista, grau);
    printf("\n04) Grau dos vertices:\n");
    for (int i = 0; i < 26; i++) {
        if (!is_Empty(lista[i])) {
            printf("Vertice %c: %d\n", 'a' + i, grau[i]);
        }
    }

    calcularGrauMinimoMaximo(lista);

    printf("\n06) A ordem do grafo eh: %d\n", ordemDoGrafo(lista));

    printf("\n07) O grafo %s\n", isSimples(lista) ? "eh Simples" : "NAO Eh Simples");

    printf("\n08) O grafo %s multigrafo\n", isMultigrafo(lista) ? "eh" : "NAO eh");

    printf("\n09) O grafo %s completo.\n", completo(lista) ? "eh" : "nao eh");

    printf("\n10) O grafo %s regular\n", isGrafoRegular(lista) ? "eh" : "NAO eh");

    printf("\n11) Passeios:\n");
    bool visited[26] = { false };
    char path[26];

    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            printf("%c:\n", 'a' + i);
            generatePasseios(lista, 'a' + i, visited, path, 0, numVertices);
            printf("\n");
        }
    }
    
    //-----------------Free-----------------
    for (int i = 0; i < 26; i++) {
        if (!is_Empty(lista[i])) {
            free_List(lista, i);
        } else {
            free(lista[i]);
        }
    }
    free(lista);
    return 0;
}
