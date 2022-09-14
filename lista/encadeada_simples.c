#include "encadeada_simples.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node_simples{
    int valor;
    struct _node_simples *next;
}Node_simples;

typedef struct _lista_simples{
    Node_simples *inicio;
    Node_simples *fim;
    int size;    //obrigatório já que necessia-se saber o tamanho
}Lista;

bool _isNull(const Lista *list){
    return list->size == 0;
}

Node_simples *Node_create(int val){
    Node_simples *node = (Node_simples*)calloc(1, sizeof(Node_simples));
    node->valor = val;
    node->next = NULL;
    return node;
}

Lista *Lista_create(){
    Lista *lista = (Lista *)calloc(1, sizeof(Lista));   //aloca apenas a "cabeca da lista", ou seja, o inicio da lista
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->size = 0;
    return lista;
}

void add_inicio(Lista *list, int elem)
{
    //lista está vazia
    if(list->inicio == NULL){
        Node_simples *dados = Node_create(elem);
        list->inicio = dados;
    }
    //lista com dados
    else{
        Node_simples *dados = Node_create(elem);
        dados->next = list->inicio; // o elemento criado aponta para o elemento que o 'inicio' está apotando p/ não perder a referancia
        list->inicio = dados; // agora ele se torna o primeiro elemento sem perder a referencia do antigo 1º elemento
    }
    list->size++;
}

//tem que verificar se a lista não está vazia, pois caso ela esteja. ele será o elemento final e inicial
void add_final(Lista *list, int elem){
    Node_simples *dados = Node_create(elem);
    if(_isNull(list))list->inicio = dados;
    //sem o else ele inseriria como 1º e depois duplicaria como ultimo, ou seja, ele entraria duas vezes
    else{
        //enquando dados não foir igual a null (ultimo elemento), prox.
        Node_simples *aux = list->inicio;
        while(aux->next != NULL){
            aux = aux->next;
        }//quando chegar aqui, aux aponta p/ o ultimo elemento
        aux->next = dados;
    }
    list->size++;
}

/*          modo simplificado de add_inicio

Nó *dados = Nó_create(elem);
dados->next = list->inicio;
list->inicio = dados;

    ****funciona para o caso de estar com dados ou vazia*****
    (testa o 'null' que você entenderá)
*/

void insert_ordem (Lista *list, int elem){
    Node_simples *inserir = Node_create(elem); // cria o novo elemento
    Node_simples *aux = list->inicio; //percorre o vetor sem perder a referencia,
    if(_isNull(list))list->inicio = inserir; //veririfca se a lista está vazia

    else{
        if(list->inicio->valor > inserir->valor){
            inserir->next = list->inicio; //se for menor, ele passa a ser o inicio
            list->inicio = inserir;
        }
        else{
            while(aux->next && inserir->valor > aux->next->valor){ // verif. se existe um prox e se esse proximo é maior
                
                aux = aux->next; // o ponteiro auxiliar passa a receber o valor do proximo valor

            }
            inserir->next = aux->next; // novo valor vai apontar para o valor maior que ele
            aux->next = inserir; // aqui ele entra na posição entre um numero maior que ele e um maior
        }
    }
    list->size++;
}

void remover_elemento(Lista *list, int elem){
    if(!_isNull(list)){ //verifica se a lista NÃO está vazia
        // elemento no inicio
        if(list->inicio->valor == elem){ //verifica se o 1º nó contem o valor que deseja remover
            Node_simples *pos = list->inicio; //antes de atualizar o inicio, estamos armazenando ele em uma variavel 'pos'
            list->inicio = pos->next; //atualiza o inicio, sem perda de referencia
            if(list->inicio == NULL)pos = NULL; //isso é para o caso da lista conter apensas um elemento
            free(pos);
            list->size--;
        }

        // elemento no meio
        else{
            Node_simples *pos = list->inicio->next;
            Node_simples *ant = list->inicio;
            while(pos != NULL && pos->valor != elem){ //enq exister elemen na lista e o valor apontado pelo pos for != do valor desejado, a lista seguirá p/ o prox elemento            }
                ant = pos; //andando juntamente com o pos
                pos = pos->next; 
            }     
            if (pos != NULL){ //elemento encontrado
                ant->next = pos->next; // fazendo a ligação para não perder a referencia
                if(pos->next == NULL){ // elemento no final
                    list->fim = ant;
                }
                free(pos);
                list->size--;
            }
        }
    }
}

void remover_todos_elementos(Lista **ref_list){
    Lista *lista = *ref_list;

    /*precisa da aux para não perder a referencia para o proximo elemento
    assim que o aux recebe o proximo elemento a lista pula para o outro e assim
    excluimos o aux, isso acontecerá até a lista receber null, ou seja, o fim da lista*/
    Node_simples *busca = lista->inicio;
    Node_simples *aux = NULL;

    while (busca != NULL){
        aux = busca;
        busca = busca->next;

        free(aux);
        lista->size--;
    }
    free(lista);
}

void busca_elemento(Lista *list, int elem){
    //verifica se a lista contem elementos
    if(_isNull(list)){
        fprintf(stderr, "ERRO: lista vazia\n\n");
        exit(EXIT_FAILURE);
    }
    //verifica se o elemento dessejado é um elemento valido!
    else if(elem < 0 || elem >= list->size){
        fprintf(stderr, "ERRO: index invalido!\n\n");
        exit(EXIT_FAILURE);
    }
    //tudo valido
    else{
        int index=0;
        Node_simples *p = list->inicio;
        
        while(index != elem){
            p = p->next;
            index++;
        }

        return p->valor; //retorna o valor dentro do index
    }
    
}

int tam_lista(const Lista *list){
    return list->size;
}

void print(const Lista *list)
{
    Node_simples *p = list->inicio;

    if(list != NULL){
        printf("INICIO -> ");
        while(p != NULL){
            printf(" %d ->", p->valor);
            p = p->next;
        }
        printf("NULL\n");
    }else{
        printf("a lista foi totalmete desalocada!\n");
    }

    printf("tamanho = %d\n", list->size);
}

/*
arrumar a busca e a remoção de todos os elementos
*/