import timeit
def soma_matrizes(matriz1, matriz2):
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

    return soma

def soma_matrizes_refatorada(matriz1, matriz2):
    # Encontra o menor número de linhas e colunas entre as duas matrizes
    linhas = min(len(matriz1), len(matriz2))
    colunas = min(len(matriz1[0]), len(matriz2[0]))

    # Inicializa uma matriz para armazenar a soma
    soma = []

    for i in range(linhas):
        linha_soma = []
        for j in range(colunas):
            linha_soma.append(matriz1[i][j] + matriz2[i][j])
        soma.append(linha_soma)

    # Adiciona as partes restantes da matriz maior à soma
    for i in range(linhas, len(matriz1)):
        linha_soma = []
        for j in range(colunas, len(matriz1[0])):
            linha_soma.append(matriz1[i][j])
        soma.append(linha_soma)

    for i in range(linhas, len(matriz2)):
        linha_soma = []
        for j in range(colunas, len(matriz2[0])):
            linha_soma.append(matriz2[i][j])
        soma.append(linha_soma)

    return soma


# Exemplo de uso:
matriz_4x4 = [
    [2, 4, 6, 8],
    [1, 3, 5, 7],
    [9, 11, 13, 15],
    [10, 12, 14, 16]
]

# Matriz 5x4 com números diferentes
matriz_5x4 = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [10, 20, 30, 40],
    [15, 25, 35, 45],
    [11, 12, 13, 14]
]


#resultado = soma_matrizes(matriz_4x4, matriz_5x4)
resultado1 = soma_matrizes_refatorada(matriz_4x4, matriz_5x4)

for linha in resultado1:
    print(linha)
