def retornaDiaSeguinte(dia:str)->str: #entrada DD:MM:AAAA
    dia, mes, ano = dia.split('/')
    correcaoMES = 0
    dia = int(dia)
    
    if int(mes) == 2:
        correcaoMES = -2
    
    if int(mes) in [1, 3, 5, 7, 8, 10, 12]: #meses com 31 dias
        correcaoMES = 1

    if dia + 1 > (30 + correcaoMES): #agoraEHfinalMes
        dia = "01"
        if int(mes) == 12:
            ano = str(int(ano) + 1)
            return "01/01/" + ano

        mes = str(int(mes) + 1)
        
        if len(mes) == 1:
            mes = "0" + mes

        return "01/" + mes + "/" + ano
    
    else:
        dia = str(dia + 1)
        if len(dia) == 1:
            dia = "0" + dia
        return dia + "/" + mes + "/" + ano

def main():
    entrada = input()
    diaSeguinte = retornaDiaSeguinte(entrada)
    print(diaSeguinte)

main()
