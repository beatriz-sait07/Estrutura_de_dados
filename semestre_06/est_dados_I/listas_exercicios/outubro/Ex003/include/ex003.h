#ifndef EX003_H
#define EX003_H

#include<stdbool.h>

typedef struct _site Site;
typedef struct _list List;

Site *Site_create(char *nome, char *link);
List *List_create();
bool is_Empty(const List *lista);

void add_site(List *lista, char *nome, char *link);
void print_sites(const List *lista);
void get_site(List *lista, char *nome);

#endif