class Funcionario():
    def __init__(self, nome:str, cpf:str, salario:float, departamento:str) -> None:
        self.nome = nome
        self.cpf = cpf
        self._salario = salario #rotegido
        self.departamento = departamento
        
    
    def __repr__(self) -> str:
        return f"Funcionario {self.nome}, {self.salario}"
        
    @property
    def salario(self):
        return self._salario

    @salario.setter
    def salario(self, nv_salario):
        pass
    
    def bonificar(self):
        self._salario = self._salario * 1.10
        
    def __repr__(self) -> str:
        return f"Funcionario {self.nome}, {self.salario}"
    
class Gerente(Funcionario):
    def __init__(self, nome: str, cpf: str, salario: float, departamente: str, senha:str, n_func:int) -> None:
        super().__init__(nome, cpf, salario, departamente)
        self.senha = senha
        self.n_func = n_func
        
        
    def bonificar(self):
        self._salario = self._salario * 1.15
        # _salario eh protegido, significando que as classes bases e subclasses podem acessesa-las
        # __salarios, seria privados, assim apenas a classe base teria acesso.
    
    @property
    def senha(self):
        return self.__senha
    
    @senha.setter
    def senha(self, nv_senha):
        if(len(nv_senha) >= 8):
            self.__senha = nv_senha
    
    def autentica_senha(self, senha:str) -> bool:
        return self.__senha == senha
        
    def __repr__(self) -> str:
        return f"Gerente {self.nome}, {self.salario}, {self.n_func}"
        
        

#--------------------------MAIN-------------------------------------
g = Gerente("João", "123.123.123-3", 3000, "TI", "12345678", 2)

print(g)


'''senha = input('Senha: ')
if(g.autentica_senha(senha)):
    '''