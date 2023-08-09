class Conta:
    
    def __init__(self, titular, numero, saldo, limite):
        print(f'inicializando a conta {titular}, Bem vindo(a)!')
        self.titular = titular
        self.numero = numero
        self.saldo = saldo
        self.limite = limite
        
    
def sacar(saldo, limite, valor):
    valor = float('quanto voce deseja sacar: R$ ')
    
    if valor < (limite + saldo):
        print('ERRO AO SACAR')
    else:
        print('saque R$ {valor:.2f}')
        saldo = saldo - valor
    
    
def depositar(saldo, valor):
    
            
    