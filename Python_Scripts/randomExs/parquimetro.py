def converteHoraParaMinutos(hora:str)->float:#input: HH:MM
    horas, minutos = hora.split(':')
    horas, minutos = float(horas), float(minutos)
    minutos = horas*60 + minutos
    return minutos

def calculaPreco(minutos:float)->float:
    if minutos <=15:
        return 0
    elif minutos <=60:
        return 5
    elif minutos <=4 * 60:
        total = 5 #primeira hora
        minutos = minutos - 60 #primeira hora

        horas = int(minutos / 60)
        if ((minutos / 60) > horas):
            horas = horas + 1
        
        total = total + horas * 3 #3 reais por hora - de 2 a 4 horas
        return total
    #mais de 4 horas
    total = 5 #primeira hora
    total = total + 9 #3 reais por hora, 3 horas
    minutos = minutos - 4 * 60 #subtrair as primeiras 4 horas

    horas = int(minutos / 60)
    if ((minutos / 60) > horas):
        horas = horas + 1

    total = total + horas * 2 #2 reais por hora - 5horas ou mais
    return total


def main():
    entrada = input()
    saida = input()

    entrada = converteHoraParaMinutos(entrada)
    saida = converteHoraParaMinutos(saida)

    tempo = saida - entrada
    print(tempo)
    preco = calculaPreco(tempo)
    print(f"R$ {preco:.2f}")

main()