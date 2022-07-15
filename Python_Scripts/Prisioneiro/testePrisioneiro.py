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
    numeros = [x for x in range(1, 101)]
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

def buscaCaixa(id: int, listaCaixa:list)->Caixa:
    for c in listaCaixa:
        if c.id == id:
            return c
    return None

def procurarNumeroDoPrisioneiro(p:Prisioneiro, listaCaixas:list):
    cx = buscaCaixa(p.numero, listaCaixas)
    print(f'Prisioneiro: {p.getNumber()}')

    for i in range(50):
        print(f'cx.id = {cx.id}, cx.numero = {cx.numero}')
        if p.numero == cx.numero:
            p.achou_numero = True
            break
        else:
            cx = buscaCaixa(cx.numero, listaCaixas)
    print(f'--- --- ---')

def main():
    prisioneiros = gerarPrisioneiros()
    caixas = gerarCaixas()

    print("--- Prisioneiros ---")
    for p in prisioneiros:
        print(f'Prisioneiro: {p.getNumber()}')

    print("--- Caixas ---")
    for c in caixas:
        print(f'Caixa_id: {c.getId()}, Caixa_numero: {c.getNumber()}')
    
    print("--- iniciando teste ---")
    for p in prisioneiros:
        procurarNumeroDoPrisioneiro(p, caixas)



main()


#fix 50 caixas -> 100
#exception when busca returns None. Shouldnt return none 