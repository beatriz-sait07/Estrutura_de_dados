// buscando quantas vezes repediu cada letra do alfabeto

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

    //pior jeito de fazer, mas foi o unico que rodou!
    // possivel fazer com um faco de repetição, mas não consegui;

    file = fopen("arq.txt", "r");

    int conta = 0, contb = 0, contc = 0, contd = 0, conte = 0, contf = 0, contg = 0;
    int conth = 0, conti = 0, contj = 0, contk = 0, contl = 0, contm = 0, contn = 0;
    int conto = 0, contp = 0, contq = 0, contr = 0,conts = 0, contt = 0, contu = 0;
    int contv = 0, contw = 0, contx = 0, conty = 0, contz = 0;

    while ((letras = fgetc(file))!=EOF){
        letras =tolower(letras);    //transforma todas as letras em minusculo

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

    printf(" a = %d\n", conta);
    printf(" b = %d\n", contb);
    printf(" c = %d\n", contc);
    printf(" d = %d\n", contd);
    printf(" e = %d\n", conte);
    printf(" f = %d\n", contf);
    printf(" g = %d\n", contg);
    printf(" h = %d\n", conth);
    printf(" i = %d\n", conti);
    printf(" j = %d\n", contj);
    printf(" k = %d\n", contk);
    printf(" l = %d\n", contl);
    printf(" m = %d\n", contm);
    printf(" n = %d\n", contn);
    printf(" o = %d\n", conto);
    printf(" p = %d\n", contp);
    printf(" q = %d\n", contq);
    printf(" r = %d\n", contr);
    printf(" s = %d\n", conts);
    printf(" t = %d\n", contt);
    printf(" u = %d\n", contu);
    printf(" v = %d\n", contu);
    printf(" w = %d\n", contw);
    printf(" x = %d\n", contx);
    printf(" y = %d\n", conty);
    printf(" z = %d\n", contz);
    

    fclose(file);

    return 0;
}
