class Pessoa:
    def __init__(self, nome: str, idade: float):
        self.nome = nome
        self.idade = idade

# ---------------------------CLASSE CONTA---------------------------------------
class Conta:
    def __init__(self, numero: int, saldo: float):
        self.numero = numero
        self.saldo = saldo

    def depositar(self, valor: float):
        self.saldo += valor

    def sacar(self, valor: float):
        if self.saldo < valor:
            print("Saldo insuficiente")
        else:
            self.saldo -= valor

# --------------------------CLASSE CLIENTE----------------------------------------
class Cliente(Pessoa, Conta):
    def __init__(self, nome: str, idade: float, numero: int, saldo: float):
        Pessoa.__init__(self, nome, idade)
        Conta.__init__(self, numero, saldo)

    def aumentar_saldo(self, aumento: float):
        self.saldo += aumento

    def __repr__(self):
        return f"Cliente({self.nome}, Idade: {self.idade}, CC: {self.numero}, Saldo: R${self.saldo})"

# ---------------------------CLASSE FUNCIONARIO---------------------------------------
class Funcionario(Pessoa):
    def __init__(self, nome: str, idade: float, salario: float):
        Pessoa.__init__(self, nome, idade)
        self.salario = salario

    def aumentar_salario(self, aumento: float):
        self.salario += aumento

    def __repr__(self):
        return f"Funcionario({self.nome}, {self.idade}, Salário: {self.salario})"

# ---------------------------CLASSE TIPO CONTA---------------------------------------
class FuncCC(Funcionario, Conta):
    def __init__(self, nome: str, idade: float, salario: float, numero: int, saldo: float):
        Funcionario.__init__(self, nome, idade, salario)
        Conta.__init__(self, numero, saldo)

# ---------------------------CLASSE LOGIN---------------------------------------
class Login:
    def __init__(self, login):
        self.__login = login

    @property
    def login(self):
        return self.__login

    @login.setter
    def login(self, nv_login):
        self.__login = nv_login

    def autentica_login(self, login):
        return self.__login == login
    
    
# ---------------------------CLASSE NIVEL---------------------------------------
class Nivel:
    def __init__(self, nivel):
        self.nivel = nivel

    def verificacao_nivel(self):
        if self.nivel == "Funcionario":
            return "Iniciante"
        elif self.nivel == "Gerente":
            return "Intermediário"
        elif self.nivel == "Diretor":
            return "Avançado"
        else:
            return "Nível não especificado"

    def __repr__(self):
        return f"Nivel({self.nivel}: {self.verificacao_nivel()})"

# ---------------------------CLASSE DIRETOR---------------------------------------
class Diretor(FuncCC, Login, Nivel):
    def __init__(self, nome, idade, salario, numero, bonifica, nivel, login: str, saldo=0):
        FuncCC.__init__(self, nome, idade, salario, numero, saldo)
        Login.__init__(self, login)
        Nivel.__init__(self, nivel)
        
        # Aplica a bonificação diretamente no salário
        self.salario *= 1.15

        self.nivel = self.verificacao_nivel()

    def __repr__(self):
        return f"Diretor({self.nome}, {self.idade}, Salário: {self.salario}, CC: {self.numero}, Nível: {self.nivel})"

# ---------------------------CLASSE GERENTE---------------------------------------
class Gerente(FuncCC, Login, Nivel):
    def __init__(self, nome: str, idade: int, salario: float, numero: int, bonifica: float, nivel, login: str, saldo=0):
        FuncCC.__init__(self, nome, idade, salario, numero, saldo)
        Login.__init__(self, login)
        Nivel.__init__(self, nivel)
        
        # Aplica a bonificação diretamente no salário
        self.salario *= 1.15

        self.nivel = self.verificacao_nivel()

    def __repr__(self):
        return f"Gerente({self.nome}, {self.idade}, Salário: {self.salario}, CC: {self.numero}, Nível: {self.nivel})"

# ---------------------------MAIN---------------------------------------

diretor = Diretor("João", 40, 5000, 123, 1000, "Diretor", "joao_login", 500)
gerente = Gerente("Maria", 35, 4000, 456, 800, "Gerente", "maria_login", 300)

print(diretor.nivel)  # Saída: Avançado
print(gerente.nivel)  # Saída: Intermediário
