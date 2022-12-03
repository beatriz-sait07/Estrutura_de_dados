// contador de vogais em arquivo.txt

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

        if(letras == 'a' ||
           letras == 'e' ||
           letras == 'i' ||
           letras == 'o' ||
           letras == 'u'){

		cont++;

        }
	}

    if(letras > 1)
        printf("\ntem %i vogal no arquivo!\n\n", cont);

    else{
        printf("\ntem %i vogal no arquivo!\n\n", cont);
    }
    

    fclose(file);

    
    

    return 0;
}
