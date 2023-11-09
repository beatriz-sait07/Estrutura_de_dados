#Aula de herança multiplas
#Estenção do vscode para python Autodocstring, mostra o que a funcao realiza
# nome:<string>, idade: int =idade, numero: int numero da conta cc, saldo: float - saldo inicial da conta
 

class Pessoa:
        def _init_(self, nome, idade):
            self.name = name
            self.age= age
            
class Conta:
    def _init_(self, numero, saldo = 0):
        self.numero = numero
        self.saldo = saldo

    def deposito(self, valor):
        self.saldo += numero

    def sacar(self, valor):
        if self.saldo >= valor:
            self.saldo -= numero
        else:
            print("Saldo insuficiente!")

class Cliente(Pessoa, Conta):
        def _init_(self, nome, idade, numero, saldo):
           	Pessoa._init_(self, nome, idade)
            Conta._init_(self, numero, saldo)

        def _str_(self):
            return f"{self.nome}, {self,idade}, CC{self.numero}, Saldo: R${self.saldo:.2f}"

class Funcionario(Pessoa):
    def _init_(self, nome, idade, salario):
        Pessoa._init_(self, nome, idade)
        self.salario= salario

    def aumentarSalario(self, valor):
        self.salario += valor

    def _str_(self):
        return f"{self.nome}, {self.idade}, R$ {self.salario}"

class FuncCC(Funcionario):
    def _init_(self, nome, idade, salario):
        Funcionario._init_(self, nome, idade, salario)
        Conta._init_(self, numero, saldo)

class Diretor(FuncCC):
    def _init_(self, nome, idade, salario, bonifica, salario= 0):
        Funcionario._init_(self, nome, idade, salario)
        Conta._init_(self, numero, saldo)
        self.bonifica = self.salario * 1.20
        self.nivel = nivel

    def login(self):
        pass

class Gerente(FuncCC):
    def _init_(self, nome, idade, salario, bonifica, salario):
        Funcionario._init_(self, nome, idade, salario):
        Conta._init_(self, numero, saldo):
        self.bonifica = self.salario * 1.10
        self.nivel = nivel

    def login(self):
        pass

        

class ContaCC(Conta):
    def _init_(self, numero, saldo, digito):
        self.digito = digito
        Pessoa._init_(self, nome, idade)
        Conta._init_(self, numero, saldo)

class ContaPP(Conta):
    def _init_(self, numero, saldo):
        Pessoa._init_(self, nome, idade)
        Conta._init_(self, numero, saldo)

        pass
cliente_carlos=cliente("Carlos", 23, 2345, 1300)
print(cliente_carlos)
