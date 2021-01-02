
import random as rd

def geraNumeros(qtdNumeros:int)->list:
    populacao = list()
    for i in range(qtdNumeros):
        populacao.append(rd.randint(40, 100))
    return populacao

def umaIteracao(populacao: list) -> list:
    amostraDaPopulacao = list()
    for i in range(20):
        amostraDaPopulacao.append(rd.choices(populacao))
    return amostraDaPopulacao
    
def mediaAmostra(amostra:list)->float:
    return sum(amostra) / len(amostra)

def experimento(repeticoes:int):
    populacao = geraNumeros(20)
    distribuicaoMedias = list()
    
    for i in range(repeticoes):
        iteracao = umaIteracao(populacao)
        media = mediaAmostra(iteracao)
        distribuicaoMedias.append(media)
        iteracao = list()
        media = 0
    
    mediaGeral = mediaAmostra(distribuicaoMedias)
    for i in distribuicaoMedias:
        print(i, end=" ")
    print("-----")
    print(mediaGeral)
    
    
