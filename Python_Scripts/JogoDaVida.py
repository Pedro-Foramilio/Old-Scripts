''' Jogo da Vida 1-D '''
''' 
REGRAS: BBABB
A nasce se 2 ou 3 Bs vivos
A Vive se 2 ou 4 Bs vivos
'''

def regras(tabuleiro:list, index:int, modo:int)->bool:
    '''Recebe o tabuleiro e o index da casa a ser analisada. Determina se viverá
        (true), ou morrerá(false)
    modo = 0 analisa se vive, modo = 1 analisa se nasce
    '''
    condicao = [(2, 4), (2, 3) ]
    if (index < 2) or (index > len(tabuleiro) -3 ):
        
        if index < 2:
            if index == 0: #primeira casa
                casa2, casa3 = tabuleiro[index+1], tabuleiro[index+2]
                if casa2 == 'X' and casa3 == 'X':
                    return True
                else:
                    return False
            if index == 1: #segunda casa
                (casa1, casa3, casa4) = (
                    tabuleiro[index-1], tabuleiro[index+1],tabuleiro[index+2]
                    )
                casas = [casa1, casa3, casa4]
                vivos = 0
                for elemento in casas:
                    if elemento == 'X':
                        vivos+=1
                if vivos in condicao[modo]:
                    return True
                else:
                    return False
    
        if index > len(tabuleiro)-3:
            if index == len(tabuleiro)-1: #ultima casa
                casa1, casa2 = tabuleiro[index-2], tabuleiro[index-1]
                if casa1 == 'X' and casa2 == 'X':
                    return True
                else:
                    return False
            if index == len(tabuleiro)-2: #penultima casa
                (casa1, casa2, casa4) = (
                    tabuleiro[index-2], tabuleiro[index-1], tabuleiro[index+1]
                    )
                casas = [casa1, casa2, casa4]
                vivos = 0
                for elemento in casas:
                    if elemento == 'X':
                        vivos +=1
                if vivos in condicao[modo]:
                    return True
                else:
                    return False
    else: #elementos do meio do tabuleiro
        (casa1, casa2, casa4, casa5) = (
            tabuleiro[index-2], tabuleiro[index-1], 
            tabuleiro[index+1], tabuleiro[index+2]
            )
        casas = [casa1, casa2, casa4, casa5]
        vivos = 0
        for elemento in casas:
            if elemento == 'X':
                vivos +=1
        if vivos in condicao[modo]:
            return True
        else:
            return False

def update_board(board:list)->list:
    new_board = []
    for i in range(len(board)):
        if board[i] == '.':
            nasce = regras(board, i, 1)
            if nasce:
                new_board.append('X')
            else:
                new_board.append('.')
        if board[i] == 'X':
            vive = regras(board, i, 0)
            if vive:
                new_board.append('X')
            else:
                new_board.append('.')
    return ''.join(new_board )


k = input('Quantas gerações? ')
loop = int(k)
board = list(input('Geração inical: '))
new_board = []

print(''.join(board))
for uehuehuh in range(loop):
    new_board = update_board(board)
    print(new_board)
    board = new_board
