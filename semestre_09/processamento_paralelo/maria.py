import random

#defindo a funÃ§Ã£o F(x)
def F(x):
    return x

tempo = 1800
frame_por_segundo = 30
resolicao_width = 3840
resolucao_height = 2160

#calculando o total de frame e pixels
total_frames = tempo * frame_por_segundo
total_pixels = resolicao_width * resolucao_height

#criando uma lista para armazenar os valores de f(x)
f_values = []

#calculando os valores de f(x) para cada pixel em cada frame
for frame in range(total_frames): #para cada frame
    for pixel in range(total_pixels): #para cada pixel 
        r, g, b = [random.randint(0, 255) for _ in range(3)] #gerando valores aleatÃ³rios para r, g e b
        f_x = F([r, g, b]) #calculando o valor de f(x) para r, g e b
        f_values.append(f_x) #adicionando o valor de f(x) na lista f_values

        print(f_values)

