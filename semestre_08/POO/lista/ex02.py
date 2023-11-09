class FormaGeo:
    def __init__(self, area=0, perimetro=0):
        self.area = area
        self.perimetro = perimetro
        
class Retangulo(FormaGeo):
    def __init__(self, base, altura):
        super().__init__()
        self.base = base
        self.altura = altura
        
    def calculaArea(self):
        self.area = self.base * self.altura
        
    def calculaPerimetro(self):
        self.perimetro = 2 * (self.base + self.altura)
        
class Triangulo(FormaGeo):
    def __init__(self, base, altura):
        super().__init__()
        self.base = base
        self.altura = altura
        
    def calculaArea(self):
        self.area = 0.5 * self.base * self.altura
        
    def calculaPerimetro(self):
        pass
    
Retangulo = Retangulo(1, 2)
Triangulo = Triangulo(3, 4)

Retangulo.calculaArea()
Triangulo.calculaArea()

print("area do retangulo: ", Retangulo.area)
print("area do triangulo: ", Triangulo.area)