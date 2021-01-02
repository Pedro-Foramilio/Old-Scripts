from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
import time

class Scrap:

    def __init__(self, driver):
        self.driver = driver
        self.url = "https://www.ebay.com/"
        self.bar = "_nkw" #name
        self.boxes = "s-item__wrapper" #class
        self.name = "s-item__title" #class
        self.price = "s-item__price" #class
    
    def navigate(self):
        self.driver.get(self.url)
    
    def search(self, word):
         self.driver.find_element_by_name(self.bar).send_keys(word)
         self.driver.find_element_by_name(self.bar).send_keys(Keys.ENTER)

    def get_boxes(self):
        return self.driver.find_elements_by_class_name(self.boxes) #creates a list of boxes
    
    def get_content(self, boxes: list):
        products = [] # (name, price)
        for box in boxes:
            name = box.find_element_by_class_name(self.name)
            name = name.text
            price = box.find_element_by_class_name(self.price)
            price = price.text
            products.append([name, price])
        return products
             


gg = webdriver.Chrome(ChromeDriverManager().install())
g = Scrap(gg)
g.navigate()
time.sleep(2)
g.search("SSD")
time.sleep(0.5)
new_url = gg.current_url
g.url = new_url
boxes = g.get_boxes()
products = g.get_content(boxes)
for product in products:
    if 'NOVO ANÚNCIO' in product[0]:
        product[0] = product[0][12:]
gg.close()
for produto in products:
    print(produto[0])
    print(produto[1])
    print("-----------------")