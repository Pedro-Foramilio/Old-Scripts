
##############################################################################
# def remover(car, string):
#     response = string.replace(car.lower(), '')
#     response = response.replace(car.upper(), '')
#     return response
# print(remover(input(), input()))
##############################################################################
# def remover(frase):
#     filtro = 'aeiou'
#     aux = frase
#     for char in frase:
#         if char.lower() in filtro:
#             aux = aux.replace(char, '')
#     return aux
# print(remover(input()))
##############################################################################
# s = 'oi'
# n = 3
# msg = s
# for i in range(n-1):
#     msg += ' , ' + s
# if n == 0:
#     print(msg*0)
# else:
#     print(msg)


#   print(((input() + ' , ') * int(input()))[:-3])
##############################################################################
# def coletor(string: str)-> str:
#     box = ''
#     for leter in string:
#         if leter not in box:
#             box += leter
#     return box

# def convertor(string: str)-> tuple:
#     response = []
#     for char in string:
#         response.append(ord(char))
#     return tuple(response)

# alfabeto = list(range(ord('a'), ord('z')+1))
# frase = input().strip().lower().replace(' ', '').replace('.', '')

# box = coletor(frase)
# box = convertor(box)
# box = sorted(box)
# if box == alfabeto:
#     print('SIM')
# else:
#     print('NAO')
##############################################################################
# palavra = input()
# check = palavra[::-1]
# if check == palavra:
#     print('PALINDROMO')
# else:
#     print('NAO EH PALINDROMO')
##############################################################################
# s1 = 'a arara bicou a jararaca'
# s2 = 'ara'
# s2_len = len(s2)
# 
# count = 0
# for i in range(len(s1)):
#     if s2 in s1:
#         count += 1
#         aux1 = s1.index(s2)
#         s1 = s1[:(aux1)] + s1[aux1+1:]
# print(count)
##############################################################################
# vogais = 'aeiou'
# conc = 'bcdfghjklmnpqrstvwxyz' 
# pont = '.,!?'
# space = ' '
# frase = 'Um exercicio facil!'.lower()
# def counter(frase, banco):
#     aux = 0
#     for letter in frase:
#         if letter in banco:
#             aux += 1
#     return aux
# n_vogais = counter(frase, vogais)
# n_conc = counter(frase, conc)
# n_pont = counter(frase, pont)
# n_space = counter(frase, space)
# total = len(frase)
# p_vogais = (n_vogais/total)*100
# p_conc = (n_conc/total)*100
# p_pont = (n_pont/total)*100
# p_space = (n_space/total)*100

# print(f'Vogais: {p_vogais:.2f}%')
# print(f'Consoantes: {p_conc:.2f}%')
# print(f'Espacos: {p_space:.2f}%')
# print(f'Pontuacoes: {p_pont:.2f}%')
##############################################################################
# s = 'RA000000000000012345'
# validation = True
# if len(s) != 20:
#     validation = False
# ra = s[:2]
# if ra != 'RA':
#     validation = False
# if validation:
#     numbers = '123456789'
#     aux = 0
#     for count, char in enumerate(s, 0):
#         if char in numbers:
#             aux = count
#             break
#     password = s[aux:]
#     print(password)
# else:
#     print('RA INVALIDO')
##############################################################################
# s = '((9 + (5 + 8) + 10) + (3 + 10)) + 5'
# check = True
# filter_ = '()'
# aux1 = 0
# aux2 = 0
# for char in s:
#     if char not in filter_:
#         s = s.replace(char, '')
# s = s.replace(' ', '')
##############################################################################
# s = '3 * (8 + (5 * 9 ^ 8) + 3'
# conta_abrir = 0
# conta_fechar = 0
# check = True
# for char in s:
#     if char == '(':
#        conta_abrir += 1
#     if char == ')':
#        conta_fechar += 1
#     if conta_fechar > conta_abrir:
#        check = False
#        break

# if conta_abrir != conta_fechar or not check:
#     print('Erro na parentizacao')
# else:
#    print('Parentizacao correta')
##############################################################################
# n = int(input())
# pont = '.,!?;:'
# texto = []
# for i in range(n):
#     texto.append(input())
 
# maior = 0
# atual = 0
# for frase in texto:
#     atual = 0
#     for letra in frase:
#         if atual > maior:
#             maior = atual
#             break
#         atual +=1
#         if letra == ' ' or letra in pont:
#             atual = 0    

##############################################################################
# def encoder(string: str)->str:
#     char_anterior = ''
#     char_next = ''
#     counter = 0
#     indexador = []
#     for i in range(len(string)-1):
#         char_anterior = string[i]
#         char_next = string[i+1]
#         if char_next == char_anterior:
#             counter+=1
#         if char_next != char_anterior:
#             indexador.append((char_anterior, counter+1))
#             counter = 0
#         if i == len(string)-2:
#             if char_anterior == char_next:
#                 indexador.append((char_anterior, counter+1))
#             else:
#                 indexador.append((char_next, 1))
#             counter = 0
#     encoded = ''
#     for tupla in indexador:
#         if tupla[1] > 2:
#             encoded += str(tupla[0]) + str(tupla[1])
#         else:
#             encoded += tupla[0]*tupla[1]
            
#     return encoded

   
# def decoder(string: str)->str:
#     lista = [x for x in string]
#     decoded = ''
#     for i in range(len(lista)):
#         if i == (len(lista)-1):
#             if lista[i].isnumeric():
#                 if lista[i-1].isnumeric():
#                     break
#                 else:
#                     numero = int(lista[i])
#                     decoded += lista[i-1]*numero
#             else:
#                 if lista[i-1].isalpha():
#                     decoded += lista[i-1] + lista[i]
#                 else:
#                     decoded += lista[i]
#         if i == (len(lista)-2):
#             continue
#         if i < (len(lista)-2):
#             if lista[i].isalpha() or lista[i] == ' ':
#                 if lista[i+1].isnumeric() and lista[i+2].isnumeric():
#                     decoded += lista[i]*(int(lista[i+1]+lista[i+2]))
#                 if lista[i+1].isnumeric() and lista[i+2].isalpha():
#                     decoded += lista[i]*(int(lista[i+1]))
#                 if lista[i+1].isalpha():
#                     decoded += lista[i]
                
#     return decoded




# n = 2
# s = 'a5bbc13mmdcc'
# if n == 1:
#     print(encoder(s))
# if n == 2:
#     print(decoder(s))
# if n not in (1, 2):
#     print('Codigo desconhecido')
##############################################################################
