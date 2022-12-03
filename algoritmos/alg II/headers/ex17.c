#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE *doc;

    char arq, palavra;
    int cont = 0;

    printf("nome do arquivo: ");
    scanf("%s", &arq);

    doc = fopen(arq, "rt");

    if(doc == NULL){
        printf("arquivo nao exitente");
    }

   printf("ARQUIVO ENCONTRADO\n\n");
    printf("palavra que deseja procurar no arquivo: \n");
    scanf("%s", &palavra);

    while(palavra != EOF){
        palavra = tolower(palavra);
        fread(&palavra, sizeof(char), 1, doc);
        cont++;
    }

    printf("exite %dX a palavra '%s' no arquivo!", cont, palavra);
    

    fclose(doc);
    return 0;
}
