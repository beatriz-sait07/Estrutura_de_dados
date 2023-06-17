//contando vogais e consoantes em arquivo txt

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

    int contV= 0, contC = 0;

    printf("\n ARMAZENAMENTO COMPLETO!\n");

    fclose(file);

    file = fopen("arq.txt", "r");

    while ((letras = fgetc(file))!=EOF){
        letras =tolower(letras);    //transforma todas as letras em minusculo

        if(letras == 'a' ||
           letras == 'e' ||
           letras == 'i' ||
           letras == 'o' ||
           letras == 'u'){

		contV++;
        }
        else{
            contC++;
        }
	}

    printf("\ntem %i vogal/vogais no arquivo!\n\n", contV);
    printf("\ntem %i consoante/consoantes no arquivo!\n\n", contC);
    

    fclose(file);

    
    

    return 0;
}
