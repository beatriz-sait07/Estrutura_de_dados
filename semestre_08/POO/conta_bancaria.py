import datetime

class Cliente:
    
    def __init__(self, nome, cpf, data) -> None:
        self.nome = nome
        self.cpf = cpf
        self.data = data
        
    def __repr__(self) -> str:
        return f'{self.nome}, {self.cpf}, {self.data}'

class Conta:

    def __init__(self, agencia, numero, saldo, cliente) -> None:
        self.agencia = agencia
        self.numero_conta = numero
        self.saldo = saldo
        self.cliente = cliente

    def depositar(self, valor):
        if valor > 0:
            self.saldo += valor
            return True
        else:
            return False

    def sacar(self, valor):
        if valor <= self.saldo:
            self.saldo -= valor   
            return True
        else:
            return False
        
    def transferir(self, valor, destinatario, agencia_dest, conta_dest):
        if self.sacar(valor):
            destinatario.depositar(valor)
            return True
        else:
            return False

cliente1 = Cliente("João", "123.456.789-00", '10/08/2023')
cliente2 = Cliente("Maria", "987.654.321-00", datetime.datetime.now())

conta1 = Conta("001", "12345", 1000, cliente1)
conta2 = Conta("001", "67890", 500, cliente2)

conta1.transferir(200, conta2, "001", "67890")
print(conta1.saldo)
print(conta2.saldo)
