// juntando arq1 e arq2 em um arq3

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
    
    FILE *file, *arq, *doc;

    file = fopen("arq.txt", "w");

    char letras;

    if (file == NULL){
        printf("não foi possivel criar o arquivo!\n");
        return 0;
    }
    else{
    

        printf("\nDigite um texto para primeiro arquivo ('0' - finaliza a digitacao): \n");
    
        while(1){
            fflush(stdin);
            scanf("%c", &letras);

            if(letras == '0')
                break;

            fputc(letras, file);
        }   

        printf("\n ARMAZENAMENTO DO PRIMEIRO ARQUIVO COMPLETO!\n");
    }
    
    char c;

    arq = fopen("dados_arq.txt", "w");

    if (arq == NULL){
        printf("não foi possivel criar o arquivo!\n");
        return 0;
    }

    else{

        printf("\nDigite um texto para o segundo arquivo ('0' - finaliza a digitacao): \n");
    
        while(1){
            fflush(stdin);
            scanf("%c", &c);
            if(c == '0')
                break;

        fputc(c, arq);
    }

    printf("\n ARMAZENAMENTO DO SEGUNDO ARQUIVO COMPLETO!\n");
    }

    fclose(file);
    fclose(arq);


    file = fopen("arq.txt", "r");

    if(file == NULL){
        printf("arquivo não encontrado!");
        return 0;
    }
    

    
    arq = fopen("dados_arq.txt", "r");

    if(arq == NULL){
        printf("arquivo não encontrado!\n");
        return 0;
    }

    doc = fopen("rec.txt", "w");

    if(doc == NULL){
        printf("não foi possivel criar um novo arquivo\n");
        exit(1);
    }
    
    letras = getc(file);

    fputs("primeiro arquivo\n", doc);
    while(letras != EOF){
        
        letras = tolower(letras);

        putc(letras, doc);

        letras = getc(file);
    }

    c = getc(arq);

    fputs("segundo arquivo\n", doc);
    while(c != EOF){
        c = toupper(c);

        putc(c, doc);

        c = getc(arq);
    }

    printf("\n\nDADOS ARMAZENADOS EM REC.TXT\n\n");

    fclose(file);
    fclose(arq);  
    fclose(doc);  
    
    return 0;
}
