from time import sleep

def ask_limit():
    # Quantos números da sequência serão considerados
    print_text = "[#] Digite o tamanho da lista de Fibonnaci: "

    limit = int(input(print_text))

    while limit < 2:
        print("\n[!] O número precisa ser um inteiro maior ou igual a dois!\n")
        sleep(1)
        limit = int(input(print_text))

    return limit

# Forma recursiva. Complexidade: n - 2, sendo n o tamanho da lista
def generate_fibonacci_recursive(limit: int, sequence: list = [1, 1]):
    if len(sequence) >= limit:
        print_list(sequence, "Forma recursiva")
        return
        
    sum = sequence[-1] + sequence[-2]
    sequence.append(sum)
    generate_fibonacci_recursive(limit, sequence)

# Forma imperativa. Complexidade: n - 2, sendo n o tamanho da lista
def generate_fibonacci_imperative(limit: int):
    sequence = [1, 1]

    while 1:
        if len(sequence) >= limit:
            break

        sum = sequence[-1] + sequence[-2]
        sequence.append(sum)

    print_list(sequence, "Forma imperativa")

def print_list(list: list, type: str):
    for i in range(len(list)):
        print(list[i], end="")
        if i == len(list) - 1:
            print(".")
        else:
            print(", ", end="")

limit = ask_limit()
generate_fibonacci_recursive(limit)
generate_fibonacci_imperative(limit)