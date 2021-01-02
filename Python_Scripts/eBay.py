from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
import pandas
import time
import os

class eBay:
    
    def __init__(self, driver):
        self.driver = driver
        self.url = "https://www.ebay.com/"
        self.bar = "_nkw"  # name
    
    def navigate(self):
        self.driver.get(self.url)
    
    def search(self, word = "None"):
        self.driver.find_element_by_name(self.bar).send_keys(word)
        self.driver.find_element_by_name(self.bar).send_keys(Keys.ENTER)
    
    def get_names(self):
        names = self.driver.find_elements_by_class_name("s-item__title")
        return [name.text for name in names]
    
    def get_prices(self):
        prices = self.driver.find_elements_by_class_name("s-item__price")
        return [price.text for price in prices]


options = Options()
options.headless = True
gg = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=options)
g = eBay(gg)
g.navigate()
g.search(input("Search input: "))
new_url = gg.current_url
g.url = new_url
time.sleep(1)
names = g.get_names()
prices = g.get_prices()
tam_prices = len(prices)
tam_names = len(names)
gg.close()

for i in range(tam_names):
    if "NOVO ANÚNCIO" == names[i][:12]:
        names[i] = names[i][12:]
        

if tam_names == tam_prices:
    content = list(zip(names, prices))
else:
    gap = abs(tam_names - tam_prices)
    if tam_names < tam_prices:
        prices = prices[:tam_prices-gap]
    if tam_names > tam_prices:
        names = names[:tam_names-gap]
    content = list(zip(names, prices))

question = input("You wish to create excel file with serach results? (Y/N)? ")
if question[0].upper().strip() in ["Y", "S"]:
    products = {"Name": names, "Price": prices}
    data_frame = pandas.DataFrame(products, columns= ["Name", "Price"])
    path = os.getcwd() + '\eBay.xlsx'
    data_frame.to_excel(path, index=False, header=True)

print("Data found:")
for tuple_ in content:
    print(tuple_[0])
    print(tuple_[1])
    print("---------------------")
print("end.")
if question[0].upper().strip() in ["Y", "S"]:
    print("File saved in excel format")
