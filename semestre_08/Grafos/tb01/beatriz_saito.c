#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//-------------------------------------------LISTA--------------------------------------------------------------------------------
struct node {
    bool masc, infc;
    struct node *next;
};

struct list {
    long int size;
    struct node *begin;    
};

struct node *Node_create(bool mask, bool infctd) {
    struct node *Node = (struct node*)calloc(1, sizeof(struct node));
    Node->masc = mask;
    Node->infc = infctd;
    Node->next = NULL;
    return Node;
}

struct list *List_create() {
    struct list *l = (struct list*)calloc(1, sizeof(struct list));
    l->size = 0;
    l->begin = NULL;
    return l;
}

bool isNull(struct list *l) {
    return l->size == 0;
}

void insert(struct list *l, bool mask, bool infctd) {
    struct node *n = Node_create(mask, infctd);
    if (isNull(l)) {
        l->begin = n;
    } else {
        struct node *aux = l->begin;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = n;
    }
    l->size++;
}

void print_list(const struct list *l) {
    struct node *aux = l->begin;
    if (aux != NULL) {
        printf("INICIO -> ");
        while (aux != NULL) {
            printf("%c -> ", aux->infc);
            aux = aux->next;
        }
        printf("NULL\n");
    } else {
        printf("A lista está vazia!\n");
    }

    printf("Tamanho = %ld\n", l->size);
}


void free_list(struct list **l) {
    struct list *lista = *l;
    struct node *p = lista->begin;
    struct node *aux = NULL;
    while (p != NULL) {
        aux = p->next;
        free(p);
        p = aux;
    }
    free(lista);
    *l = NULL;
    printf("Lista liberada com sucesso!\n");
}

//------------------------------------------LEITURA-----------------------------------------------------------------------------
void leitura_arq(struct list **lista) {
    FILE *arq;
    char caracter;
    int i = 0;

    arq = fopen("infectado.csv", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    while ((caracter = fgetc(arq)) != EOF) {
        printf("%c", caracter);
    }

    fclose(arq);
}


// ------------------------------------------MAIN--------------------------------------------------------------------------------
int main() {
    int num_lists = 8;
    struct list **lista = (struct list **)malloc(num_lists * sizeof(struct list *));
    
    // Verifique se a alocação de memória foi bem-sucedida
    if (lista == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    for (int i = 0; i < num_lists; i++) {
        lista[i] = List_create();  // Inicialize cada lista no array
    }

    leitura_arq(lista);

    // Libere a memória de cada lista
    /*for (int i = 0; i < num_lists; i++) {
        free_list(&lista[i]);
    }*/
    
    free(lista);  // Libere o array de ponteiros para listas

    return 0;
}
