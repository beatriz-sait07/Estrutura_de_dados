#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"ex007.h"

typedef struct _notas{
    float t1;
    float t2;
    float t3;
    float media;
} Notas;

typedef struct _aluno{
    int ra;
    char *nome;
    bool cpl;
    bool aproalg;
    Notas *ntrab;
    float nsub;
    struct _aluno *next;
    struct _aluno *prev;
} Aluno;

typedef struct _list {
    Aluno *begin;
    Aluno *end;
    int size;
} List;

Notas *create_Trab(Aluno *aluno, float t1, float t2, float t3)
{
    Notas *Trab = (Notas*)calloc(1, sizeof(Notas));
    Trab->t1 = t1;
    Trab->t2 = t2;
    Trab->t3 = t3;
    Trab->media = (t1+t2+t3)/3;
    return Trab;
}

Aluno *create_Aluno(int ra, char *nome, bool cpl, bool aproalg, float t1, float t2, float t3, float nsub)
{
    Aluno *aluno = (Aluno*)calloc(1, sizeof(Aluno));
    
    aluno->ra = ra;
    aluno->next = NULL;
    aluno->prev = NULL;
    aluno->nome = nome;
    aluno->cpl = cpl;
    aluno->aproalg = aproalg;
    aluno->ntrab = create_Trab(aluno, t1, t2, t3);
    aluno->nsub = nsub;

    return aluno;
}

List *List_create()
{
    List *lista = (List*)calloc(1, sizeof(List));
    lista->begin = NULL;
    lista->end = NULL;
    lista->size = 0;

    return lista;
}

bool is_Empty(const List *L)
{
    return L->size == 0;
}

void add_Aluno(List *L, int ra, char *nome, bool cpl, bool aproalg, float t1, float t2, float t3, float nsub)
{
    Aluno *new = create_Aluno(ra, nome, cpl, aproalg, t1, t2, t3, nsub);
    if(is_Empty(L)){
        L->begin = L->end = new;
    }else{
        if(new->ra < L->begin->ra){ // Se o New valor for menor que o primeiro elemento da Lista
            new->next = L->begin; // New aponta pro primeiro elemento
            L->begin->prev = new; 
            L->begin = new; // New passa a ser o Primeiro elemento
        }else{
            Aluno *aux = L->begin;
            while(aux->next && new->ra > aux->next->ra){ // Pula pro proximo ate achar um Maior
                aux = aux->next;
            }
            new->next = aux->next;
            if(aux->next){
                aux->next->prev = new;
            }
            new->prev = aux;
            aux->next = new;
        }
    }
    L->size++;
}

void listar_Alunos(const List *L)
{
    Aluno *p = L->begin;
    printf("\n--------- Estrutura de Dados - Lista de Alunos ---------\n\n");
    printf("    RA    |  Nome  | CPL | AproAlg | MediaTrabs |\n");
    while(p != NULL){
        printf("%d | %s | %s |   %s   |", p->ra, p->nome, p->cpl?"Sim":"Nao", p->aproalg?"Sim":"Nao");
        printf("    %.2f    |\n", p->ntrab->media);
        p = p->next;
    }
    printf("\n");
    printf("Size: %d\n", L->size);
    printf("Begin: %s\n", L->begin->nome);
    printf("End: %s\n", L->end->nome);
}
