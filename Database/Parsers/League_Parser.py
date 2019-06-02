import pandas as pd
import numpy as np


data = pd.read_csv('2016-2018.csv')

# subset data to fit to table attributes in cashflow table
data = data[['Team','League','Year']]
data = data.rename(columns = {'Team':'club', 'League':'league', 'Year':'year'})


#clean year column
data['year'] = pd.to_numeric(data['year'], downcast='signed')


# print(data.dtypes)
# print (data)

#export file
import time
timestr = time.strftime("%Y%m%d-%H%M%S")
# data.to_csv((timestr + 'club_league.csv'))

#create database for clubs and leagues
club = data['club'].copy().drop_duplicates().reset_index(drop=True)
print(club)
club.to_csv((timestr + 'club.csv'))

league = data['league'].copy().drop_duplicates().reset_index(drop=True)
league.to_csv((timestr + 'league.csv'))
print(league)