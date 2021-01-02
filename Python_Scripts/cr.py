def calcula_nota(conceito):
    if conceito.upper() == 'A':
        return 4*credito
    elif conceito.upper() == 'B':
        return 3*credito
    elif conceito.upper() == 'C':
        return 2*credito
    elif conceito.upper() == 'D':
        return 0
pergunta = input('Já possúi CR? (S/N)')
if pergunta.upper() == 'N':
    credito_total = 0
    nota_parcial = 0
    n = int(input('Quantas matérias completará?'))
    for i in range(n):
        print(f'{i + 1}ª matéria:')
        conceito = input('Conceito: ')
        credito = int(input('Créditos: '))
        print('')
        credito_total = credito_total + credito
        nota = calcula_nota(conceito)
        nota_parcial = nota_parcial + nota
    CR = print(f'Seu CR será {nota_parcial/credito_total}')
if pergunta.upper() == 'S':
    cr_anterior = float(input('Digite seu Cr anterior: '))
    creditos_completos = int(input('Quantos créditos já completou? '))
    n = int(input('Quantas matérias comletará neste quad? '))
    creditos_atuais = 0
    nota_parcial = 0
    for i in range(n):
        print(f'{i + 1}ª matéria:')
        conceito = input('Conceito: ')
        credito = int(input('Créditos: '))
        print('')
        creditos_atuais = creditos_atuais + credito
        nota = calcula_nota(conceito)
        nota_parcial = nota_parcial + nota
    CR = (cr_anterior*creditos_completos + nota_parcial)/(creditos_completos + creditos_atuais)
    print(f'Seu Cr será {round(CR, 3)}')