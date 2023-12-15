class Pessoas:
    def __init__(self):
        self.nomes = []

    def inserir_nome(self, nome):
        self.nomes.append(nome)
        self.nomes.sort()

    def obter_nome_na_posicao(self, posicao):
        try:
            nome = self.nomes[posicao]
            return nome
        except IndexError:
            return f"Posição {posicao} inválida. A lista contém {len(self.nomes)} elementos."

    def imprimir_lista(self):
        print("Lista de nomes:", self.nomes)

pessoas = Pessoas()
pessoas.inserir_nome("Saito")
pessoas.inserir_nome("Taynan")
pessoas.inserir_nome("Maria")

posicao_valida = 1
nome_na_posicao_valida = pessoas.obter_nome_na_posicao(posicao_valida)
print(f"Nome na posição {posicao_valida}: {nome_na_posicao_valida}")

posicao_invalida = 10
nome_na_posicao_invalida = pessoas.obter_nome_na_posicao(posicao_invalida)
print(nome_na_posicao_invalida)


pessoas.imprimir_lista()
