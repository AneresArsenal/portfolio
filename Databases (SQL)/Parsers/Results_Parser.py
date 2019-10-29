## Description: HTML Parser to extract result tables from transfermarkt.co.uk for database project
## Date: Friday April 19, 2019

import requests
from bs4 import BeautifulSoup
import pandas as pd
import numpy as np


headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36'}

url = "https://www.transfermarkt.co.uk/premier-league/heimtabelle/wettbewerb/GB1/saison_id/"
#"https://www.transfermarkt.co.uk/premier-league/tabelle/wettbewerb/GB1?saison_id="


data = []

#loop through 18 seasons results to store in database
for i in range(2010,2018):

    pageTree = requests.get((url +str(i)), headers=headers)
    soup = BeautifulSoup(pageTree.content, "html.parser")
    table = soup.find("div", {"class":"box"} )
    table_body = table.find('tbody')
    rows = table.find_all('tr')

    for each, row in enumerate(rows):
        cols = row.find_all('td')
        cols = [ele.text.strip() for ele in cols]
        cols.extend([i])
        data.append([ele for ele in cols if ele])


print(data)
    


#create dataframe
df = pd.DataFrame(data)
df.columns=["Rank","Team", "Games", "Win", "Draw", "Loss","Goals", "Goal Difference","Points", "Year"]
df = df.replace(to_replace='None', value=np.nan).dropna()

#print result to examine output
print(df)


#create unqiue file names for backup purposes
import time
timestr = time.strftime("%Y%m%d-%H%M%S")

df.to_csv((timestr + 'EPLTable.csv'))








# page = "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/a/ids/a/sa//saison_id/2018/saison_id_bis/2018/land_id/0/nat/0/pos//w_s//intern/0/plus/1"
#        "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/plus/1?ids=a&sa=&saison_id=2000&saison_id_bis=2000&land_id=&nat=&pos=&altersklasse=&w_s=&leihe=&intern=0"
#        "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/plus/0?ids=a&sa=&saison_id=2005&saison_id_bis=2005&land_id=&nat=&pos=&altersklasse=&w_s=&leihe=&intern=0"
# pageTree = requests.get(page, headers=headers)
# pageSoup = BeautifulSoup(pageTree.content, 'html.parser')

# #input table into pandas datframe
# table = pageSoup.find( "table", {"class":"items"} )
# table_body = table.find('tbody')
# rows = table_body.find_all('tr')
# data = []

# for row in rows:
#     cols = row.find_all('td')
#     cols = [ele.text.strip() for ele in cols]
#     data.append([ele for ele in cols if ele])



# # link to first page - without `page=`
# url = "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/a/ajax/yw1/ids/a/sa//saison_id/2018/saison_id_bis/2018/land_id/0/nat/0/pos//w_s//intern/0/plus/1/page/"
#       "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/plus/ajax/yw1/ids/a/sa//saison_id/2005/saison_id_bis/2005/land_id//nat//pos//altersklasse//w_s//leihe//intern/0/0//page/5"
#       "https://www.transfermarkt.co.uk/transfers/einnahmenausgaben/statistik/plus/ajax/yw1/ids/a/sa//saison_id/2000/saison_id_bis/2000/land_id//nat//pos//altersklasse//w_s//leihe//intern/0/0//page/5"

# page = 2

# for page in range(2,11):
#     # r = requests.get(url)

#     pageTree = requests.get((url +str(page)), headers=headers)
#     soup = BeautifulSoup(pageTree.content, "html.parser")
#     table = soup.find( "table", {"class":"items"} )
#     table_body = table.find('tbody')
#     rows = table.find_all('tr')

#     for row in rows:
#         cols = row.find_all('td')
#         cols = [ele.text.strip() for ele in cols]
#         data.append([ele for ele in cols if ele])

# #create dataframe
# df = pd.DataFrame(data)
# df.columns=["Rank","Team", "League", "Expenditures", "Arrivals", "Incomes","Departures", "Net Balance"]

# df = df.replace(to_replace='None', value=np.nan).dropna()

# # df.replace("", np.nan, inplace=True)
# # df.dropna(how='all')
# df["Year"] = 2018


# print(df)

# import time
# timestr = time.strftime("%Y%m%d-%H%M%S")

# df.to_csv((timestr + 'result.csv'))




# df = pd.DataFrame({"Clubs":ClubsList,"Expenditure":ExpendituresList})
# df

#input data into lists [manual col by col method]
# Clubs =  pageSoup.find_all("a", {"class": "vereinprofil_tooltip"})
# Expenditures = pageSoup.find_all("td",{"class": "rechts hauptlink redtext"})
# Amount = pageSoup.find_all("td",{"class": "zentriert"})
# Income = pageSoup.find_all("td",{"class": "rechts hauptlink greentext"})


# ClubsList = []

# ExpendituresList = []
# Amount = []

# for club in Clubs:
#     ClubsList.append(''.join(club.findAll(string=True)))

# ClubsList = list(filter(None, ClubsList))


# for expenditure in Expenditures:
#     ExpendituresList.append(''.join(expenditure.findAll(string=True)))


# for amount in Amounts:
#     AmountsList.append(''.join(amount.findAll(string=True)))
