/*Considere uma colecao de nomes de sites da web e seus respectivos links na Internet 
armazenados atraves de uma lista simplesmente encadeada. Escreva uma classe que contenha
um metodo que, dado o nome de um site, busque o seu link correspondente na lista e ao
mesmo tempo mova o noh que contem o nome buscado para o inıcio da lista, de forma que
ele possa ser encontrado mais rapidamente na proxima vez que for buscado.*/

#include<stdio.h>
#include<stdlib.h>
#include "ex003.h"


int main(){

    List *Lista = List_create();

    add_site(Lista, "Facebook", "https://www.facebook.com");
    add_site(Lista, "Instagram", "https://www.instagram.com");
    add_site(Lista, "Corinthians", "https://www.corinthians.com.br");
    add_site(Lista, "Ifms", "https://www.ifms.edu.br");
    
    print_sites(Lista);
    get_site(Lista, "Facebook");
    print_sites(Lista);
    get_site(Lista, "Corinthians");
    print_sites(Lista);
    get_site(Lista, "Ifms");
    print_sites(Lista);

return 0;
}