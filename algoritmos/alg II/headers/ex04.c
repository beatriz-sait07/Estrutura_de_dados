#include <stdio.h>
#include <stdlib.h>

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

    fclose(file);

    printf("\n ARMAZENAMENTO COMPLETO!\n");

    

    return 0;
}
