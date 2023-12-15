class Idades:
    def __init__(self):
        self.idades = []

    def inserir_idade(self, idade):
        if not isinstance(idade, (int, float)):
            raise TypeError("A idade deve ser um valor numérico.")
        
        self.idades.append(idade)

    def calcular_media(self):
        if not self.idades:
            return 0  

        media = sum(self.idades) / len(self.idades)
        return media

idades = Idades()

try:
    idades.inserir_idade(23)
    idades.inserir_idade(19)
    idades.inserir_idade(12)
    idades.inserir_idade(26)
    idades.inserir_idade("vinte e quatro")
except TypeError as e:
    print(f"Erro: {e}")

media_idades = idades.calcular_media()
print(f"Média das idades: {media_idades}")
