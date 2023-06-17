// criar thread para jantar dos filosofos

#include <stdio.h>      // tradicional do c#
#include <stdlib.h>     //exit_failure
#include <pthread.h>    //usar thread
#include <unistd.h>     // constantes simbolicas 

/* mutex -> recursive_mutext, imed_mutex, recursive_timed_mutex;
lock_guard e unique_lock */


//definindo as constantes
#define num_filosofos 5
#define esquerda (aut  + num_filosofos - 1) % num_filosofos
#define direita (aut + 1) % num_filosofos
#define pensando 0
#define tenta_comer 1
#define come 2


/* *******pra lembrar*******
num_filosofos = quantidade de filosofos
esquerda/direita = pessoas que ocupam tais locais
tenta_comer = testa se pode comer ou não
come = executando a acao de comer
aut = autenticacao do filosofo*/

//definindo variaveis globais
int situacao[num_filosofos];

//estado critico
pthread_mutex_t mutex;
pthread_mutex_t mutex_filosofos[num_filosofos];
pthread_t jantar[num_filosofos];


/*criando funçoes para:
1º criar filosofo
2º pensar
3º testar se pode comer
4º pegar o talher
5º comer / ou não (depende da 3º)
6º soltar o talher
 ******* seguir esta diretriz********
*/

void *filosofo( void *p);
void pensar (int aut);
void pegar_talher (int aut);
void intencao(int aut);
void comer (int aut);
void soltar_talher(int aut);


void pensar (int aut){

    //printf("entrou no pensar!\n");
    
    int acao = (rand() % 10 + 1);
    printf("%d esta pensando há %d s\n", aut, acao);

    //printf("finalizou pensar\n");
}

void intencao(int aut){

    //printf("entrou na intenção\n");

    printf("%d esta querendo comer!\n", aut);
    if(situacao[aut] == tenta_comer && situacao[esquerda] != come && situacao[direita] != come){
    printf("%d pode comer\n", aut);
    situacao[aut] = come;
    pthread_mutex_unlock (&(mutex_filosofos[num_filosofos]));
    }
    else{
        printf("filosofo %d ainda tentando comer!\n", aut);    
    }
}

void pegar_talher(int aut){

    //printf("entrou no pegar talher!\n");
    //comeca região critica
    pthread_mutex_lock(&(mutex));
    printf("%d esta com fome!\n", aut);
    situacao[aut] = tenta_comer;
    intencao(aut);
    pthread_mutex_unlock (&(mutex));
    pthread_mutex_lock(&(mutex_filosofos[aut])); //bloquei se os garfos não forem pegos
}




void comer(int aut){

    //printf("entrou no 'comer'\n");
    int acao = (rand() % 10 +1);
    printf("%d esta comendo há %d s\n", aut, acao);

}

void soltar_talher(int aut){

    //printf("entrou no 'soltar talher'\n");
    //comeca região critica
    pthread_mutex_lock (&(mutex));
    printf("filosofo %d esta pensando!\n", aut);
    situacao[num_filosofos] = pensando;
    intencao(esquerda);
    intencao(direita);
    pthread_mutex_unlock (&(mutex));
}



void *filosofo (void *pessoa){
    int *aut = (int *)(pessoa); //id

    printf("novo filosofo: %d \n", *(aut));
    
    while(1){
        //printf("entrou no while do filosofo\n");
        pensar(*(aut));
        pegar_talher(*(aut));
        comer(*(aut));
        soltar_talher(*(aut));
    }
    
    //retorna
    pthread_exit((void*) 0);
}


int main () {

    //printf("entrou na funcao principal\n");

    //int cont =0;
    int sit;

    pthread_mutex_init(&(mutex), NULL);
    for(int cont = 0; cont < num_filosofos; cont++){
        pthread_mutex_init(&(mutex_filosofos[cont]), NULL);
        //printf ("entrou no for 1\n");

    }
    //printf ("vai entrar no for 2\n");
    for(int cont = 0; cont < num_filosofos; cont++){
        //printf ("entrou no for 2\n");
        sit = pthread_create(&(jantar[cont]), NULL, filosofo, (void *)&(cont));
            if(sit){
                printf("erro ao criar thread!\n\n");
            return EXIT_FAILURE;
        } 
    }
return 0;
}


