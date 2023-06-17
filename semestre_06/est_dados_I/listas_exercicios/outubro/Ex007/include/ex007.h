#ifndef EX007_H
#define EX007_H

typedef struct _aluno Aluno;
typedef struct _list List;
typedef struct _notas Notas;

Aluno *create_Aluno(int ra, char *nome, bool cpl, bool aproalg, float t1, float t2, float t3, float nsub);
List *List_create();
bool is_Empty(const List *L);

void add_Aluno(List *L, int ra, char *nome, bool cpl, bool aproalg, float t1, float t2, float t3, float nsub);
void listar_Alunos(const List *L);

#endif