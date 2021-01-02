
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options

class Google:
    def __init__(self, driver):
        self.driver = driver
        self.url = 'http://google.com.br'
        self.search_bar = 'q'
        self.btn_search = '/html/body/div[1]/div[3]/form/div[2]/div[1]/div[3]/center/input[1]'
        
    def navigate(self):
        self.driver.get(self.url)
        
    def search(self, word = 'None'):
        self.driver.find_element_by_name(self.search_bar
                                             ).send_keys(word)
        self.driver.find_element_by_xpath(self.btn_search).click()
            
            
            
            
options = Options()
options.headless = False
gg = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=options)
g = Google(gg)
g.navigate()
g.search('iPhone mercado livre')
