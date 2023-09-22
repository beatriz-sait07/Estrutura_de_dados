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
//01) Verificar se o grafo é conexo
void DFS(struct lista** lista, int vertex, bool* visited) {
    visited[vertex] = true;

    struct node* atual = lista[vertex]->begin;
    while (atual != NULL) {
        int aux = atual->val - 'a';
        if (!visited[aux]) {
            DFS(lista, aux, visited);
        }
        atual = atual->next;
    }
}

bool isConexo(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    // Inicialize um array de booleanos para marcar os vértices visitados
    bool visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    int p = -1; // Encontre o primeiro vértice não nulo (se existir)
    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            p = i;
            break;
        }
    }

    // Se não houver vértices não nulos, o grafo é trivialmente conexo
    if (p == -1) {
        return true;
    }

    // Execute uma DFS a partir do primeiro vértice não nulo
    DFS(lista, p, visited);

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
        struct node* atual = lista[i]->begin;
        while (atual != NULL) {
            if (atual->val == 'a' + i) {
                return true; // Loop encontrado
            }
            atual = atual->next;
        }
    }
    return false; // Não há loops
}

//03) Verificar se o grafo tem arestas paralelas
bool ArestasParalelas(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        struct node* atual = lista[i]->begin;
        while (atual != NULL) {
            int aux = atual->val - 'a';
            struct node* check = atual->next; // Comece a verificação a partir do próximo nó

            while (check != NULL) {
                if (check->val == atual->val) {
                    return true; // Aresta paralela encontrada
                }
                check = check->next;
            }
            atual = atual->next;
        }
    }
    return false; // Não há arestas paralelas
}

//04) Calcular o grau de cada vértice
void GrauVertices(struct lista** lista, int grau[]) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'

    for (int i = 0; i < numVertices; i++) {
        grau[i] = 0; // Inicialize o grau do vértice como 0

        struct node* atual = lista[i]->begin;
        while (atual != NULL) {
            grau[i]++; // Incrementa o grau para cada aresta incidente
            atual = atual->next;
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
        struct node* atual = lista[i]->begin;
        while (atual != NULL) {
            int aux = atual->val - 'a';
            int count = 0; // Contador para contar as arestas entre o par de vértices

            // Percorre novamente a lista para contar as arestas entre o mesmo par de vértices
            struct node* check = lista[i]->begin;
            while (check != NULL) {
                if (check->val == atual->val) {
                    count++;
                }
                check = check->next;
            }

            if (count > 1) {
                return true; // Mais de uma aresta entre o mesmo par de vértices
            }

            atual = atual->next;
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
                struct node* atual = lista[i]->begin;
                while (atual != NULL) {
                    if (atual->val == 'a' + j) {
                        arestaExiste = true;
                        break;
                    }
                    atual = atual->next;
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

//10) Verificar se o grafo é regular
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

//11) Gerar passeios
void gerando_passeios(struct lista** lista, char go, bool* visited, char* caminho, int index, int numVertices) {
    visited[go - 'a'] = true; // mantem o controlo dos vértices visitados 
    caminho[index++] = go; 
    if (index == numVertices) { 
        for (int i = 0; i < numVertices; i++) {
            printf("%c -> ", caminho[i]);
        }
        printf("\n");
    } else {
        struct node* atual = lista[go - 'a']->begin;
        while (atual != NULL) {
            char nextVertex = atual->val;
            if (!visited[nextVertex - 'a']) {
                gerando_passeios(lista, nextVertex, visited, caminho, index, numVertices);
            }
            atual = atual->next;
        }
    }
    
    visited[go - 'a'] = false; 
}
void gerando_passeio_total(struct lista** lista, char start, char end, bool* visited, char* path, int index) {
    visited[start - 'a'] = true; // Marca o vértice atual como visitado
    path[index++] = start; // Adiciona o vértice atual ao caminho

    if (start == end) { // Se chegarmos ao vértice de destino, imprime o caminho
        for (int i = 0; i < index; i++) {
            printf("%c -> ", path[i]);
        }
        printf("\n");
    } else {
        struct node* current = lista[start - 'a']->begin;
        while (current != NULL) {
            char nextVertex = current->val;
            if (!visited[nextVertex - 'a']) {
                gerando_passeio_total(lista, nextVertex, end, visited, path, index);
            }
            current = current->next;
        }
    }

    visited[start - 'a'] = false; // Desmarca o vértice atual como visitado para explorar outros caminhos
}

//12) Gerar todos os caminhos entre dois vértices
// Função auxiliar para imprimir uma trilha
void printTrilha(char* trilha, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c -> ", trilha[i]);
    }
    printf("\n");
}

// Função recursiva para encontrar trilhas em um grafo
void generateTrilhas(struct lista** lista, char currentVertex, bool* visited, char* trilha, int index, int numVertices) {
    visited[currentVertex - 'a'] = true;
    trilha[index++] = currentVertex;

    if (index >= 2) {
        // Verifica se a trilha contém um ciclo
        if (visited[currentVertex - 'a'] && index > 2 && trilha[index - 1] == trilha[0]) {
            visited[currentVertex - 'a'] = false;
            return;
        }
    }

    if (index == numVertices) {
        printTrilha(trilha, numVertices);
    } else {
        struct node* atual = lista[currentVertex - 'a']->begin;
        while (atual != NULL) {
            char nextVertex = atual->val;
            if (!visited[nextVertex - 'a']) {
                generateTrilhas(lista, nextVertex, visited, trilha, index, numVertices);
            }
            atual = atual->next;
        }
    }

    visited[currentVertex - 'a'] = false;
}

// Função para imprimir todas as trilhas possíveis em um grafo
void encontrar_trilha(struct lista** lista, int numVertices) {
    bool* visited = (bool*)malloc(sizeof(bool) * numVertices);
    char* trilha = (char*)malloc(sizeof(char) * numVertices);
    memset(visited, false, sizeof(bool) * numVertices);

    for (int i = 0; i < numVertices; i++) {
        generateTrilhas(lista, 'a' + i, visited, trilha, 0, numVertices);
    }

    free(visited);
    free(trilha);
}

//13) Gerar todos os ciclos
bool Caminho(const char* path, char vertex) {
    int length = strlen(path);
    for (int i = 0; i < length; i++) {
        if (path[i] == vertex) {
            return true;
        }
    }
    return false;
}

// Função recursiva para encontrar e imprimir todos os circuitos a partir de um vértice
void encontrou_seu_caminho(struct lista** lista, char start, char current, char* path, int depth) {
    // Adicione o vértice atual ao caminho
    path[depth] = current;
    depth++;

    // Verifique se encontramos um circuito completo
    if (depth > 2 && current == start) {
        // Imprima o circuito encontrado
        printf("Circuito: ");
        for (int i = 0; i < depth; i++) {
            printf("%c ", path[i]);
        }
        printf("\n");
    } else {
        // Continue a busca em profundidade a partir do vértice atual
        struct node* neighbor = lista[current - 'a']->begin;
        while (neighbor != NULL) {
            if (!Caminho(path, neighbor->val)) {
                encontrou_seu_caminho(lista, start, neighbor->val, path, depth);
            }
            neighbor = neighbor->next;
        }
    }

    // Remova o vértice atual do caminho antes de retroceder
    depth--;
    path[depth] = '\0';
}

// Função para encontrar e imprimir todos os circuitos em um grafo direcionado
void caminho_total(struct lista** lista) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'
    char* path = (char*)malloc(numVertices * sizeof(char));

    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            for (int j = 0; j < numVertices; j++) {
                path[j] = '\0'; // Inicialize o caminho com caracteres nulos
            }
            encontrou_seu_caminho(lista, 'a' + i, 'a' + i, path, 0);
        }
    }

    free(path);
}

//14) Função de interface para gerar todos os caminhos entre dois vértices
void gerar_todos_os_caminhos(struct lista** lista, char start, char end) {
    int numVertices = 26; // Assumindo que há 26 vértices, 'a' a 'z'
    bool* visited = (bool*)malloc(numVertices * sizeof(bool));
    char* path = (char*)malloc(numVertices * sizeof(char));

    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    printf("Todos os caminhos entre %c e %c:\n", start, end);
    gerando_passeio_total(lista, start, end, visited, path, 0);

    free(visited);
    free(path);
}

void encontrando_caminhos(struct lista** lista, bool* visited, char* path, int* pathLength, char currentVertex, char targetVertex) {
    int currentIndex = currentVertex - 'a';
    visited[currentIndex] = true;
    path[(*pathLength)++] = currentVertex;

    if (currentVertex == targetVertex) {
        // Imprime o caminho encontrado
        for (int i = 0; i < *pathLength; i++) {
            printf("%c", path[i]);
            if (i < *pathLength - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        struct node* current = lista[currentIndex]->begin;
        while (current != NULL) {
            char nextVertex = current->val;
            int nextIndex = nextVertex - 'a';
            if (!visited[nextIndex]) {
                encontrando_caminhos(lista, visited, path, pathLength, nextVertex, targetVertex);
            }
            current = current->next;
        }
    }

    visited[currentIndex] = false;
    (*pathLength)--;
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
    printf("-------------------------------------\n");
    printf("01) O grafo eh %s\n", isConexo(lista) ? "conexo" : "nao conexo");
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

    printf("\n10) O grafo %s regular\n", grafo_reg(lista) ? "eh" : "NAO eh");


    printf("\n11) Passeios:\n");
    bool visited[26] = { false };
    char caminho[26];
    for (int i = 0; i < numVertices; i++) {
        if (!is_Empty(lista[i])) {
            
            gerando_passeios(lista, 'a' + i, visited, caminho, 0, numVertices);
            printf("---------------------\n");
        }
    }

    printf("\n12) Trilhas possíveis no grafo:\n");
    encontrar_trilha(lista, numVertices);
    
    printf("\n14) Caminhos:\n");
    char startVertex = '\0', endVertex = '\0';   // Vértice de fim

    for (int i = 0; i < 26; i++) {
        if (!is_Empty(lista[i])) {
            if (startVertex == '\0') {
                startVertex = 'a' + i; // Encontre o primeiro vértice não vazio
            }
            endVertex = 'a' + i; // O último vértice não vazio será atualizado a cada iteração
        }
    }

    if (startVertex != '\0' && endVertex != '\0') {
        printf("Caminhos entre %c - %c:\n", startVertex, endVertex);
        gerar_todos_os_caminhos(lista, startVertex, endVertex);
    } else {
        printf("Não foi possível encontrar vértices de início e fim.\n");
    }

    
    printf("\n---------------------\n");
    caminho_total(lista);

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