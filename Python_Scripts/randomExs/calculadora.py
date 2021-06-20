def soma(x:float, y:float)->float:
    return x + y

def sub(x:float, y:float)->float:
    return x - y

def mult(x:float, y:float)->float:
    return x * y

def div(x:float, y:float)->float:
    if y != 0:
        return x / y
    return None

def pot(x:float, y:float)->float:
    return x ** y

def raiz(x:float)->float:
    return x ** 0.5

def log10 (x:float)->float:
    import math
    return math.log10(x)

def calcula(operador:str, x:float, y:float)->float:
    if operador == "SUM": return soma(x, y)
    if operador == "DIF": return sub(x, y)
    if operador == "MULT": return mult(x, y)
    if operador == "DIV": return div(x, y)
    if operador == "POT": return pot(x, y)
    if operador == "RAIZ": return raiz(x)
    if operador == "LOG10": return log10(x)


def main():
    entrada = input().split(' ')
    operador, x = entrada[0], float(entrada[1])
    y = "undefined"
    if len(entrada) == 3:
        y = float(entrada[2])
    resposta = calcula(operador, x, y)
    print(f"{resposta:.2f}")
    
main()