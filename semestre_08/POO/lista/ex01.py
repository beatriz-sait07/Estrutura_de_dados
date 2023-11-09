class Funcionario:
    def __init__(self, nome: str, cpf: str, salario: float, departamento: str):
        self.nome = nome
        self.cpf = cpf
        self._salario = salario 
        self.departamento = departamento

    @property
    def salario(self):
        return self._salario

    @salario.setter
    def salario(self, novoSalario: float):
        self._salario = novoSalario

    def bonificar(self):
        self._salario = self._salario * 1.10

    def __repr__(self):
        return f"Funcionario({self.nome}, {self._salario})"


class Gerente(Funcionario):
    def __init__(self, nome: str, cpf: str, salario: float, departamento: str, senha: str, n_func: int):
        super().__init__(nome, cpf, salario, departamento)
        self.__senha = senha
        self.n_func = n_func

    def bonificar(self):
        self._salario = self._salario * 1.15

    @property
    def senha(self):
        return self.__senha

    @senha.setter
    def senha(self, novaSenha):
        if len(novaSenha) >= 6:
            self.__senha = novaSenha
        else:
            print("A senha deve ter no mínimo 6 caracteres.")

    def autenticarSenha(self, senha: str):
        return self.__senha == senha

    def __repr__(self):
        return f"Gerente({self.nome}, {self.salario}, {self.n_func})"

f = Funcionario(
    nome="Maria",
    cpf="068.068.073-59",
    departamento="Programação",
    salario=2700,
)

g = Gerente(
    nome="João Paulo",
    cpf="123.123.123-1",
    departamento="Programação",
    salario=5000,
    senha="123456",
    n_func = 8,
)

print(f"Funcionario(a): {f.nome}")
print(f"CPF: {f.cpf}")
print(f"Departamento: {f.departamento}")
print(f"Salario: {f.salario}")

f.bonificar()
print("FUNCIONÁRIO(A) BONIFICADO!")
print(f"Salario após a bonificação: {f.salario}")
print("\n")

print(f"Gerente: {g.nome}")
print(f"CPF: {g.cpf}")
print(f"Departamento: {g.departamento}")
print(f"Salario: {g.salario}")
print(f"Senha: {g.senha}")

g.bonificar()
print("GERENTE BONIFICADO!")
print(f"Salario após a bonificação: {g.salario}")
print("\n")

print("Autenticar gerente:")
senha = input("Senha do gerente: ")

if g.autenticarSenha(senha):
    print("Autenticado com sucesso.")
else:
    print("Senha incorreta.")
