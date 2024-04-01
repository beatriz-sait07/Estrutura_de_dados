from random import randint
import threading
from concurrent.futures import ThreadPoolExecutor

def soma_matrizes(matriz1, matriz2, output_file):
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

    with open(output_file, 'a') as f:
        f.write("Soma das matrizes:\n")
        for linha in soma:
            f.write(' '.join(map(str, linha)) + '\n')
        f.write('\n')

def sub_matrizes(matriz1, matriz2, output_file):
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

    with open(output_file, 'a') as f:
        f.write("Subtração das matrizes:\n")
        for linha in sub:
            f.write(' '.join(map(str, linha)) + '\n')
        f.write('\n')

def multiplicar_matrizes(matriz1, matriz2, output_file):
    if len(matriz1[0]) != len(matriz2):
        raise ValueError("Número de colunas da primeira matriz não é igual ao número de linhas da segunda matriz")

    resultado = [[0 for _ in range(len(matriz2[0]))] for _ in range(len(matriz1))]

    for i in range(len(matriz1)):
        for j in range(len(matriz2[0])):
            for k in range(len(matriz2)):
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]

    with open(output_file, 'a') as f:
        f.write("Produto das matrizes:\n")
        for linha in resultado:
            f.write(' '.join(map(str, linha)) + '\n')
        f.write('\n')

def maiores_elementos(matriz, output_file):
    maiores = []
    for i in range(5):
        maior = matriz[0][0]
        for linha in matriz:
            for elemento in linha:
                if elemento > maior and elemento not in maiores:
                    maior = elemento
        maiores.append(maior)

    with open(output_file, 'a') as f:
        f.write("Cinco maiores elementos:\n")
        f.write(', '.join(map(str, maiores)) + '\n')

def moda(matriz, output_file):
    moda = {}
    for linha in matriz:
        for elemento in linha:
            if elemento in moda:
                moda[elemento] += 1
            else:
                moda[elemento] = 1
    moda = max(moda, key=moda.get)

    with open(output_file, 'a') as f:
        f.write(f'Moda da matriz: {moda}\n')

# Inicializa as matrizes
matriz1 = [[randint(0, 100) for _ in range(1000)] for _ in range(1000)]
matriz2 = [[randint(0, 100) for _ in range(1000)] for _ in range(1000)]

# Inicializa o arquivo de saída
output_file = 'output.txt'
with open(output_file, 'w') as f:
    f.write('')

# Iniciar as threads utilizando ThreadPoolExecutor
with ThreadPoolExecutor(max_workers=5) as executor:
    executor.submit(soma_matrizes, matriz1, matriz2, output_file)
    executor.submit(sub_matrizes, matriz1, matriz2, output_file)
    executor.submit(multiplicar_matrizes, matriz1, matriz2, output_file)
    executor.submit(maiores_elementos, matriz1, output_file)
    executor.submit(moda, matriz1, output_file)

print("Todas as operações concluídas.")
