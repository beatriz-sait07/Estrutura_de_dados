//transformando dados arq1 (minusculo) para arq2(mauisculo)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
    
    FILE *file, *arq;
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

    int contV= 0;

    printf("\n ARMAZENAMENTO COMPLETO!\n");

    fclose(file);

    //usar aqui
    file = fopen("arq.txt", "rt");

    if(file == NULL){
        printf("arquivo não encontrado!");
        return 0;
    }

    arq = fopen("dados_aqr.txt", "w");

    if(arq == NULL){
        printf("nao foi possivel criar novo arquivo\n");
        return 0;
    }

    letras = getc(file);

    while (letras != EOF){
        letras = toupper(letras);

        putc(letras, arq);

        letras = getc(file);

        
    }

    fclose(file);
    fclose(arq);    
    
    return 0;
}
