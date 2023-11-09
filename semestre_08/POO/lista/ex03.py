class Atleta:
    def __init__(self, nome):
        self.nome = nome

    def aposentar(self):
        print(f"{self.nome} Aposentado")

    def aquecer(self):
        print(f"{self.nome} Aquecendo")
        

class AtletaAposentado(Atleta):
    pass

class Nadador(Atleta):
    def nadar(self):
        print(f"{self.nome} nadando")
        
class Ciclista(Atleta):
    def pedalar(self):
        print(f"{self.nome} pedalando")
        
class Corredor(Atleta):
    def correr(self):
        print(f"{self.nome} correndo")
    
class TriAtleta(Atleta):
    def __init__(self, nome):
        super().__init__(nome)
        self.nadador = Nadador(nome)
        self.ciclista = Ciclista(nome)
        self.corredor = Corredor(nome)
        
    def nadar(self):
        self.nadador.nadar()
        
    def pedalar(self):
        self.ciclista.pedalar()
        
    def correr(self):
        self.corredor.correr()
        

if __name__ == "__main__":
    atleta1 = Atleta("Saito")
    atleta1.aquecer()

    atleta2 = AtletaAposentado("Taynan")
    atleta2.aposentar()

    nadador1 = Nadador("Lucas")
    nadador1.nadar()

    ciclista1 = Ciclista("Maria")
    ciclista1.pedalar()

    corredor1 = Corredor("Borges")
    corredor1.correr()

    triatleta1 = TriAtleta("Roza")
    triatleta1.aquecer()
    triatleta1.nadar()
    triatleta1.pedalar()
    triatleta1.correr()
