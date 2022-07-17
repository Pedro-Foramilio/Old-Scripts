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

def _reset():
    Prisioneiro.numerosDisponiveis = [x for x in range(1, 101)]
    Caixa.numeros = [x for x in range(1, 101)]
    Caixa.contagem = 1

def gerarPrisioneiros():
    return [Prisioneiro() for x in list(range(100))]

def gerarCaixas():
    return [Caixa() for x in list(range(100))]

def buscaCaixa(id: int, listaCaixa:list)->Caixa:
    for c in listaCaixa:
        if c.id == id:
            return c
    return None

def procurarNumeroDoPrisioneiro(p:Prisioneiro, listaCaixas:list):
    cx = buscaCaixa(p.numero, listaCaixas)

    for i in range(50):
        if p.numero == cx.numero:
            p.achou_numero = True
            break
        else:
            cx = buscaCaixa(cx.numero, listaCaixas)

def realizarTeste():
    prisioneiros = gerarPrisioneiros()
    caixas = gerarCaixas()

    for p in prisioneiros:
        procurarNumeroDoPrisioneiro(p, caixas)

    achou, nao_achou = 0, 0
    for p in prisioneiros:
        if p.achou_numero:
            achou += 1
        else:
            nao_achou += 1
    
    _reset()
    return achou

def main():
    numero_sucessos = 0
    numero_falhas = 0

    for i in range(1, 1001):
        print(f'Iniciando teste {i}')
        numero_achados = realizarTeste()
        print(f'teste {i} {"Sucesso" if numero_achados == 100 else "Fracasso" } - numero achados: {numero_achados}\n')
        if numero_achados == 100:
            numero_sucessos += 1
        else:
            numero_falhas += 1

    print("--- Resultados ---")
    print(f'Sucessos: {numero_sucessos} - Fracassos {numero_falhas}')
    

if __name__ == '__main__':
    main()
