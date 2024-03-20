import _thread

# Variável de controle para o loop infinito
keep_running = True

# Função para imprimir números pares de 0 a 10
def imprimir_par():
    for i in range(0, 10, 2):
        print(i)

# Função para imprimir números ímpares de 0 a 10
def imprimir_impar():
    for i in range(1, 10, 2):
        print(i)

# Iniciar as threads
_thread.start_new_thread(imprimir_par, ())
_thread.start_new_thread(imprimir_impar, ())

# Loop principal
while keep_running:
    # Podemos adicionar alguma condição para sair do loop, como uma entrada do usuário
    user_input = input("Pressione 'q' para sair: ")
    if user_input == 'q':
        keep_running = False
