from math import ceil
from time import sleep

def ask_limit():
    # Quantos números da sequência serão considerados
    print_text = "[#] Digite o tamanho da sequência da espiral triangular: "

    limit = int(input(print_text))

    while limit < 1:
        print("\n[!] O número precisa ser um inteiro maior ou igual a um!\n")
        sleep(1)
        limit = int(input(print_text))

    return limit

def make_espiral(limit: int):
    list = [(0, 0)]
    if limit == 0:
        return list

    for i in range(limit - 1):
        coordinate = (0,0)
        if i == 0:
            list.append((1, 0))
            continue
        cicle = ceil(i / 3)

        if i % 3 == 1:
            coordinate = (cicle, cicle)
        elif i % 3 == 2:
            coordinate = (-2*cicle, -cicle)
        else:
            coordinate = (2*cicle+1, -cicle)
        list.append(coordinate)
    print("\n[#] Pontos da espiral triangular:\n    ", end="")
    print(f"{str(list)[1:-1]}.")

limit = ask_limit()
make_espiral(limit)