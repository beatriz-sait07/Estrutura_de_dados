// contando caracter no arquivo txt

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
    
    FILE *file;
    file = fopen("arq.txt", "w");

    if (file == NULL){
        printf("não foi possivel criar o arquivo!\n");
        return 0;
    }
    
    char letras;
    char busca;

    printf("digite um caracter para saber quantas vezes o mesmo apareceu no arquivo: ");
    scanf("%c", &busca);

    printf("\nDigite um texto ('0' - finaliza a digitacao): \n");
    
    while(1){
        fflush(stdin);
        scanf("%c", &letras);
        if(letras == '0')
        break;

        fputc(letras, file);
    }

    

    int cont = 0;

    printf("\n ARMAZENAMENTO COMPLETO!\n");

    fclose(file);

    file = fopen("arq.txt", "r");


    while ((letras = fgetc(file))!=EOF){
        letras =tolower(letras);

        if(busca == letras){
		cont++;
        }
    }

    printf("\ntem %i de %c no arquivo!\n\n", cont, busca);
    

    fclose(file);

    
    

    return 0;
}
