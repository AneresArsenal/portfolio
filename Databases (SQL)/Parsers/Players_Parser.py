import requests
from bs4 import BeautifulSoup
import pandas as pd
import numpy as np


headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36'}

url1 = "https://www.transfermarkt.co.uk/transfers/saisontransfers/statistik?ajax=yw1&altersklasse=&ausrichtung=&land_id=0&leihe=&page="
url2 = "&plus=1&spielerposition_id="


data = []

for i in range(1,2):

    pageTree = requests.get((url1 +str(i) + url2), headers=headers)
    soup = BeautifulSoup(pageTree.content, "html.parser")
    table = soup.find("table", {"class":"items"} )
    table_body = table.find('tbody')
    rows = table.find_all('tr')

    for each, row in enumerate(rows):
        cols = row.find_all('td')
        cols = [ele.text.strip() for ele in cols]
        cols.extend([i])
        data.append([ele for ele in cols if ele])

print(data[1])

#create dataframe
df = pd.DataFrame(data)
df.columns=["#","Delete", "PlayerName","Position", "Age", "Market Value", "Delete1", "Departed from", "Departed league", "Delete2", "Joined","Country", "Transfer Fee", "Rank"]



df = df.replace(to_replace='None', value=np.nan).dropna()

df = df.drop(columns=['Delete', 'Delete1', 'Delete2', 'Rank'])
df = df.reset_index(drop=True)



import time
timestr = time.strftime("%Y%m%d-%H%M%S")

df.to_csv((timestr + 'PlayerTransfers.csv'))

