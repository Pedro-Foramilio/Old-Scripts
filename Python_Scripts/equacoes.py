"""Cálculo de raíes de um polinômio de grau 2"""
print('Insira valores do polinômio correspondente à ax²+bx+c')
a = float(input('a='))
b = float(input('b='))
c = float(input('c='))
D = b**2 - 4*a*c
if D > 0:
    print('2 soluções:')
    x = (-b + D**0.5)/(2*a)
    y = (-b - D**0.5)/(2*a)
    print(x)
    print(y)
elif D == 0:
    print('1 solução:')
    xu = (-b)/(2*a)
    print(xu)
else:
    print('Não há soluções reais')
    x = ((D*-1)**0.5)/2*a
    y = (-(D*-1)**0.5)/2*a
    print('soluções complexas:')
    c = -b/2*a
    X = str(x)
    Y = str(y)
    C = str(c)
    print(C +  '+ ' + X, 'i')
    print(C +  '+ ' + Y, 'i')
input()
    