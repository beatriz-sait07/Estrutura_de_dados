class Investimento:
    def __init__(self, saldo_inicial, taxa_juros):
        self.saldo = saldo_inicial
        self.taxa_juros = taxa_juros / 100  

    def adicionaJuros(self):
        juros = self.saldo * self.taxa_juros
        self.saldo += juros

conta_poupanca = Investimento(1000.00, 10)

for _ in range(5):
    conta_poupanca.adicionaJuros()

print(f"Saldo após a aplicação de juros: R${conta_poupanca.saldo:.2f}")
