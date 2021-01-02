from selenium import webdriver
import time
from bs4 import BeautifulSoup
import requests

class Amazon:
    def __init__(self, driver):
        self.driver = driver
        self.url = 'https://www.amazon.com.br/'
        self.url2 = 'https://www.amazon.com.br/s?k=iphone&__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&ref=nb_sb_noss'
        self.bar = 'twotabsearchtextbox'  #id
        self.bar_btn = 'nav-input' #class
        self.names = 'a-size-medium a-color-base a-text-normal' #class
        self.prices1 = 'a-price-whole'  #class
        self.prices1_frac = 'a-price-fraction'  #class

    def navigate(self):
        self.driver.get(self.url)
    
    def close(self):
        self.driver.close()
    
    def search(self, word = 'none'):
        self.driver.find_element_by_id(self.bar).send_keys(word)
        self.driver.find_element_by_class_name(self.bar_btn).click()
        
    def get_names(self):
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36'}
        req = requests.get(self.url2, headers=headers)
        global req_name
        req_name = req
        soup = BeautifulSoup(req.content, 'html.parser') 
        time.sleep(2)
        elements = soup.find_all(class_=self.names)
        names_ = [i.get_text() for i in elements]
        return names_

    def get_prices(self):
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36'}
        req = requests.get(self.url2, headers=headers)
        global req_price
        req_price = req
        soup = BeautifulSoup(req.content, 'html.parser')
        time.sleep(2)
        elem = soup.find_all(class_=self.prices1)
        elem_frac = soup.find_all(class_=self.prices1_frac)
        temp1 = list(zip(elem, elem_frac))
        prices= []
        for el in temp1:
            prices.append(el[0].get_text() + '' + el[1].get_text())
        return prices

def filter_zero(x):
    if x == 0:
        return False
    return True
    
gg = webdriver.Chrome()
g = Amazon(gg)
g.navigate()
g.search('iphone')
time.sleep(6)
names = []
prices = []

while names == []:
    names = g.get_names()
    if names == []:
        g.close()
        g.navigate()
        g.search('iphone')
        time.sleep(3)
while prices == []:
    prices = g.get_prices()
    if prices == []:
        g.close()
        g.navigate()
        g.search('iphone')
        time.sleep(3)
        
print(names)
print()
f = lambda x: not(x == '0' or x == '0.00' or x == '0,00' or x == 0)
prices = list(filter(f, prices))
print(prices)
