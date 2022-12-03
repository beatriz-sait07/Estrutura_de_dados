#include <iostream>

using namespace std;

int aloca(int* ptr, int tam)
{
    *ptr = tam;

    ptr = (int* )malloc(sizeof(int));


    if(ptr == NULL){
        cout << "nao foi possivel alocar!" << endl;
    }
    else{
        cout << "alocado!" << endl;
    }

    free(ptr);

    return 0;
}

int main (){
    
    int vetor[5] = { 2, 4, 6, 8, 10};
    aloca(vetor, 5);

    return 0;
}
