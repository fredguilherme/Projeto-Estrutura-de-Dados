from sys import maxsize as MAXSIZE
from itertools import permutations
V = 4

def calcula_menor_rota(grafo, ini):
    vertices = []
    for i in range(V):
        if i != ini:
            vertices.append(i)
 
    peso_minimo = MAXSIZE
    permutacao = permutations(vertices)
    menor_rota = []
    ant_sum = MAXSIZE

    for i in permutacao:
        peso_rota_atual = 0
        src = ini
        for j in i:
            peso_rota_atual += grafo[src][j]
            src = j

        peso_rota_atual += grafo[src][ini]
        if peso_rota_atual<ant_sum:
            ant_sum = peso_rota_atual
            menor_rota.insert(0, i)
        peso_minimo = min(peso_minimo, peso_rota_atual)

    return peso_minimo, menor_rota[0]

if __name__ == "__main__":

    # representação da matriz do grafo
    grafo = [
        [0, 10, 15, 20], 
        [10, 0, 35, 25],
        [15, 35, 0, 30], 
        [20, 25, 30, 0]
    ]

    ini = 2

    resultado = list(calcula_menor_rota(grafo, ini))
    print('Ponto de partida: Cidade {} \nOrdem de visita às cidades: {} \nDistância que será percorrida: {} km'.format(ini, resultado[1], resultado[0]))