from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
import time

class Twich_ping:

    def __init__(self, driver):
        self.driver = driver
        self.url = "https://twitchstatus.com/"
        self.TMIping = '/html/body/div[2]/section[2]/table/tbody/tr[3]/td[4]' #xpath
    
    def navigate(self):
        self.driver.get(self.url)
    
    def get_TMIping(self):
        aux = self.driver.find_element_by_xpath(self.TMIping)
        return aux.text

options = Options()
options.headless = True
gg = webdriver.Chrome(ChromeDriverManager().install(), chrome_options= options)
g = Twich_ping(gg)
g.navigate()
time.sleep(2)
ping_0 = 0
for i in range(10):
    ping = g.get_TMIping()
    while ping == ping_0:
        try:
            ping = g.get_TMIping()
            gg.refresh()
            time.sleep(2)
        except:
            print("error fetching")
            continue
    ping_0 = ping
    print(ping)
    time.sleep(1)
gg.close()
