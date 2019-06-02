import pandas as pd
import numpy as np


data = pd.read_csv('2016-2018.csv')

# subset data to fit to table attributes in cashflow table
data = data[['Team','Expenditures','Incomes', 'Year']]
data = data.rename(columns = {'Team':'club', 'Year':'year'})
data = pd.melt(data, id_vars=['club', 'year'], value_vars=['Expenditures', 'Incomes'])
data = data.rename(columns = {'value':'amount'})
data = data[['club', 'year', 'amount', 'variable']]

#clean year column
data['year'] = pd.to_numeric(data['year'], downcast='signed')

#clean amount column
data['amount'] = data['amount'].astype('str')
data['amount'] = data['amount'].astype(str).str.replace('m','')
data['amount'] = data['amount'].astype(str).str.replace('k','')
data['amount'] = data['amount'].astype(str).str.replace('£','')
data['amount'] = data['amount'].astype(str).str.replace('-','0')
data['amount'] = pd.to_numeric(data['amount'], downcast='signed')
data['amount'] = np.where( data['variable'] == 'Expenditures', data['amount']*-1, data['amount'])
data = data[['club', 'year', 'amount']]
print(data.dtypes)
print (data)

#export file
import time
timestr = time.strftime("%Y%m%d-%H%M%S")
data.to_csv((timestr + 'cashflow.csv'))