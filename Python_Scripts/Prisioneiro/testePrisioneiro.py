import numpy as np
import random as rd

class Prisioneiro:
    numerosDisponiveis = [x for x in range(1, 101)] #static variable
    
    def __init__(self):
        self.numero = rd.choice(Prisioneiro.numerosDisponiveis)
        self.achou_numero = False
        Prisioneiro.numerosDisponiveis.remove(self.numero)

    def getNumber(self):
        return self.numero

class Caixa:
    numeros = [x for x in range(1, 51)]
    contagem = 1
    def __init__(self):
        self.id = Caixa.contagem
        Caixa.contagem = Caixa.contagem + 1
        self.numero = rd.choice(Caixa.numeros)
        Caixa.numeros.remove(self.numero)
    
    def getId(self):
        return self.id
    def getNumber(self):
        return self.numero

def gerarPrisioneiros():
    return [Prisioneiro() for x in list(range(100))]

def gerarCaixas():
    return [Caixa() for x in list(range(50))]


def main():
    prisioneiros = gerarPrisioneiros()
    caixas = gerarCaixas()

    print("--- Prisioneiros ---")
    for p in prisioneiros:
        print(f'Prisioneiro: {p.getNumber()}')

    print("--- Caixas ---")
    for c in caixas:
        print(f'Caixa_id: {c.getId()}, Caixa_numero: {c.getNumber()}')


main()
