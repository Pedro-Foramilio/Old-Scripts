import pandas as pd
import numpy as np
import sys
import os

def valorMedio(valoresX:list) -> float:
    return sum(valoresX) / len(valoresX)

def incertezaMedia(valores:list) -> float:
    media = valorMedio(valores)
    N = len(valores)
    d_quadrado_sum = sum([(x - media)**2 for x in valores])
    parametro = 1 / (N * (N-1))
    return np.sqrt(parametro * d_quadrado_sum)


def p_valor_sobre_incerteza(list_v, list_inc_y):
    return sum([(list_v[i] / list_inc_y[i]**2) for i in range(len(list_v))])

def p_1_sobre_incerteza(list_inc_y):
    return sum([(1/x**2) for x in list_inc_y])

def p_x_y(list_x, list_y, list_inc_y):
    return sum([(list_x[i] * list_y[i] / list_inc_y[i]**2) for i in range(len(list_x))])

def p_valor_inc_quadrado(list_v, list_inc_y):
    return sum([(list_v[i]**2 / list_inc_y[i]**2) for i in range(len(list_v))])

def coef_angular(dataFrame):
    valoresX = dataFrame["X"]
    valoresY = dataFrame["Y"]
    valoresInc = dataFrame["Inc"]
    c1 = p_valor_sobre_incerteza(valoresY, valoresInc) * p_valor_sobre_incerteza(valoresX, valoresInc) 
    c2 = p_1_sobre_incerteza(valoresInc) *  p_x_y(valoresX, valoresY, valoresInc)
    c3 = p_valor_sobre_incerteza(valoresX, valoresInc) ** 2
    c4 = p_valor_inc_quadrado(valoresX, valoresInc) * p_1_sobre_incerteza(valoresInc)
    return c1 - c2 / (c3 - c4)

def coef_linear(dataFrame, coefAngular):
    valoresX = dataFrame["X"]
    valoresY = dataFrame["Y"]
    valoresInc = dataFrame["Inc"]
    c1 = p_valor_sobre_incerteza(valoresY, valoresInc)
    c2 = coefAngular * p_valor_sobre_incerteza(valoresX, valoresInc)
    c3 = p_1_sobre_incerteza(valoresInc)
    return c1 - c2 / c3

def incerteza_coef_angular_e_linear(dataFrame) -> (float, float):
    valoresX = dataFrame["X"]
    valoresY = dataFrame["Y"]
    valoresInc = dataFrame["Inc"]
    N = len(valoresX)

    x = p_valor_sobre_incerteza(valoresX, valoresInc) / p_1_sobre_incerteza(valoresInc)
    x2 = p_valor_inc_quadrado(valoresX, valoresInc) / p_1_sobre_incerteza(valoresInc)
    s2 = N / p_1_sobre_incerteza(valoresInc)

    inc_a = 1/ np.sqrt(N) * np.sqrt(s2 / (x2 - x**2))
    inc_b = 1/ np.sqrt(N) * np.sqrt(s2 * x2 / (x2 - x**2))
    return (inc_a, inc_b)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("missing filePath")
    else:
        file_path = sys.argv[1]
        if os.path.exists(file_path) and os.path.isfile(file_path):
            df = pd.read_excel(file_path)
            media = valorMedio(df["X"])
            inc_media = incertezaMedia(df["X"])
            print(f"media: {media} incerteza: {inc_media}")
            tupla = incerteza_coef_angular_e_linear(df)
            print(f"a: {coef_angular(df)} b: {coef_linear(df)} inc_a:{tupla[0]} inc_b:{tupla[1]}")
        else:
            print("file not exists")
