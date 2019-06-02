## Description: HTML Parser to extract income and expenditure tables from transfermarkt.co.uk for database project
## Date: Friday April 19, 2019




import requests
from bs4 import BeautifulSoup
import pandas as pd
import numpy as np


headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36'}

url1 =   "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/a/ids/a/sa//saison_id/"
url2 =   "/saison_id_bis/"
url3 =   "/land_id/0/nat/0/pos//w_s//intern/0/plus/5/page/"

data = []

# Loop through all pages to extract full table from website

for i in range(2016,2019):

    url = url1 +str(i)+ url2 + str(i) + url3

    for page in range(1,11):

        pageTree = requests.get((url +str(page)), headers=headers)
        soup = BeautifulSoup(pageTree.content, "html.parser")
        table = soup.find( "table", {"class":"items"} )
        table_body = table.find('tbody')
        rows = table.find_all('tr')

        for each, row in enumerate(rows):
            cols = row.find_all('td')
            cols = [ele.text.strip() for ele in cols]
            cols.extend([i])
            data.append([ele for ele in cols if ele])




#create dataframe
df = pd.DataFrame(data)
df.columns=["Rank","Team", "League", "Expenditures", "Arrivals", "Incomes","Departures", "Net Balance", "Year"]
df = df.replace(to_replace='None', value=np.nan).dropna()


#to review output
print(df)


#to create unique filenames for backup purposes
import time
timestr = time.strftime("%Y%m%d-%H%M%S")

df.to_csv((timestr + 'AnnualSpending.csv'))

