
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define TAM 8

//-------------------------------LISTA ENCADEADA---------------------------------//
struct node{
    char val;
    struct node *next;
};
struct lista{
    struct node *begin;
    struct node *end;
    char pal[30];
    int porcent;
    int size;
};
struct node *Node_Create(char val)
{
    struct node *node = (struct node *)calloc(1, sizeof(struct node)); //Alocando o No dinamicamente
    node->val = val; // Atribuindo o parametro passado 
    node->next = NULL; // Atribuindo nulo ao proximo elemento de um No recem criado

    return node;
}
struct lista *List_Create()
{
    struct lista *lista = (struct lista*)calloc(1, sizeof(struct lista)); // Alocando a lista dinamicamente
    lista->begin = NULL; // Atribuindo Nulo ao ponteiro pro inicio de uma lista recem criada
    lista->end = NULL; // Atribuindo Nulo ao ponteiro pro final de uma lista recem criada
    lista->size = 0;

    return lista;
}
bool is_Empty(const struct lista *lista)
{
    return lista->size == 0;
}
void add_Last(struct lista *lista, char val)
{
    struct node *new = Node_Create(val);

    //Se a lista estiver vazia
    if(is_Empty(lista)){
        lista->begin = lista->end = new;
    }else{
        lista->end->next = new; // Proximo elemento do ultimo Node aponta pro novo
        lista->end = lista->end->next; // O novo Node passa a ser o End
    }
    lista->size++;
}
void print(const struct lista *lista)
{
    struct node *p = lista->begin;
    //Enquanto P apontar para um no existente
    while(p != NULL){
        printf("|%c|", p->val);
        p = p->next;
    }
}

//-----------------------------------------LEITURA DO ARQUIVO-----------------------------------------//
void leitura_arq(struct lista **lista){
    FILE *file;
    file = fopen("grafos.csv", "r");
    if(file == NULL){
        printf("Erro de abertura do arquivo!");
        exit(1);
    }

    char line[50];
    int i = 0;
    lista[i] = List_Create();

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            int value;
            value = token[0];
            add_Last(lista[i], value);
            token = strtok(NULL, ",");
        }
        i++;
        lista[i] = List_Create();
    }
}
//-------------------------------TRANSFORMANDO EM BOOLEANO-----------------------------------//
void replace(struct lista **lista) {
    int i = 0;
    while (lista[i]->begin != NULL) {
        struct node *aux = lista[i]->begin;

        while (aux != NULL) {
            if (aux->val == 'C' || aux->val == 'c') {
                aux->val = '1';
            } else if (aux->val == 'S' || aux->val == 's') {
                aux->val = '0';
            } else {
                fprintf(stderr, "Erro: Nao foi possivel identificar o estado do vertice %d", i);
            }
            aux = aux->next;
        }
        i++;
    }
}
//-----------------------------------------CHANCE DE INFECCAO---------------------------------------//
/*   considerando um individuo sem mascara e saudavel (00), com outras quaisquer combinacoes de estado,
apos irei realizar a chance de um individuo com mascara e saudavel (10), com outras quaisquer combinacoes
de estado!         */

int percorre(struct lista *lista){
    struct node *aux = lista->begin;
    if(aux->val == '0'){    // 1 coluna
        aux = aux->next;
        if(aux->val == '0'){    // 2 coluna
            aux = aux->next;
            if(aux->val == '0'){   // 3 coluna
                aux = aux->next;
                if(aux->val == '0'){    // 4 coluna
                    return 0;
                }else if(aux->val == '1'){  // 4 coluna
                    return 100;
                }
            }else if(aux->val == '1'){  // 3 coluna
                aux = aux->next;
                if(aux->val == '0'){    // 4 coluna
                    return 0;
                }else if(aux->val == '1'){  // 4 coluna
                    return 50;
                }
            }
        }
    }else{      // 1 coluna
        aux = aux->next;
        if(aux->val == '0'){    // 2 coluna
            aux = aux->next;
            if(aux->val == '0'){   // 3 coluna
                aux = aux->next;
                if(aux->val == '0'){    // 4 coluna
                    return 0;
                }else if(aux->val == '1'){  // 4 coluna
                    return 50;
                }
            }else if(aux->val == '1'){  // 3 coluna
                aux = aux->next;
                if(aux->val == '0'){    // 4 coluna
                    return 0;
                }else if(aux->val == '1'){  // 4 coluna
                    return 25;
                }
            }
        }
    }
}

void atribui_Porcent(struct lista **lista){
    for(int i=0; i<TAM; i++){
        int p = percorre(lista[i]);
        lista[i]->porcent = p;
    }
}

//-------------------------------------------------MAIN--------------------------------------------//
int main(){
    
    struct lista **lista = (struct lista**)malloc(TAM * sizeof(struct lista*));
    leitura_arq(lista);


    for(int j=0; j<TAM; j++){
        printf("\n|%d| = ", j);
        print(lista[j]);
        //printf("%s", lista[j]->pal);
    }
    replace(lista);
    atribui_Porcent(lista);

    printf("LIsta com booleanos e suas porcentagens de infeccatados: \n");
    for(int j=0; j<TAM; j++){
        printf("\n|%d| = ", j);
        print(lista[j]);
        printf(" - %d%%", lista[j]->porcent);
    }
    printf("\n");
    return 0;
}
