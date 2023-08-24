class Fracao:
    def __init__(self, numerador: int, denominador:int) -> None:
        self.numerador = numerador
        self.denominador = denominador
        
    def soma(self, outra: "Fracao") -> "Fracao": #ja que a funcao fracao nao foi conluida usamos "" para nao dar erro no interpretador
        return Fracao(
            self.numerador * outra.denominador + 
                self.denominador * outra.numerador,
            self.denominador * outra.denominador
                )
    
    def mult(self, outra: "Fracao") -> "Fracao":
        return Fracao(
            self.numerador * outra.numerador, 
                self.denominador * outra.denominador,
                )
    
    def __repr__(self) -> str:
        return f'{self.numerador}/{self.denominador}'
    
    
f1 = Fracao(1,2)
f2 = Fracao(3, 4)
f3 = f1.soma(f2)
f4 = f1.mult(f2)
print(f'{f1} + {f2}  = {f3}')
print(f'{f1} * {f2}  = {f4}')