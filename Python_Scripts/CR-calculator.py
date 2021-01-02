from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
import time
import pandas
from bs4 import BeautifulSoup

class Calcula_Cr:
    

    def __init__(self, driver):
        self.driver = driver
        self.url = "https://aluno.ufabc.edu.br/"
        self.login_bar = "login"  #id
        self.pass_bar = "senha" #id
        self.user = "None"
        self.password = "None"
        self.ficha = '/html/body/div[2]/div/div[1]/ul/ul[4]/li[1]/a'  #xpath
        self.bacharel = "/html/body/div[2]/div/div[2]/div/table/tbody/tr[2]/td[1]/a"  #xpath
        self.table = "ficha_individual"  #class
        self.cr = "/html/body/div[2]/div/div[2]/div/table[2]/tbody/tr[2]/td[2]"  #xpath

    def getLogin(self):
        self.user = input("Insert username to login: ")
        self.password = input("Insert login password: ")
    
    def navigate(self):
        self.driver.get(self.url)
    
    def login(self):
        self.driver.find_element_by_id(self.login_bar).send_keys(self.user)
        self.driver.find_element_by_id(self.pass_bar).send_keys(self.password)
        print("Click captcha option, then press enter")
        input("Press enter on the script after you logged in")
    
    def try_loggin_again(self):
        print("Loggin failed")
        question = input("Are loggin details filled in the boxes?(Y/N) ")
        if question.lower().strip() == "y":
            print("Click captcha option, then press enter")
            input("Press enter on the script after you logged in")
        else:
            self.login()

    def find_data(self):
        self.driver.find_element_by_xpath(self.ficha).click()
        self.driver.find_element_by_xpath(self.bacharel).click()
    
    def get_data(self):
        tbl = self.driver.find_element_by_class_name(self.table).get_attribute('outerHTML')
        soup = BeautifulSoup(tbl, features="lxml")
        data = [i.text for i in soup]
        data  = data[0].replace("\n", " ")
        info = []
        for i in range(len(data)):
            if data[i:i+8] == "Aprovado" or data[i:i+11] == "Obrigatória":
                info.append(data[i-4:i])
        info = [i.strip() for i in info]
        for item in info:
            if item == "ado":
                info.remove(item)
        info = [i.replace(" ", "") for i in info]
        return info
    
    def get_cr(self):
        cr = self.driver.find_element_by_xpath(self.cr)
        cr = cr.text
        cr = cr.strip()
        cr = cr.replace('"', '')
        cr = cr.replace(",", ".")
        return float(cr)

def calcula_nota(conceito: str, credito: int):
    if conceito.upper() == "A":
        return 4*credito
    if conceito.upper() == "B":
        return 3*credito
    if conceito.upper() == "C":
        return 2*credito    
    if conceito.upper() == "D":
        return 1*credito
    if conceito.upper() in ("F", "O"):
        return 0

# getting data from old Disciplines
gg = webdriver.Chrome(ChromeDriverManager().install())
g = Calcula_Cr(gg)
g.navigate()
g.getLogin()
g.login()
if g.url == gg.current_url:
    g.try_loggin_again()
g.url = gg.current_url
g.find_data()
data = g.get_data()
cr = g.get_cr()
gg.close()

#Calculating
creditos_completos = [i[0] for i in data]
creditos_completos = list(map(int, creditos_completos))
creditos_completos = sum(creditos_completos)
n = int(input("Quantas matérias serão finalizadas nesse QS? ")) #numero de materias a computar
materias = []

for i in range(n):
    aux1 = input(f"conceito na matéria {i+1}: ").upper().strip()
    aux2 = int(input(f"creditos da matéria {i+1}: "))
    materias.append([aux1, aux2])
print(materias)

p = input('Há erros na lista (S/N)? ')
if p.upper() == 'S':
    errado = True
    while errado:
        k = int(input('Qual a posição da materia errada?(pos_incial = 1) '))
        m = int(input("Qual a posição do dado na materia errada(1 ou 2"))
        materias[k - 1][m - 1] = float(input('Digite o valor correto(numero de creditos ou conceito): '))
        print("lista atualizada: ", materias)
        ajuste = input('Todos os dados estão corretos (S/N)? ')
        if ajuste.upper() == 'S':
            errado = False

creditos_atuais = 0
nota_parcial = 0
for disc in materias:
    creditos_atuais += disc[1]
    nota_parcial += calcula_nota(disc[0].upper(), disc[1])
cr_novo = (cr*creditos_completos + nota_parcial)/(creditos_completos + creditos_atuais)
print(f"CR novo: {cr_novo:.3f}")
