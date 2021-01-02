'''Powder Diffraction Ploting'''
### This will work using Jupyter Notebook

import matplotlib.pyplot as pp
%matplotlib notebook
import numpy as np

def read_my_data(file):
	with open(file) as f:
		data = list(f.read().split('\n'))[:-1]
		data = [float(i) for i in data]
		return data

#amostra L_01
dados1_x = read_my_data('L_01X.txt')
normalizacao_1 = 1/max(read_my_data('L_01Y.txt'))
dados1_y = normalizacao_1 * np.array(read_my_data('L_01Y.txt'))
pp.plot(dados1_x, dados1_y, 'k', label='L_01')

#amostra L_02
dados2_x = read_my_data('L_02X.txt')
normalizacao_2 = 1/max(read_my_data('L_02Y.txt'))
dados2_y = normalizacao_2 * np.array(read_my_data('L_02Y.txt'))
#pp.plot(dados2_x, dados2_y, 'k', label='L_02')

#Indato de Bário desejado: Ba2 In2 O5
dados3_x = read_my_data('InBaO2.5-X.txt')
normalizacao_3 = 1/max(read_my_data('InBaO2.5-Y.txt'))
dados3_y = normalizacao_3 * np.array(read_my_data('InBaO2.5-Y.txt'))
pp.plot(dados3_x, dados3_y, 'm', label='Indato de Bário')

#BaO
dados4_x = read_my_data('BaOX.txt')
normalizacao_4 = 1/max(read_my_data('BaOY.txt'))
dados4_y = normalizacao_4 * np.array(read_my_data('BaOY.txt'))
#pp.plot(dados4_x, dados4_y, 'b', label='BaO')

#Ba3 In2 O6
dados5_x = read_my_data('Ba3In2O6-X.txt')
normalizacao_5 = 1/max(read_my_data('Ba3In2O6-Y.txt'))
dados5_y = normalizacao_5 * np.array(read_my_data('Ba3In2O6-Y.txt'))
pp.plot(dados5_x, dados5_y, 'r', label='Ba3In2O6')

#Ba4 In6 O13   obs: há outro padrão de difrção que não está presente
dados6_x = read_my_data('Ba4In6O13-X.txt')
normalizacao_6 = 1/max(read_my_data('Ba4In6O13-Y.txt'))
dados6_y = normalizacao_6 * np.array(read_my_data('Ba4In6O13-Y.txt'))
#pp.plot(dados6_x, dados6_y, 'g', label='Ba4In6O13')

#Ba In2 O4
dados7_x = read_my_data('BaIn2O4-X.txt')
normalizacao_7 = 1/max(read_my_data('BaIn2O4-Y.txt'))
dados7_y = normalizacao_7 * np.array(read_my_data('BaIn2O4-Y.txt'))
#pp.plot(dados7_x, dados7_y, 'r', label='BaIn2O4')

#In2 O3
dados8_x = read_my_data('In2O3-X.txt')
normalizacao_8 = 1/max(read_my_data('In2O3-Y.txt'))
dados8_y = normalizacao_8 * np.array(read_my_data('In2O3-Y.txt'))
#pp.plot(dados8_x, dados8_y, 'y', label='In2O3')

#Ba C O3
dados9_x = read_my_data('BaCO3-X.txt')
normalizacao_9 = 1/max(read_my_data('BaCO3-Y.txt'))
dados9_y = normalizacao_9 * np.array(read_my_data('BaCO3-Y.txt'))
#pp.plot(dados9_x, dados9_y, 'b', label='BaCO3')


pp.grid(True)
pp.legend()
pp.ylabel('Intensidade Normalizada')
pp.xlabel('2θ')
pp.title('Powder Diffraction')
