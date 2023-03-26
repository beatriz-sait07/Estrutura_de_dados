#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT 1
//ideia principal

typedef struct node_dados Node;
typedef struct list List;
bool isNull(const List *l);
Node *create_node (char caracter);
List *create_list();
void insere_dados(List *l, char letra);
void print(const List *list);
//void exluir_lista(List **ref_l);
void validar_token(List *l);

int main (){
    FILE *arq;
    arq = fopen("arq.c", "r");
    
    List *lista[50]; // lista de palavras
    int i; // contador da lista, cada i vai ser uma palavra
    
    if (arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        exit(1);
    }
    

    lista[0] = create_list();
    List *list_caracter = create_list();
    List *list_num = create_list();
    List *frase = create_list();
    char aux = fgetc(arq);

    //percorrendo o arquivo e jogando os caracteres em uma lista
    while(aux != EOF){ 
        if(aux != ' ' && aux != '\n' && aux != '\t'){
            if(aux == '"'){
                insere_dados(frase, aux);
                aux = fgetc(arq);
                while(aux != '"'){
                    insere_dados(frase, aux);
                    aux = fgetc(arq);
                }
                insere_dados(frase, aux);
                aux = fgetc(arq);
            }
            if (!(aux >= 'a' && aux <= 'z' || aux >= 'A' && aux <= 'Z')) { // se nao for letra
                if (aux < '0' || aux > '9') { // se nao for numero

                    insere_dados(list_caracter, aux);
                    aux = fgetc(arq);
                }
                else {
                    insere_dados(list_num, aux);
                    aux = fgetc(arq);
                }
            }
            else {
                insere_dados(lista[i], aux);
                aux = fgetc(arq);
            }
        }
        else {
            if (aux == '\n') {
                aux = fgetc(arq);
                aux = fgetc(arq);
                aux = fgetc(arq);
                aux = fgetc(arq);
            }
            if (aux == ' ') {
                i++;
                lista[i] = create_list();
            }
            
            aux = fgetc(arq);
        }
    }

    printf("lista de palavras: \n");
    i=0;
    while(lista[i] != NULL){
        print(lista[i]);
        i++;
    }
    printf("\n\nlista de caracteres: \n");
    print(list_caracter);
    printf("\n\nlista de numeros: \n");
    print(list_num);
    printf("\n\nlista de frases: \n");
    print(frase);

    //while(i)
    validar_token(lista[0]);
    fclose(arq);
    printf("\n\n");

    return 0;
}

// criar uma funcao para definir os token do arquivo de saida

typedef struct  node_dados {
    char letras;
    struct node_dados *next;
}Node;

typedef struct list {
    Node *inicio, *fim;
    long int size;
    int token;
} List;

bool isNull(const List *l){
    return l->inicio == NULL;
}

Node *create_node (char caracter){
    Node *aux = (Node*)calloc(1, sizeof(Node));
    aux->letras = caracter;
    aux->next = NULL;

    return aux;
}

List *create_list() {
    List *l = (List*)calloc(1, sizeof(List));
    l->inicio = NULL;
    l->fim = NULL;
    l->token = 0;
    l->size = 0;

    return l;
}

void insere_dados(List *l, char letra){ // adicionando apenas no final, pq ? pq eh uma palavra!
    Node *alpha = create_node(letra);
    if (isNull(l)) l->inicio = alpha;
    else {
        Node *aux = l->inicio;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = alpha;
    }
    //printf("%c", letra);
    l->size ++;
}

void print(const List *list){
    Node *p = list->inicio;
    if(list != NULL){
        printf("INICIO -> ");
        while(p != NULL){
            printf(" %c ->", p->letras);
            p = p->next;
        }
        printf("NULL\n");
    }else{
        printf("a lista foi totalmete desalocada!\n");
    }
}


void validar_token(List *l){
    Node *p = l->inicio;

    while (p != NULL){
        if (p->letras == 'a'){ // token -> auto
            p = p->next;
            if (p->next != NULL && p->letras == 'u'){
                p = p->next;
                if (p->next != NULL && p->letras == 't'){
                    p = p->next;
                    if (p->next != NULL && p->letras == 'o'){
                        printf("token -> auto\n");
                    }
                }
            }
        }
        
        if (p->letras == 'b'){// token -> break
            p = p->next;
            if (p->next != NULL && p->letras == 'r'){
                p = p->next;
                if (p->next != NULL && p->letras == 'e'){
                    p = p->next;
                    if (p->next != NULL && p->letras == 'a'){
                        p = p->next;
                        if (p->next != NULL && p->letras == 'k'){
                            printf("token -> break\n");
                        }
                    }
                }
            }
        }

        if (p->letras == 'c'){ // token -> case
            p = p->next;
            if (p->next != NULL && p->letras == 'a'){
                p = p->next;
                if (p->next != NULL && p->letras == 's'){
                    p = p->next;
                    if (p->next != NULL && p->letras == 'e'){
                        printf("token -> case\n");
                    }
                }
            } else if (p->next != NULL && p->letras == 'h'){ // token -> char
                p = p->next;
                if (p->next != NULL && p->letras == 'a'){
                    p = p->next;
                    if (p->next != NULL && p->letras == 'r'){
                        printf("token -> char\n");
                    }
                }
            } else if(p->next != NULL && p->letras == 'o'){ // token -> const
                p = p->next;
                if (p->next != NULL && p->letras == 'n'){
                    p = p->next;
                    if (p->next != NULL && p->letras == 's'){
                        p = p->next;
                        if (p->next != NULL && p->letras == 't'){
                            printf("token -> const\n");
                        }
                    } else if (p->next != NULL && p->letras == 't'){ // token -> continue
                        p = p->next;
                        if (p->next != NULL && p->letras == 'i'){
                            p = p->next;
                            if (p->next != NULL && p->letras == 'n'){
                                p = p->next;
                                if (p->next != NULL && p->letras == 'u'){
                                    p = p->next;
                                    if (p->next != NULL && p->letras == 'e'){
                                        printf("token -> continue\n");
                                    }
                                }
                            }
                        }
                    }
                } 
            }
        }

        if (p->letras == 'i'){ // token -> int
            p = p->next;
            if (p != NULL && p->letras == 'n'){
                p = p->next;
                if (p != NULL && p->letras == 't'){
                    p = p->next;
                    if (p == NULL || p->letras == ' '){
                        printf("token -> int\n");
                        l->token = 1;
                    } else{
                        printf("token -> identificador\n");
                    }
                }
            }
            if (p != NULL && p->letras == 'f'){ // token -> if
                printf("token -> if\n");
            }
        }

        if (p->letras == 'd'){ // token -> double
            p = p->next;
            if (p != NULL && p->letras == 'o'){
                p = p->next;
                if (p != NULL && p->letras == 'u'){
                    p = p->next;
                    if (p != NULL && p->letras == 'b'){
                        p = p->next;
                        if (p != NULL && p->letras == 'l'){
                            p = p->next;
                            if (p != NULL && p->letras == 'e'){
                                p = p->next;
                                if (p == NULL || p->letras == ' '){
                                    printf("token -> double\n");
                                    l->token = 3;
                                } else{
                                    printf("token -> identificador\n");
                                }
                            }
                        }
                    }
                }
            }
        }

        if (p->letras == 'f'){ // token -> float
            p = p->next;
            if (p != NULL && p->letras == 'l'){
                p = p->next;
                if (p != NULL && p->letras == 'o'){
                    p = p->next;
                    if (p != NULL && p->letras == 'a'){
                        p = p->next;
                        if (p != NULL && p->letras == 't'){
                            p = p->next;
                            if (p == NULL || p->letras == ' '){
                                printf("token -> float\n");
                                l->token = 2;
                            } else{
                                printf("token -> identificador\n");
                            }
                        }
                    }
                }
            }
        }
        
        

        p = p->next;
    }
}

    /*while != null
    se lista.palvra == a
        if lista.palavra == u
        if palavra == t
        se palavra == o
        l.token = "auto"

    se palavra == i*/
        
    

void exluir_lista(List **ref_l){
    List *l = *ref_l;
    Node *pont = l->inicio;
    Node *aux = NULL;

    while(pont != NULL){
        aux = pont;
        pont = pont->next;
        free(aux);
    }
    free(l);
    *ref_l = NULL;
    printf("\nlista totalmente desalocada!\n");
}