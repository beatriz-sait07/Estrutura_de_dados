import _thread

cont_thread = 5

def bubble_sort(lista):
    global cont_thread
    n = len(lista)
    # Percorre toda a lista
    for i in range(n):
        for j in range(0, n-i-1):
            if lista[j] > lista[j+1]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
    


def soma_matrizes(matriz1, matriz2):
    global cont_thread
    # Verifica se as matrizes têm o mesmo tamanho
    if len(matriz1) != len(matriz2) or len(matriz1[0]) != len(matriz2[0]):
        return "As matrizes têm tamanhos diferentes e não podem ser somadas."

    # Inicializa uma matriz para armazenar a soma
    soma = []

    for i in range(len(matriz1)):
        linha_soma = []
        for j in range(len(matriz1[0])):
            linha_soma.append(matriz1[i][j] + matriz2[i][j])
        soma.append(linha_soma)
    
    cont_thread-=1
    return soma

def multiplicar_matrizes(matriz1, matriz2):
    global cont_thread
    if len(matriz1[0]) != len(matriz2):
        raise ValueError("Número de colunas da primeira matriz não é igual ao número de linhas da segunda matriz")

    resultado = [[0 for _ in range(len(matriz2[0]))] for _ in range(len(matriz1))]

    for i in range(len(matriz1)):
        for j in range(len(matriz2[0])):
            for k in range(len(matriz2)):
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]

    cont_thread-=1
    return resultado

#faca uma funcao para fatorial
def fatorial(n):
    global cont_thread
    if n == 0:
        return 1
    else:
        cont_thread-=1
        return n * fatorial(n-1)
    

#faca uma funcao para calcula primo
def primo(n):
    global cont_thread
    mult=0
    for count in range(2,n):
        if (n % count == 0):
            mult += 1
    if(mult==0):
        cont_thread-=1
        return print(f'eh primo {n}', True)
    else:
        cont_thread-=1
        return print(f'nao eh primo {n}', False)

_thread.start_new_thread(bubble_sort, ([5, 3, 8, 1, 2],))
_thread.start_new_thread(soma_matrizes, ([[1, 2], [3, 4]], [[5, 6], [7, 8]]))
_thread.start_new_thread(multiplicar_matrizes, ([[1, 2], [3, 4]], [[5, 6], [7, 8]]))
_thread.start_new_thread(fatorial, (5,))
_thread.start_new_thread(primo, (7,))
# Loop principal
while(cont_thread > 0 ):
    pass