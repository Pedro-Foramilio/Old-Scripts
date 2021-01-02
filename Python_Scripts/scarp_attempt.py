from selenium import webdriver

class Scrap:
    def __init__(self, driver):
        self.driver = driver
        self.url = 'https://minecraft.gamepedia.com/Java_Edition_version_history'
        self.tables = 'wikitable'  #class
    def navigate(self):
        self.driver.get(self.url)
    
    def get_tables(self):
        return self.driver.find_elements_by_class_name(self.tables)

    def get_version(self):
        tables = list(self.get_tables)
        for table in tables:
            row_count = len(self.driver.find_element_by_xpath('/html/body/div[2]/div[3]/div[1]/div[4]/div[4]/div/div[5]/table/tbody/tr')) 
            base = '/html/body/div[2]/div[3]/div[1]/div[4]/div[4]/div/div[6]/table/tbody/tr[2]/td[2]/a'
            for i in range(len(tables)):
            
            
gg = webdriver.Chrome()
g = Scrap(gg)
g.navigate()



'''
tables = list(g.get_tables())
for version in tables:
    print(g.get_version())
'''
