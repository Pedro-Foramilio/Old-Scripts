entrada =  [[0,0,0,0],
            [0,0,0,1],
            [0,0,1,0],
            [0,0,1,1],
            [0,1,0,0],
            [0,1,0,1],
            [0,1,1,0],
            [0,1,1,1],
            [1,0,0,0],
            [1,0,0,1],
            [1,0,1,0],
            [1,0,1,1],
            [1,1,0,0],
            [1,1,0,1],
            [1,1,1,0],
            [1,1,1,1]]

def strHex_to_listBin(str):
    if len(str) != 1:
        raise ValueError("Input must be a single character")

    my_hexdata = str

    scale = 16 ## equals to hexadecimal

    num_of_bits = 4

    return [int(x) for x in bin(int(my_hexdata, scale))[2:].zfill(num_of_bits)]



def XOR (x1, x2):
    if x1 == 0 and x2 == 0 or x1 == 1 and x2 == 1:
        return 0 
    return 1

"""
Funcao XOR3 e XOR4 apllica XOR para 3 e 4 bits, respectivamente
"""
def XOR3 (x1, x2, x3):
    soma = x1 + x2 + x3
    if soma % 2 == 0:
        return 0
    return 1

def XOR4 (x1, x2, x3, x4):
    soma = x1 + x2 + x3 + x4
    if soma % 2 == 0:
        return 0
    return 1

"""
Funcao fazXOR recebe um vetor de Colunas Col_n e uma matriz de bits (que pode
ser uma sbox) e aplica o XOR para as colunas do vetor

Tome como exemplo a sbox 3, se for desejado o XOR das colunas X1 e X3, a funcao
vai recebe-las em um vetor (Col_n[1,3]) e vai aplicar o XOR na sbox

O resultado eh entao armazenado em um novo vetor (resultado) que possui somente
os resultados dos XOR para 2 ou mais colunas

Caso seja passado uma unica coluna, não ha XOR e eh retornado e própria coluna
"""
def fazXOR(Col_n, m):
    resultado = []
    
    if len(Col_n) == 1:
        for i in range(0,16):
            resultado.append(m[i][Col_n[0]])
        
    elif len(Col_n) == 2:
        for i in range(0,16): 
            resultado.append(XOR(m[i][Col_n[0]],m[i][Col_n[1]]))
        
    elif len (Col_n) == 3:
        for i in range(0,16): 
            resultado.append(XOR3(m[i][Col_n[0]],m[i][Col_n[1]],m[i][Col_n[2]]))
        
    else:
        for i in range(0,16): 
            resultado.append(XOR4(m[i][Col_n[0]],m[i][Col_n[1]],m[i][Col_n[2]],m[i][Col_n[3]]))
        
    return resultado

"""
Funcao invertNum recebe um numero de 0 a 3 e retorna o inverso dele. 

Ela serve para recebermos um numero de uma posicao de um binario, como por exem
plo x134, que se refere, respectivamente a 4, 3, 1 em posicao de vetor
"""
def inverteNum (n):
    if n == 0:
        n = 3
    elif n == 1:
        n = 2
    elif n == 2:
        n = 1
    else: 
        n = 0
    return n

"""
Funcao pegaCol vai receber uma string, tipo 1234, vai separar esse numeros e 
guarda-los num vetor

Essa string corresponde as colunas da sbox que voce quer fazer a criptoanalise
por exemplo, se voce quiser analisar a 134, a funcao recebe essa string, separa
os numeros, inverte eles (pois estamos falando de binarios, as colunas sao da 
direita para a esquerda), e armazena num vetor
"""
def pegaCol (string):
    aux = []
    for i in string:
        n = int(i) - 1
        n = inverteNum(n)        
        aux.append(n)
    return aux

"""
Funcao Cripto vai receber como parametro duas strings, x e y, que correspondem
a combinacoes das sboxs de entrada e sbox3

A funcao recebe essa string e armazena em uma variavel a coluna, em formato de 
vetor, exemplo:
    x1234 = '1234'
    x_linha = vetor [3, 2, 1, 0]
    
Em seguida vai aplicar o XOR para as combinacoes, tanto em x quanto em y, e 
armazena-las em outro vetor. 
    No caso anterior, pegariamos o resultado de x1 XOR x2 XOR x3 XOR x4 para 
    cada linha da sbox de entrada e armazenaria num vetor res_x
    
Por fim, pega os dois vetores de resultado dos XOR, tanto da matriz de entrada
quanto da SBOX3 e compara linha a linha, via XOR novamente. Para cada resultado
zero, incrementa 1 no contador

No final, mostramos na tela o valor do contador - 8, que é o numero correspon-
dente na tabela de combinacao linear da cripto analise    

"""
def cripto (sbox, x, y):
    x_linha = pegaCol(x)
    y_linha = pegaCol(y)
    
    #print("X1 entrada")
    res_x = fazXOR(x_linha, entrada)
    
    #print("Y2 sbox3")
    res_y = fazXOR(y_linha, sbox)
    
    counter = 0
    
    for i in range(0,16):
        aux = XOR (res_x[i], res_y[i])
        if aux == 0:
            counter += 1
    
    #print(f"x{x} operado y{y} = {counter - 8}")
    #print()
    return counter -8


def main():
    sbox1_Hex = ["3", "B", "7", "1", "0", "C", "E", "A", "F", "6", "2", "5", "8", "9", "D", "4"]
    sbox1 = [strHex_to_listBin(x) for x in sbox1_Hex]

    sbox2_Hex = ["B", "3", "7", "1", "D", "C", "A", "E", "F", "6", "9", "5", "8", "2", "0", "4"]
    sbox2 = [strHex_to_listBin(x) for x in sbox2_Hex]

    sbox3_Hex = ['3', 'B', 'E', '1', '0', 'A', '7', 'C', 'F', '8', '2', '5', '6', '9', 'D', '4']
    sbox3 = [strHex_to_listBin(x) for x in sbox3_Hex]

    sbox4_Hex = ['3', 'B', '7', '0', '1', 'E', 'C', 'A', 'F', '6', '4', '5', '8', '9', 'D', '2']
    sbox4 = [strHex_to_listBin(x) for x in sbox4_Hex]

    sbox5_Hex = ['3', '7', 'B', '5', '0', 'C', 'E', 'A', '2', 'F', '2', '1', '8', '9', 'D', '4']
    sbox5 = [strHex_to_listBin(x) for x in sbox5_Hex]

    sbox6_Hex = ['3', 'B', '7', '1', '0', 'C', 'E', 'A', '4', '2', '6', '8', '5', '9', 'D', 'F']
    sbox6 = [strHex_to_listBin(x) for x in sbox6_Hex]

    sbox7_Hex = ['4', '8', '7', '1', '0', 'C', 'E', 'F', 'A', '6', '2', '5', 'B', '9', 'D', '3']
    sbox7 = [strHex_to_listBin(x) for x in sbox7_Hex]

    sbox8_Hex = ['3', 'B', '7', '1', 'A', 'C', 'E', '0', 'F', '6', '4', '5', '8', 'D', '9', '2']
    sbox8 = [strHex_to_listBin(x) for x in sbox8_Hex]

    sbox9_Hex = ['3', '0', 'F', '2', 'B', 'C', 'E', 'A', '7', '6', '1', '5', '8', '9', 'D', '4']
    sbox9 = [strHex_to_listBin(x) for x in sbox9_Hex]

    sbox10_Hex = ['3', 'B', '7', '1', 'D', 'A', 'E', 'C', '9', '6', '2', '5', '8', 'F', '0', '4']
    sbox10 = [strHex_to_listBin(x) for x in sbox10_Hex]

    sbox11_Hex = ['D', 'B', '5', '1', '6', 'C', 'E', 'A', 'F', '0', '2', '7', '8', '9', '3', '4']
    sbox11 = [strHex_to_listBin(x) for x in sbox11_Hex]

    sbox12_Hex = ['3', 'B', '7', '1', '0', 'D', '4', 'A', '9', '6', '2', '5', '8', 'F', 'C', 'E']
    sbox12 = [strHex_to_listBin(x) for x in sbox12_Hex]

    sbox13_Hex = ['3', 'B', '0', '1', '7', 'F', 'A', 'E', 'C', '6', '2', '5', '8', '9', 'D', '4']
    sbox13 = [strHex_to_listBin(x) for x in sbox13_Hex]

    sbox14_Hex = ['3', 'B', '7', '8', 'C', '0', '9', 'A', 'F', '6', '2', '5', '1', 'E', 'D', '4']
    sbox14 = [strHex_to_listBin(x) for x in sbox14_Hex]

    sbox15_Hex = ['3', 'B', '7', 'A', '0', 'C', 'E', '0', 'F', '5', '2', '6', '8', '4', 'D', '9']
    sbox15 = [strHex_to_listBin(x) for x in sbox15_Hex]

    sbox16_Hex = ['3', 'B', '7', '4', '0', 'C', 'E', 'A', 'F', '9', '5', '2', '8', '6', 'D', '1']
    sbox16 = [strHex_to_listBin(x) for x in sbox16_Hex]

    sboxes = [sbox1, sbox2, sbox3, sbox4, sbox5, sbox6, sbox7, sbox8, sbox9, sbox10, sbox11, sbox12, sbox13, sbox14, sbox15, sbox16]
    xs = ["1", "2", "12", "3", 
          "13", "23", "123", "4",
          "14", "24", "124", "34",
          "134", "234", "1234"]

    ys = ["1", "2", "12",
          "3", "13", "23",
          "123", "4", "14",
          "24", "124", "34",
          "134", "234", "1234"]


    #for i in range(len(ys)):
    #    y = ys[i]
    #    print("y = " + y )
    #    values = [cripto(x, y) for x in xs]
    #    for j in range(len(values)):
    #        print(str(values[j]) + "\t")
    #    print("---------------")

    box_counter = 1
    for box in sboxes:
        a = [[] for x in range(15)]
        matrix = [a for x in range(15)]

        for i in range(len(ys)):
            y = ys[i]
            #print("y = " + y )
            values = [cripto(box, x, y) for x in xs]
            matrix[i] = [k for k in values]

        rez = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

        print(f"SBOX {box_counter}:")
        for line in rez:
            print(*line)
        print("---")
        box_counter += 1

if __name__ == "__main__":
    main()
