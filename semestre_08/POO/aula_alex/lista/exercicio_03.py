class Ladolnvalido(Exception):
    pass

class Triangulo:
    def __init__(self, lado_a, lado_b, lado_c):
        self._lado_a = None
        self._lado_b = None
        self._lado_c = None
        self.set_lados(lado_a, lado_b, lado_c)

    def get_lado_a(self):
        return self._lado_a

    def set_lado_a(self, valor):
        self._validar_lados(valor, self._lado_b, self._lado_c)
        self._lado_a = valor

    def get_lado_b(self):
        return self._lado_b

    def set_lado_b(self, valor):
        self._validar_lados(self._lado_a, valor, self._lado_c)
        self._lado_b = valor

    def get_lado_c(self):
        return self._lado_c

    def set_lado_c(self, valor):
        self._validar_lados(self._lado_a, self._lado_b, valor)
        self._lado_c = valor

    def _validar_lados(self, a, b, c):
        if a is not None and b is not None and c is not None:
            if a >= b + c or b >= a + c or c >= a + b:
                raise Ladolnvalido("Os lados do triângulo são inválidos.")

try:
    triangulo1 = Triangulo(3, 4, 5)
    print(f"Lados do triângulo 1: {triangulo1.get_lado_a()}, {triangulo1.get_lado_b()}, {triangulo1.get_lado_c()}")

    triangulo1.set_lado_c(10)
except Ladolnvalido as e:
    print(f"Erro: {e}")

try:

    triangulo2 = Triangulo(3, 7, 8)
except Ladolnvalido as e:
    print(f"Erro: {e}")
