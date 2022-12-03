//contando letras, palavras, linhas e repetição de cada letra;

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
    
    char letras, palavras;

    printf("\nDigite um texto ('0' - finaliza a digitacao): \n");
    
    while(1){
        fflush(stdin);
        scanf("%c", &letras);
        if(letras == '0')
        break;

        fputc(letras, file);
    }

    int vogal= 0, consoante = 0, linhas = 0, pal = 0;

    int conta = 0, contb = 0, contc = 0, contd = 0, conte = 0, contf = 0, contg = 0;
    int conth = 0, conti = 0, contj = 0, contk = 0, contl = 0, contm = 0, contn = 0;
    int conto = 0, contp = 0, contq = 0, contr = 0,conts = 0, contt = 0, contu = 0;
    int contv = 0, contw = 0, contx = 0, conty = 0, contz = 0;




    printf("\n ARMAZENAMENTO COMPLETO!\n\n");

    fclose(file);

    file = fopen("arq.txt", "r");

    while ((letras = fgetc(file))!=EOF){
        letras =tolower(letras);    //transforma todas as letras em minusculo

        if(letras == 'a' ||
           letras == 'e' ||
           letras == 'i' ||
           letras == 'o' ||
           letras == 'u'){

		vogal++;
        }

		else{
			consoante++;

			if(letras == '\n' || letras == ' '){
				consoante--;
			}
			
		}
        
		if(letras == '\n'){
			linhas++;
   		}

		if((letras != '\n') || (letras != ' ')){
			palavras = 1;
			
			if(palavras == 1){
				pal++;
				palavras += 1;
			}
		}

        if(letras == 'a') conta++;
        if(letras == 'b') contb++;
        if(letras == 'c') contc++;
        if(letras == 'd') contd++;
        if(letras == 'e') conte++;
        if(letras == 'f') contf++;
        if(letras == 'g') contg++;
        if(letras == 'h') conth++;
        if(letras == 'i') conti++;
        if(letras == 'j') contj++;
        if(letras == 'k') contk++;
        if(letras == 'l') contl++;
        if(letras == 'm') contm++;
        if(letras == 'n') contn++;
        if(letras == 'o') conto++;
        if(letras == 'p') contp++;
        if(letras == 'q') contq++;
        if(letras == 'r') contr++;
        if(letras == 's') conts++;
        if(letras == 't') contt++;
        if(letras == 'u') contu++;
        if(letras == 'v') contv++;
        if(letras == 'w') contw++;
        if(letras == 'x') contx++;
        if(letras == 'y') conty++;
        if(letras == 'z') contz++;

	}

	
    

	printf("ARQUIVO POSSUI: \n");
    printf("\n%d letras\n", (vogal + consoante));
	printf("%d de linhas\n", linhas);
	printf("%d de palavras\n", palavras);
    printf("\n-----------------------------------------\n");

    printf(" a = %d  ", conta);
    printf(" b = %d  ", contb);
    printf(" c = %d  ", contc);
    printf(" d = %d  ", contd);
    printf(" e = %d  ", conte);
    printf(" f = %d  ", contf);
    printf(" g = %d\n", contg);
    printf(" h = %d  ", conth);
    printf(" i = %d  ", conti);
    printf(" j = %d  ", contj);
    printf(" k = %d  ", contk);
    printf(" l = %d  ", contl);
    printf(" m = %d  ", contm);
    printf(" n = %d\n", contn);
    printf(" o = %d  ", conto);
    printf(" p = %d  ", contp);
    printf(" q = %d  ", contq);
    printf(" r = %d  ", contr);
    printf(" s = %d  ", conts);
    printf(" t = %d  ", contt);
    printf(" u = %d\n", contu);
    printf(" v = %d  ", contu);
    printf(" w = %d  ", contw);
    printf(" x = %d  ", contx);
    printf(" y = %d  ", conty);
    printf(" z = %d\n", contz);

    

    fclose(file);

    
    

    return 0;
}
