
from selenium import webdriver
import time
from bs4 import BeautifulSoup
import requests
import pandas
import time
import os


class MercadoLivre:
    def __init__(self, driver):
        self.driver = driver
        self.url = 'https://lista.mercadolivre.com.br/iphone#D[A:iphone]'
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36'}
        self.names = 'main-title'  # class
        self.prices = 'price__fraction'  # class
        
    def navigate(self):
        self.driver.get(self.url)

    def close(self):
        self.driver.close()

    def get_names(self):
        req = requests.get(self.url, headers = self.headers)
        global req_name
        req_name = req
        soup = BeautifulSoup(req.content, 'html.parser')
        time.sleep(2)
        elements = soup.find_all(class_=self.names)
        names_ = [i.get_text() for i in elements]
        return names_

    def get_prices1(self):
        req = requests.get(self.url, headers = self.headers)
        global req_price1
        req_price1 = req
        soup = BeautifulSoup(req.content, 'html.parser')
        time.sleep(2)
        elements = soup.find_all(class_=self.prices)
        prices_ = [i.get_text() for i in elements]
        return prices_

    def get_prices2(self):
        req = requests.get(self.url, headers=self.headers)
        global req_price2
        req_price2 = req
        soup = BeautifulSoup(req.content, 'html.parser')
        time.sleep(2)
        elements = soup.find_all(class_='pdp_options__text pdp_options--no-margin')
        prices_ = [i.get_text() for i in elements]
        return prices_


t0 = time.time()
gg = webdriver.Chrome()
g = MercadoLivre(gg)
g.navigate()
time.sleep(4)
names = g.get_names()
time.sleep(1)
prices1 = g.get_prices1()
time.sleep(1)
prices2 = g.get_prices2()

try:
    for i in range(len(prices2)):
        prices2[i] = prices2[i][4:9]

    prices2 = [element.partition(' ')[0] for element in prices2]
    prices = prices1 + prices2

    reduct = lambda x, y: x[:-y]

    if len(names) > len(prices):
        excess = len(names) - len(prices)
        names = reduct(names, excess)
    elif len(prices) > len(names):
        excess = len(prices) - len(names)
        prices = reduct(prices, excess)

    names = [name.strip() for name in names]
    content = list(zip(names, prices))

    for element in content:
        print(f'{element[0]}: R${element[1]}')

    # products = {'Name': names, 'Price': prices}
    # data_frame = pandas.DataFrame(products, columns= ['Name', 'Price'])
    # path = os.getcwd() + '\Mercado_Livre.csv'
    # data_frame.to_csv(path, index = False, header=True)
except:
    raise Exception('Something went wrong')
finally:
    g.close()
    t1 = time.time()
    print(f'\nRuntime: {(t1-t0):.3f}s')

