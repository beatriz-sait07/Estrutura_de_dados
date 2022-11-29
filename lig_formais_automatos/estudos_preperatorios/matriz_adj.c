#include <stdio.h>
#include <stdlib.h>

//declaracao de funcoes
typedef struct grafo *Grafo;
Grafo inicia_grafo(int n);
void insere_arco_grafo (Grafo g, int v, int w);
void insere_arco_grafo_Nao_verifica (Grafo g, int v, int w);
void remove_arco_grafo(Grafo g, int v, int w);
void print_vert(Grafo g);
void print_grafo(Grafo g);
Grafo destoy_grafo(Grafo g);

//main
int main (){
    int i=0;
    inicia_grafo(i);
    printf("matriz adjacencia\n");
    
    return 0;
}


// implementacao de funcoes
struct grafo {
    int **A; //matriz inteira
    int n; // numero de vertices
    int m; //numero de arestas
};

Grafo inicia_grafo(int n){ 
    int i, j;


    //constroi um grafo com vertices 0 1, sendo de 0 até n-1;
    Grafo G = malloc(sizeof( *G));                                  // G -> A | n | m -- iniciando o arco com zero
    G->n = n;
    G->m = 0;
    G->A = malloc(n * sizeof(int));

    for(i=0; i<n; i++) G->A[i] = malloc(n * sizeof(int));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)G->A[i][j] = 0;
    
    return G;
}

//insere arco v-w no grafo g, supondo que v e w sao inteiros distintos entre 0 e n-1.
//caso o grafo ja tenha arco, nao sera realizada nenhum operacao
void insere_arco_grafo (Grafo g, int v, int w) {
    if(g->A[v][w] == 0){
        g->A[v][w] = 1;
        g->m++;
    }
}


//versao insere_arco_grafo, porem nao ha teste se v-w estao presentes
void insere_arco_grafo_Nao_verifica (Grafo g, int v, int w) { //insere independentemente de ja haver um arco ou nao
    g->A[v][w] = 1;
    g->m++;
}

//remove arco v-w do grafo g, supondo que v e w sao inteiro e distintos entre 0 e n1, em caso de inexistencia. nao realizada remove_Arco_grafo
void remove_arco_grafo(Grafo g, int v, int w){
    if(g->A[v][w] == 1){
        g->A[v][w] = 0;
        g->m--;
    }
}

// imprime vizinhos possiveis
void print_vert(Grafo g){
    int i,j;
    
    for(i=0; i<g->n; i++){ // para cada vertice
        printf("%2d: ", i);
        for(j=0; j<g->n;){ // todos os vizinhos possiveis
            if(g->A[i][j] == 1) printf("%2d", j); //imprime apenas os visinhos reais
            printf("\n");
        }
    }
}

//imprimindo o ***grafo***
void print_grafo(Grafo g){
    int i, j;

    for(i=0; i<g->n; i++){
        for(j=0; j<g->n; j++){
            if(g->A[i][j] == 1) printf("%2d", j);
            printf("-1"); //marcacao do fim da lista
            printf("\n");
        }
    }
}

//liberar espaco da memoria locada, lembre-se que vc libera o inverso do jeito que foi alocado
Grafo destoy_grafo(Grafo g) {
    int i;
    for(i=0; i<g->n; i++){
        free(g->A[i]);
        g->A[i] = NULL;
    }
    free(g->A);
    g->A = NULL;
    free(g);

    return NULL;    
}
