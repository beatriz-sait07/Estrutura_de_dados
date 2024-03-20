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

def dividir_matriz_em_quatro(matriz):
    n = len(matriz)
    meio_linhas = n // 2
    meio_colunas = len(matriz[0]) // 2

    # Dividindo a matriz em quatro partes
    bloco1 = [linha[:meio_colunas] for linha in matriz[:meio_linhas]]
    bloco2 = [linha[meio_colunas:] for linha in matriz[:meio_linhas]]
    bloco3 = [linha[:meio_colunas] for linha in matriz[meio_linhas:]]
    bloco4 = [linha[meio_colunas:] for linha in matriz[meio_linhas:]]

    return bloco1, bloco2, bloco3, bloco4

# Exemplo de uso:
matriz1 = [[1, 2, 3, 11],
           [4, 5, 6, 12],
           [7, 8, 9, 13],
           [18, 19, 20, 21]]

blocos = dividir_matriz_em_quatro(matriz1)
for bloco in blocos:
    for linha in bloco:
        print(linha)
    print("----")

# Exemplo de uso:
matriz1 = [[1, 2, 3],
           [4, 5, 6],
           [7, 8, 9]]

matriz2 = [[9, 8, 7],
           [6, 5, 4],
           [3, 2, 1]]

resultado = dividir_matriz_em_quatro(matriz1, matriz2)

for i in range(0, 1000):
    timeit.timeit(dividir_matriz_em_quatro)