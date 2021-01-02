
import time
import decimal

def pega_matrix(n:int):
    M = []
    for i in range(n):
        aux = list(map(int, input().split(' ')))
        M.append(aux)
    return M

def cria_bordas(matriz, k):
    n0, m0 = len(matriz), len(matriz[0])
    n, m = (n0+2*k), (m0+2*k)
    matrizona = []
    for i in range(n):
        linha = []
        for j in range(m):
            if (i > k-1) and (j > k-1) and (i <= n0 + k-1) and (j <= m0 + k-1):
                linha.append(matriz[i-k][j-k])
            else:
                linha.append('X')
        matrizona.append(linha)
    return matrizona

def troca_valores(MA):
    n, m = len(MA), len(MA[0])
    M = [linha[:] for linha in MA]  # cópia
    for i in range(n):
        for j in range(m):
            if MA[i][j] != 'X':
                if MA[i][j-1] == 'X':  # lado esequerdo
                    if MA[i-1][j] == 'X':  # canto superior
                        for l in range(i+1):
                            for k in range(j+1):
                                M[l][k] = MA[i][j]
                    if MA[i+1][j] == 'X':  # canto inferior
                        for l in range(i, n):
                            for k in range(j+1):
                                M[l][k] = MA[i][j] 
                if MA[i][j+1] == 'X':  # lado direito
                    if MA[i-1][j] == 'X':  # canto superior
                        for l in range(i+1):
                            for k in range(j, m):
                                M[l][k] = MA[i][j]
                    if MA[i+1][j] == 'X':  # canto inferior
                        for l in range(i, n):
                            for k in range(j, m):
                                M[l][k] = MA[i][j]
                
                if (MA[i][j-1] != 'X')and(MA[i][j+1] != 'X'):  # no meio - verticalidade
                    if (MA[i-1][j] == 'X') and (MA[i+1][j] != 'X'):  # EM CIMA 
                        for l in range(i):
                            M[l][j] = MA[i][j]
                    if (MA[i+1][j] == 'X') and (MA[i-1][j] != 'X'):  # EM BAIXO
                        for l in range(i, n):
                            M[l][j] = MA[i][j]
                    if (MA[i+1][j] == 'X') and (MA[i-1][j] == 'X'):  # fix one line bug
                        for l in range(n):
                            M[l][j] = M[i][j]
                if (MA[i-1][j] != 'X') and (MA[i+1][j] != 'X'):  # no meio - horizontalidade
                    if (MA[i][j-1] == 'X') and (MA[i][j+1] != 'X'):  # esquerda
                        for k in range(j):
                            M[i][k] = M[i][j]
                    if (MA[i][j+1] == 'X') and (MA[i][j-1] != 'X'):  # direita
                        for k in range(j, m):
                            M[i][k] = M[i][j]
                    if (MA[i][j+1] == 'X') and (MA[i][j-1] == 'X'):  # fiz one column bug
                        for k in range(m):
                            M[i][k] = M[i][j]
            
    return M

def main():
    entrada = input().split(' ')
    k, n = int(entrada[0]), int(entrada[1])
    m = pega_matrix(n)
    t0 = time.time()
    if k == 0:
        for linha in m: print(linha)
    else:
        matrizona = cria_bordas(m, k)
        response = troca_valores(matrizona)
        for linha in response: print(linha)

    t1 = time.time()
    print(f'runtime: {decimal.Decimal(t1-t0)}s')


main()
