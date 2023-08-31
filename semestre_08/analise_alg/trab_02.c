#include<stdio.h>

void func_fat_not_rec(int n){ //meu metodo
    int fat = 1; // 1
    for(int i = 1; i <= n; i++){ // 2 + 2n
        fat *= i; // n
    }
    printf("%d\n", fat); // 1
}

void func_fat_not_rec_prof(int n){ //metodo professo
    int f=1; // 2
    for(n; n > 0; n--){ // 2 + 2n
        f = f * n; // n
    }
    printf("%d\n", f); //1
}

int func_fat_rec(int n){
    if(n == 1){
        return 1; //1
    }else{
         return n * func_fat_rec(n - 1); // n -1 (de cada vez que passar)
    }
}

int main (){
    printf("minha funca nao recursiva: ");
    func_fat_not_rec(5);
    printf("funcao nao recursiva do professor: ");
    func_fat_not_rec_prof(5);
    printf("funcao recursiva professor: ");
    int x = func_fat_rec(5);
    printf("%d\n", x);
    return 0;
}