import timeit

def exibir_01(vet):
    print("exibicao do nucleo 01!")
    id_n = 0
    for varredura in vet:
        print(f"{id_n} -> {varredura}")

def exibir_02(vet, intercalacao=2):
    print("exibicao do nucleo 02!")
    id_dir = 0
    id_esq = 1
    vet_original = vet;
    novo_vet = []
    for i in range(0, len(vetor), intercalacao):
        vet_original.remove(i)
        novo_vet.append(i)

    for varredura in vet_original:
        print(f"{id_dir} -> {varredura}")
    for varredura in novo_vet:
        print(f"{id_esq} -> {varredura}")


def exibir_03(vet, intercalacao=3):
    print("exibicao do nucleo 03!")
    id_01 = 0
    id_02 = 1
    id_03 = 2

    vet1 = vet[id_01:len(vet):intercalacao]
    vet2 = vet[id_02:len(vet):intercalacao]
    vet3 = vet[id_03:len(vet):intercalacao]

    for varredura in vet1:
        print(f"{id_01} -> {varredura}")
    for varredura in vet2:
        print(f"{id_02} -> {varredura}")
    for varredura in vet3:
        print(f"{id_03} -> {varredura}")



def exibir_04(vet, intercalacao=4):
    print("exibicao do nucleo 04!")
    id_01 = 0
    id_02 = 1
    id_03 = 2
    id_04 = 3

    vet1 = vet[id_01:len(vet):intercalacao]
    vet2 = vet[id_02:len(vet):intercalacao]
    vet3 = vet[id_03:len(vet):intercalacao]
    vet4 = vet[id_04:len(vet):intercalacao]

    for varredura in vet1:
        print(f"{id_01} -> {varredura}")
    for varredura in vet2:
        print(f"{id_02} -> {varredura}")
    for varredura in vet3:
        print(f"{id_03} -> {varredura}")
    for varredura in vet4:
        print(f"{id_04} -> {varredura}")


vetor = [i for i in range(10000000)]
#exibir_04(vetor)
time_execucao = timeit.timeit(stmt="exibir_04(vetor)", setup="from __main__ import exibir_04, vetor", number=1)
print("Tempo de execução da função exibir_04:", time_execucao, "segundos")

#2.8s para 1000000
