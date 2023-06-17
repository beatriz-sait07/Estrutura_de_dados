#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>


typedef struct Node_S Node;
typedef struct Lista List;
void dados_arq_email(List **adj);
void dados_arq_ipv4(List **adj);
Node *create_node(char caracter);
List *create_lista();
void add_dados(char elem, int index, List **adj);
void validar_email(List **adj);
void print(List **adj, int size);
void print_ipv4(List **adj);


int main(){
    List **adj = (List**)malloc(50 * sizeof(List*));

    int dig;
    printf("qual sera sua validacao ??\n1 - email\n2 - ipv4\n");
    scanf("%d", &dig);
    
        if (dig == 1)
        {
            dados_arq_email(adj); // chamando a primeira funcao
            validar_email(adj);
            printf("fim de execucao, verifique o arquivo: 'saida_email_beatriz.csv\n");
        }
        else if (dig == 2)
        {
            dados_arq_ipv4(adj); // chamando a segunda funcao
            print_ipv4(adj);
            printf("fim de execucao, verifique o arquivo 'saida_ipv4_beatriz.csv'");
        }
        else

        {
            printf("digito invalido\n");
        }


    free(adj);

    return 0;
}
typedef struct Node_S{
    char letras;
    struct Node_S *next;
}Node;

typedef struct Lista{
    Node *inicio, *fim;
    int val, size;
}List;

bool _isNull(const List *lista){
    return lista->inicio == NULL;
}

Node *create_node(char caracter){
    Node *node = (Node*)malloc(sizeof(Node));
    node->letras = caracter;
    node->next = NULL;
}

List *create_lista(){
    List *lista = (List*)malloc(sizeof(List));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->val = 1;
    lista->size = 0;
}

//funcao para inserir sempre no final da lista
void add_dados(char elem, int index,List **adj){
    Node *dados = create_node(elem);
    if(_isNull(adj[index])){
        // se a lista estiver vazia no index, ele insere
        adj[index]->inicio = dados;
        adj[index]->fim = dados;
    }
    else{
        adj[index]->fim->next = dados;
        adj[index]->fim = adj[index]->fim->next;
    }
    adj[index]->size++;
}

void dados_arq_email(List **adj){
    FILE *file = fopen("entrada_email_beatriz.csv", "r");
    int cont=0;
    char letras;

    if(file == NULL)fprintf(stderr, "erro ao abrir arquivo!\n");
    
    adj[cont] = create_lista();

    while(letras != EOF){
        if(letras == ',' ){
            cont++;
            adj[cont] = create_lista();
            adj[cont]->val = 1;
            letras = fgetc(file); //para pular a vigula e não dar erro
        }
        add_dados(letras, cont, adj);
        letras = fgetc(file);
    }
    fclose(file);
}

void dados_arq_ipv4(List **adj){
    FILE *file = fopen("entrada_ipv4_beatriz.csv", "r");
    int cont=0;
    char letras;

    if(file == NULL)fprintf(stderr, "erro ao abrir arquivo!\n");
    
    adj[cont] = create_lista();

    letras = fgetc(file);

    while(letras != EOF){
        if(letras == ',' ){
            cont++;
            adj[cont] = create_lista();
            letras = fgetc(file); //para pular a vigula e não dar erro
        }
        add_dados(letras, cont, adj);
        letras = fgetc(file);
    }
    fclose(file);
}

void validar_email(List **adj)
{
    for(int i=0; i<adj[i]->size; ++i){
        int tam=0, ponto=0;
        Node *aux = adj[i]->inicio;
        while(aux){

            /// ANTES DO @

            int j=0, k=0;
            char *inc_email = (char*)malloc(sizeof(char));
            while(aux->letras != '@'){
                inc_email[j] = aux->letras;
                j++;
                tam++;
                aux = aux->next;
            }
            
            for(int n=0; n<tam; n++){
                if(inc_email[n] == '.'){
                    ponto++;
                }
            }
            int flag=0;
            if(ponto == 1){
                for(int n=0; n<tam-1; n++){
                    if(inc_email[n] >= 'a' && inc_email[n] <= 'z' || inc_email[n] == '.'){
                         exit;
                    }else{
                        flag++;
                    }
                }
            }else{
                flag++;
            }
            if(flag != 0){ 
                adj[i]->val = 0;
            }

            int z=0;
            char *email = (char*)malloc(sizeof(char));
            char final = aux->next->letras;
            while(aux != NULL){
                email[z] = aux->letras;
                z++;
                aux = aux->next;
            }
            if(strcmp(email, "@estudante.ifms.edu.br") == 0){
                if(adj[i]->val != 0){
                    adj[i]->val = 2;
                }
            }else if(strcmp(email, "@ifms.edu.br") == 0){
                if(adj[i]->val != 0){
                    adj[i]->val = 3;
                }
            }else{
                adj[i]->val = 0;
            }
            break;
        }
    print(adj, i);
    //printf("validou|\n");
    }
}

/*
void validar (List **adj){
    int val=0, ponto=0, j=0, flag=0, l=0;
    char est[23] = {"@estudante.ifms.edu.br"};
    char prof[13] = {"@ifms.edu.br"};

    for(int i=0; i<size; i++){
        Node *aux = adj[i]->inicio;
        
        while(aux){
            char *email = (char*)calloc(100, sizeof(char));
            //char email[100];
            while(aux->letras != '@'){
                email[j] = aux->letras;
                j++;
                val++;
                aux = aux->next;
            }
        

            for(int x=0; x<val; x++){
                if(email[x] == '.'){
                    ponto++;
                }
            }

            if(ponto == 1){
                for(int x=0; x<val-1; x++){
                    if(email[x] >= 'a' && email[x] <= 'z' || email[x] == '.'){
                        exit;
                    }
                    else{
                        flag++;
                    }
                }
            }
            else{
                flag++;
            }

            free(email);

            if(flag != 0){
                adj[i]->val=0;
            }

            char *fim_email = (char*)calloc(100, sizeof(char));
            //char fim_email[100];  
            while(aux != NULL){
                fim_email[l] = aux->letras;
                l++;
                aux = aux->next;
            }
                
        //    strcmp compara dois vetor
                
            if(strcmp(email, est) == 0){
                if(adj[i]->val != 0)adj[i]->val = 2;
            }
            else if(strcmp(email, prof) == 0){
                if(adj[i]->val != 0)adj[i]->val = 3;
            }
            else{
                adj[i]->val = 0;
            }
            break;
            free(fim_email);
        }
        print(adj, i);
        }
    }*/

void print(List **adj, int index){
    Node *aux = adj[index]->inicio;
    FILE *arq = fopen("saida_email_beatriz.csv", "w");
    while(aux){
        fprintf(arq ,"%c", aux->letras);
        aux = aux->next;
    }
    if(adj[index]->val == 2){
        fprintf(arq, " - estudante(valido)");
    }
    else if(adj[index]->val == 3){
        fprintf(arq, "professor(valido)");
    }
    else{
        fprintf(arq, " - invalido");
    }

}

void print_ipv4(List **adj){
    FILE *arq = fopen("saida_ipv4_beatriz.csv", "w");
    if(arq == NULL)fprintf(stderr, "erro: abrir arquivo de saida\n");
    for(int i=0; i<sizeof(adj); i++){
        Node *aux = adj[i]->inicio;
        while(aux){
            fprintf(arq,"%c", aux->letras);
            aux = aux->next;
        }
        fprintf(arq,",");
    }
}
