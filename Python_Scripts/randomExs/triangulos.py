def ehTriangulo(a:float, b:float, c:float)->bool:
    return (a < b + c) and (b < c + a) and (c < a + b)

def classificaTriangulo(a:float, b:float, c:float)->str:
    if (a != b != c):
        return "Triangulo escaleno"
    elif (a == b == c):
        return "Triangulo equilatero"
    return "Triangulo isoceles"

def main():
    #entrada = input().split(' ')
    #entrada = [int(x) for x in entrada]
    a, b, c = input().split(' ')
    a = float(a)
    b = float(b)
    c = float(c)
    if ((a > 0) and (b > 0) and (c > 0) and ehTriangulo(a, b, c)):
        print(classificaTriangulo(a, b, c))
    else:
        print("Medidas nao formam um triangulo")

main()