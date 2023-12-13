#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TAM 26// Tamanho da lista de adjacência
#define INFINITO 1000000

struct node {
    char *estado;
    int peso;
    struct node *prox;
};

struct lista {
    struct node *inicio;
    int tam;
};

struct node *cria_no(char *estado, int peso) {
    struct node *no = (struct node *)calloc(1, sizeof(struct node));
    no->estado = strdup(estado);
    no->peso = peso;
    no->prox = NULL;
    return no;
}

struct lista *cria_lista() {
    struct lista *l = (struct lista *)calloc(1, sizeof(struct lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

bool vazia(const struct lista *l) {
    return l->tam == 0 || l->inicio == NULL;
}

struct node *busca_estado(struct lista *l, char *origem) {
    struct node *atual = l->inicio;
    while (atual != NULL) {
        if (strcmp(atual->estado, origem) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void inserir(struct lista **l_main, char *origem, char *destino, int peso) {

    int index_origem = -1;
    for (int i = 0; i < TAM; i++) {
        if (strcmp(l_main[i]->inicio->estado, origem) == 0) {
            index_origem = i;
            break;
        }
    }
    if (index_origem == -1) {
        printf("Estado de origem %s não encontrado!\n", origem);
        return;
    }
    struct node *novo_destino = cria_no(destino, peso);
    novo_destino->prox = l_main[index_origem]->inicio->prox;
    l_main[index_origem]->inicio->prox = novo_destino;
    // printf("Destino: %s\n", l_main[index_origem]->inicio->prox->estado);
    l_main[index_origem]->tam++;
}


void leitura(struct lista **l_main, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[200], estado1[3], estado2[3];
    int peso, posicao;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, " %2s -> %2s[label=\"%*d\",weight=\"%d\"]", estado1, estado2, &peso) == 3) {
            //printf("%s -> %s (%d)\n", estado1, estado2, peso);
            inserir(l_main, estado1, estado2, peso);
        }
    }

    fclose(arquivo);
}

/*----------------------------------------------------*/

const char* indice_para_estado(int indice) {
    if (indice < 0 || indice >= TAM) {
        return "Estado inválido"; // Retornar uma mensagem de erro se o índice for inválido
    }

    const char *estados[TAM] = {
        "SP", "RJ", "MG", "ES", "BA", "SE", "AL", "PE", "PB", "RN", 
        "CE", "PI", "MA", "PA", "AP", "AM", "RR", "AC", "RO", "MT", 
        "TO", "GO", "MS", "PR", "SC", "RS"
    };

    return estados[indice]; // Retorna o nome do estado correspondente ao índice
}

void imprimir_caminho(int anterior[], int estado_atual) {
    if (estado_atual == -1) {
        return; 
    }
    imprimir_caminho(anterior, anterior[estado_atual]); // Vai para o estado anterior
    printf("%s ", indice_para_estado(estado_atual)); // Imprime o estado atual
}

int estado_para_indice(char *estado) {
    char *estados[TAM] = {
        "SP", "RJ", "MG", "ES", "BA", "SE", "AL", "PE", "PB", "RN", 
        "CE", "PI", "MA", "PA", "AP", "AM", "RR", "AC", "RO", "MT", 
        "TO", "GO", "MS", "PR", "SC", "RS"
    };

    for (int i = 0; i < TAM; i++) {
        if (strcmp(estados[i], estado) == 0) {
            return i;
        }
    }

    return -1; // Caso o estado não seja encontrado
}

void dijkstra(struct lista **l_main, int origem, int destino) {
    int distancias[TAM];
    bool visitado[TAM];
    int anterior[TAM]; // Para rastrear o caminho

    // Inicialização
    for (int i = 0; i < TAM; i++) {
        distancias[i] = INFINITO;
        visitado[i] = false;
        anterior[i] = -1; // -1 indica que ainda não temos um caminho
    }

    distancias[origem] = 0;

    for (int i = 0; i < TAM - 1; i++) {
        int u = -1;

        // Encontrar o estado não visitado com a menor distância
        for (int j = 0; j < TAM; j++) {
            if (!visitado[j] && (u == -1 || distancias[j] < distancias[u])) {
                u = j;
            }
        }

        visitado[u] = true;

        struct node *atual = l_main[u]->inicio->prox;
        while (atual != NULL) {
            int v = estado_para_indice(atual->estado); 
            int peso = atual->peso;

            // Atualizar a distância se for menor
            if (distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                anterior[v] = u;
            }

            atual = atual->prox;
        }
    }

    printf("Menor caminho de %s para %s: ", indice_para_estado(origem), indice_para_estado(destino));
    imprimir_caminho(anterior, destino);
    printf("\n");
}


int main() {
    struct lista **l_main = (struct lista **)malloc(TAM * sizeof(struct lista *));

    for (int i = 0; i < TAM; i++) {
        l_main[i] = cria_lista();
        char *estado;
        switch (i) {
            case 0:
                estado = "SP";
                break;
            case 1:
                estado = "RJ";
                break;
            case 2:
                estado = "MG";
                break;
            case 3:
                estado = "ES";
                break;
            case 4:
                estado = "BA";
                break;
            case 5:
                estado = "SE";
                break;
            case 6:
                estado = "AL";
                break;
            case 7:
                estado = "PE";
                break;
            case 8:
                estado = "PB";
                break;
            case 9:
                estado = "RN";
                break;
            case 10:
                estado = "CE";
                break;
            case 11:
                estado = "PI";
                break;
            case 12:
                estado = "MA";
                break;
            case 13:
                estado = "PA";
                break;
            case 14:
                estado = "AP";
                break;
            case 15:
                estado = "AM";
                break;
            case 16:
                estado = "RR";
                break;
            case 17:
                estado = "AC";
                break;
            case 18:
                estado = "RO";
                break;
            case 19:
                estado = "MT";
                break;
            case 20:
                estado = "TO";
                break;
            case 21:
                estado = "GO";
                break;
            case 22:
                estado = "MS";
                break;
            case 23:
                estado = "PR";
                break;
            case 24:
                estado = "SC";
                break;
            case 25:
                estado = "RS";
                break;
            default:
                estado = "ERRO";
                break;
        }
        l_main[i]->inicio = cria_no(estado, 0);
    }

    leitura(l_main, "entrada.dot");


    printf("\n------------------extracao de dados----------------\n");
    for (int i = 0; i < TAM; i++) {
        struct node *atual = l_main[i]->inicio;
        printf("Lista de adjacência do estado %s:\n", atual->estado);
        while (atual->prox != NULL) {
            printf("-> Destino: %s, Peso: %d\n", atual->prox->estado, atual->prox->peso);
            atual = atual->prox;
        }
        printf("\n");
    }


    char origem[3], destino[3];
    printf("-------------------------menor caminho------------------\n");
    printf("Digite o estado de origem: ");
    scanf("%s", origem);
    printf("\nDigite o estado de destino: ");
    scanf("%s", destino);

    int i=0;
    while(origem[i] != '\0' && destino[i] != '\0'){
        origem[i] = toupper(origem[i]);
        destino[i] = toupper(destino[i]);
        i++;
    }

    int i_origem = estado_para_indice(origem), i_destino = estado_para_indice(destino);
    dijkstra(l_main, i_origem, i_destino);
    return 0;
}