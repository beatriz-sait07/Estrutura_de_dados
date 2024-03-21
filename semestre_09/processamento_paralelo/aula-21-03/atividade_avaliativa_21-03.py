from random import randint
import _thread
import time
import threading

def soma_matrizes(matriz1, matriz2, output_file):
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
    
    cont_thread_lock.acquire()
    cont_thread -= 1
    if cont_thread == 0:
        exit_event.set()
    cont_thread_lock.release()

    with open(output_file, 'a') as f:
        f.write("Soma das matrizes:\n")
        for linha in soma:
            f.write(' '.join(map(str, linha)) + '\n')
        f.write('\n')

def sub_matrizes(matriz1, matriz2, output_file):
    global cont_thread
    # Verifica se as matrizes têm o mesmo tamanho
    if len(matriz1) != len(matriz2) or len(matriz1[0]) != len(matriz2[0]):
        return "As matrizes têm tamanhos diferentes e não podem ser subtraidas."

    # Inicializa uma matriz para armazenar a soma
    sub = []

    for i in range(len(matriz1)):
        linha_sub = []
        for j in range(len(matriz1[0])):
            linha_sub.append(matriz1[i][j] - matriz2[i][j])
        sub.append(linha_sub)
    
    cont_thread_lock.acquire()
    cont_thread -= 1
    if cont_thread == 0:
        exit_event.set()
    cont_thread_lock.release()

    with open(output_file, 'a') as f:
        f.write("subtracao das matrizes:\n")
        for linha in sub:
            f.write(' '.join(map(str, linha)) + '\n')
        f.write('\n')

def multiplicar_matrizes(matriz1, matriz2, output_file):
    global cont_thread
    if len(matriz1[0]) != len(matriz2):
        raise ValueError("Número de colunas da primeira matriz não é igual ao número de linhas da segunda matriz")

    resultado = [[0 for _ in range(len(matriz2[0]))] for _ in range(len(matriz1))]

    for i in range(len(matriz1)):
        for j in range(len(matriz2[0])):
            for k in range(len(matriz2)):
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]

    cont_thread_lock.acquire()
    cont_thread -= 1
    if cont_thread == 0:
        exit_event.set()
    cont_thread_lock.release() 

    with open(output_file, 'a') as f:
        f.write("Produto das matrizes:\n")
        for linha in resultado:
            f.write(' '.join(map(str, linha)) + '\n')
        f.write('\n')

def maiores_elementos(matriz, output_file):
    global cont_thread
    maiores = []
    for i in range(5):
        maior = matriz[0][0]
        for linha in matriz:
            for elemento in linha:
                if elemento > maior and elemento not in maiores:
                    maior = elemento
        maiores.append(maior)
    cont_thread_lock.acquire() # Adquirir o lock para alterar a variável de controle
    cont_thread -= 1
    if cont_thread == 0:
        exit_event.set()
    cont_thread_lock.release() # Liberar o lock após alterar a variável de controle

    with open(output_file, 'a') as f:
        f.write("Cinco maiores elementos:\n")
        f.write(', '.join(map(str, maiores)) + '\n')

def moda(matriz, output_file):
    global cont_thread
    moda = {}
    for linha in matriz:
        for elemento in linha:
            if elemento in moda:
                moda[elemento] += 1
            else:
                moda[elemento] = 1
    moda = max(moda, key=moda.get)
    cont_thread_lock.acquire()
    cont_thread -= 1
    if cont_thread == 0:
        exit_event.set()
    cont_thread_lock.release()

    with open(output_file, 'a') as f:
        f.write(f'Moda da matriz: {moda}\n')


# Inicializa as matrizes
matriz1 = [[randint(0, 100) for _ in range(1000)] for _ in range(1000)]
matriz2 = [[randint(0, 100) for _ in range(1000)] for _ in range(1000)]

# Inicializa a variável de controle e o lock
cont_thread = 5
cont_thread_lock = threading.Lock()
exit_event = threading.Event()

# Inicializa o arquivo de saída
output_file = 'output.txt'
with open(output_file, 'w') as f:
    f.write('')

# Iniciar as threads
_thread.start_new_thread(soma_matrizes, (matriz1, matriz2, output_file))
_thread.start_new_thread(sub_matrizes, (matriz1, matriz2, output_file))
_thread.start_new_thread(multiplicar_matrizes, (matriz1, matriz2, output_file))
_thread.start_new_thread(maiores_elementos, (matriz1, output_file))
_thread.start_new_thread(moda, (matriz1, output_file))

# Aguardar pela conclusão de todas as threads
exit_event.wait()

print("Todas as operações concluídas.")
