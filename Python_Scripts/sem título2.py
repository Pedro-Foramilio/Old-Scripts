### THIS FORM IS LIKELY TO BE OUTDATED OR EVEN UNAVAIBLE

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
import time

class Attack:
    
    def __init__(self, driver):
        self.driver = driver
        self.url = 'https://docs.google.com/forms/d/e/1FAIpQLSf0uVHTePT3TzVngi6UKyx20R0gIswdAcBu1Uf7pT9YJmM5Ww/viewform'
        self.paths = [
            '/html/body/div/div[2]/form/div/div/div[2]/div[1]/div/div[2]/div/span/div/div[1]/label/div/div[1]/div',
            '/html/body/div/div[2]/form/div/div/div[2]/div[2]/div/div[2]/div/span/div/div[6]/label/div/div[1]/div',
            '/html/body/div/div[2]/form/div/div/div[2]/div[3]/div/div[2]/div/span/div/div[1]/label/div/div[1]/div',
            '/html/body/div/div[2]/form/div/div/div[2]/div[4]/div/div[2]/div/span/div/div[1]/label/div/div[1]/div',
            '/html/body/div/div[2]/form/div/div/div[2]/div[5]/div/div[2]/div/span/div/div[2]/label/div/div[1]/div',
            '/html/body/div/div[2]/form/div/div/div[2]/div[6]/div/div[2]/div/span/div/div[3]/label/div/div[1]/div',
            '/html/body/div/div[2]/form/div/div/div[2]/div[7]/div/div[2]/div/span/div/div[1]/label/div/div[1]/div'
            ]
        self.send = '/html/body/div/div[2]/form/div/div/div[3]/div/div/div'

    def navigate(self):
        self.driver.get(self.url)
    
    def click(self):
        for path in self.paths:
            self.driver.find_element_by_xpath(path).click()
    
    def send(self):
        self.driver.find_element_by_xpath(
        '/html/body/div/div[2]/form/div/div/div[3]/div/div/div').click()

def main():
    global gg
    options = Options()
    options.headless = True
    gg = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=options)
    g = Attack(gg)
    g.navigate()
    time.sleep(1.5)
    g.click()
    time.sleep(0.8)
    gg.find_element_by_xpath(
        '/html/body/div/div[2]/form/div/div/div[3]/div/div/div').click()
    time.sleep(0.5)
    gg.close()
    

submissions = 50
ok = 0
errors = 0
for i in range(submissions):
    try:
        main()
        ok += 1
        print("submission successed.")
    except:
        errors += 1
        gg.close()
        print("submission failed")
        continue
print(f"finnished {submissions} executions with:")
print(f"{ok} successful submissions")
print(f"{errors} errors")
