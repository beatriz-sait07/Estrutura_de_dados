#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//definicao
typedef struct cad_inf Info;
typedef struct node_simples Node;
typedef struct linkedlist List;
bool isNull(List *lista);
Info *cadastro (char *nome, char *modelo, char *placa, char *ocupacao, int id);
Node *create_node(Info *p);
List *create_lista();
void destroy (List **ref_list);
void insert_dados(Info *p, List *lista);
void locar_carro(List *lista, int alugar, char *nome);
void checkout(List *lista, Info *p, int id, float dias);
void print_list(List *lista);
void print_disponiveis(List *lista);
void print_indisponiveis(List *lista);
//--------------------------------------------------------------------------------

int main (){
    Info *in_loc;
    List *l = create_lista();
        in_loc = cadastro("locadora", "BMW", "QAP-9648", "disponivel", 1);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "HONDA", "CAH-7557", "disponivel", 2);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "JEEP", "CZN-2963", "disponivel", 3);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "MAZDA", "EDP-3873", "disponivel", 4);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "VOLVO", "BTX-5218", "disponivel", 5);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "SUZUKI", "FIK-1642", "disponivel", 6);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "TOYOTA", "CAM-7896", "disponivel", 7);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "NISSAN", "GFH-1028", "disponivel", 8);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "AUDI", "BIA-6574", "disponivel", 9);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "RENAULT", "ERT-5520", "disponivel", 10);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "KIA", "QAP-6398", "disponivel", 11);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "LEXUS", "QAS-4578", "disponivel", 12);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "HYUNDAI", "MPA-5870", "disponivel", 13);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "FIAT", "HDF-2019", "disponivel", 14);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "SUBARU", "ANO-6644", "disponivel", 15);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "FORD", "NER-5241", "disponivel", 16);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "CITROEN", "WQA-7810", "disponivel", 17);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "PEUGEOT", "TYE-6500", "disponivel", 18);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "DODGE", "ZER-4588", "disponivel", 19);
        insert_dados(in_loc, l);
        in_loc = cadastro("locadora", "PORSHE", "HIT-1199", "disponivel", 20);
        insert_dados(in_loc, l);


    float dias_locado = 0;
    int dig;
    while (dig != 0){
        printf("******MENU******\n");
        printf("Digite a opcao que deseja, sendo:\n1 - listar todos os carros\n2 - listar carros disponiveis\n3 - listar carros locados\n4 - locar um veiculo\n5 - devolucao\n0 - sair\nopcao: ");
        scanf("%d", &dig);
        if(dig == 1){
            print_list(l);
        }
        if(dig == 2){
            print_disponiveis(l);
        }
        if(dig == 3){
            printf("carros locados:\n");
            print_indisponiveis(l);
        }
        if(dig == 4){
            //terminar
            int locar;
            char nome[50];
            printf("qual carro voce deseja locar ? (digite sua identificacao)\n");scanf("%d", &locar);
            printf("quantos dias de locacao? ");scanf("%f", &dias_locado);
            printf("contratante: ");scanf("%s", &nome[50]);
            locar_carro(l, locar, nome);
        }
        if(dig == 5){
            int locar;
            printf("\t\t\tdevolucao do veiculo!\n");
            printf("Para realizar a devolucao digite a identificacao do carro: ");scanf("%d", &locar);
            checkout(l, in_loc, locar, dias_locado);
        }

        if(dig == 0){
            printf("FINALIZADO\n");
            destroy(&l);
        }
    }

    return 0;
}


//---------------------------------------------------------------------------------
//implementacao
typedef struct cad_inf {
    char *nome;
    char *placa;
    char *modelo;
    char *ocup;
    int id;
} Info;

typedef struct node_simples {
    Info *cadastro;
    struct node_simples *next;
    struct node_simples *prev;
} Node;

typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int capacity, size_list;
} List;

bool isNull(List *lista){
    return lista->begin == NULL;
}
 
Info *cadastro (char *nome, char *modelo, char *placa, char *ocupacao, int id){
    Info *aux = (Info*)calloc(1, sizeof(Info));
    aux->nome = nome;
    aux->modelo = modelo;
    aux->placa = placa;
    aux->ocup = ocupacao;
    aux->id = id;

    return aux;
}

Node *create_node(Info *p){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->cadastro = p;
    node->next = NULL;
    return node;
}

List *create_lista(){
    List *list = (List*)calloc(1, sizeof(List));
    list->begin = NULL;
    list->end = NULL;
    list->capacity = 20;
    list->size_list = 0;
    return list;
}

void destroy (List **ref_list){
    List *l = *ref_list;
    Node *p = l->begin;
    Node *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(l);
    *ref_list = NULL;
    printf("LISTA TOTALMENTE DESALOCADA!\n\n");
}

void insert_dados(Info *p, List *lista){
    Node *dados = create_node(p);

    if(isNull(lista))lista->begin = lista->end = dados;
    else{
        lista->end->next = dados;
        dados->prev = lista->end;
        lista->end = dados;
    }
    lista->size_list++;
}

void locar_carro(List *lista, int alugar, char *nome){
    Node *aux = lista->begin;
    while(aux != NULL){
        if(alugar == aux->cadastro->id){
            if(aux->cadastro->ocup == "disponivel"){
                aux->cadastro->nome = nome;
                aux->cadastro->ocup = "indisponivel";
            } else {
                printf("\ncarro indisponivel no momento!\n");
            }
        }
        aux = aux->next;
    }
}

void checkout(List *lista, Info *p, int id, float dias){
    Node *aux = lista->begin;
    while(aux != NULL){
        if(aux->cadastro->id == id){
            printf("\t\tCUPOM DE DEVOLUCAO\n");
            printf("Locador: %s\nModelo: %s\nPlaca: %s\nIdentificacao: %d\n",
            aux->cadastro->nome, aux->cadastro->modelo, aux->cadastro->placa, aux->cadastro->id);
            printf("\nDiaria: R$ 200,00\nDias locados: %.0f\nValor Total: \tR$ %.2f\n", dias, (dias*200));
            aux->cadastro->ocup = "disponivel";
        }
        aux = aux->next;
    }
}

void print_list(List *lista){
    Node *aux = lista->begin;
    if(isNull(lista))printf("Lista vazia\n");
    else{
        printf("\nNOME\t\t|\tMODELO\t\t|\tPLACA\t\t|\tOCUPACAO\t|\tIDENTIFICACAO\t|\n");
        while( aux != NULL){
            printf("%s\t|\t%s\t\t|\t%s\t|\t%s\t|\t\t%d\n",
            aux->cadastro->nome, aux->cadastro->modelo, aux->cadastro->placa, aux->cadastro->ocup, aux->cadastro->id);
            aux = aux->next;
        }
    }
}

void print_disponiveis(List *lista){
    Node *aux = lista->begin;
    if(isNull(lista))printf("Lista vazia\n");
    else{
        printf("\nNOME\t\t|\tMODELO\t|\tPLACA\t\t|\tOCUPACAO\t|\tIDENTIFICACAO\t|\n");
        while( aux != NULL){
            if(aux->cadastro->ocup == "disponivel"){
            printf("%s\t|\t%s\t|\t%s\t|\t%s\t|\t\t%d\n",
            aux->cadastro->nome, aux->cadastro->modelo, aux->cadastro->placa, aux->cadastro->ocup, aux->cadastro->id);
            }
            aux = aux->next;
        }
    }
}

void print_indisponiveis(List *lista){
    Node *aux = lista->begin;
    if(isNull(lista))printf("Lista vazia\n");
    else{
        printf("\nMODELO\t|\tPLACA\t\t|\tOCUPACAO\t|\tIDENTIFICACAO\t|\n");
        while( aux != NULL){
            if(aux->cadastro->ocup == "indisponivel"){
            printf("%s\t|\t%s\t|\t%s\t|\t\t%d\n",
            aux->cadastro->modelo, aux->cadastro->placa, aux->cadastro->ocup, aux->cadastro->id);
            }
            aux = aux->next;
        }
    }
}