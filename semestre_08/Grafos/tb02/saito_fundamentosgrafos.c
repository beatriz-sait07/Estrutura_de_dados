#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------LISTA ENCADEADA---------------------------------------//
struct node {
    char val;
    struct node* next;
};

struct lista {
    struct node* begin;
    struct node* end;
    int size;
};

// Funções para criar e manipular a lista encadeada
struct node *Node_Create(char val) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->next = NULL;
    return node;
}

struct lista *List_Create() {
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

//------------------------------------------LEITURA DO ARQUIVO------------------------------------------//
void grafo(struct lista** lista) {
    FILE* file = fopen("completok4.dot", "r");

    if (file == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    int i = -1;
    char aux = fgetc(file);

    while (aux != EOF) {
        if (aux == '{') {
            aux = fgetc(file);
            while (aux != '}') {
                if (aux == '-') {
                    aux = fgetc(file);  
                    continue;
                } else if (aux != ' ' && ((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z'))) {
                    add_Last(lista[i], aux);
                    aux = fgetc(file);
                    continue;
                } else if (aux == '\n') {
                    i++;               
                    lista[i] = List_Create();
                    aux = fgetc(file); 
                } else {
                    aux = fgetc(file);
                }
            }
        } else {
            aux = fgetc(file); 
        }
    }

    fclose(file);
}



int main() {
    struct lista** lista = (struct lista**)malloc(10 * sizeof(struct lista*));
    for (int i = 0; i < 10; i++) {
        lista[i] = List_Create();
    }
    grafo(lista);
    for (int i = 0; i < 10; i++) {
        printf("|%d| ", i);
        print(lista[i]);
        printf("\n");
        free(lista[i]); // Libera a memória da lista individual
    }
    free(lista); // Libera a memória do array de ponteiros para listas
    return 0;
}
