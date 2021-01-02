import pandas as pd
from pandas import ExcelWriter
from pandas import ExcelFile

df = pd.read_excel('MOCK_DATA.xlsx')

#print df.columns:
#out: Index(['id', 'first_name', 'last_name',
# 'gender', 'race', 'language', 'email','ip_address'],
#      dtype='object')

english_speakers = []
for i in df.index:
    if df['language'][i] == 'English':
        row_content = []
        for col in df:
            row_content.append(df[col].values[i])
        english_speakers.append(row_content)

col = df.columns
columns = []
for i in range(len(english_speakers[0])):
    column = []
    for row in english_speakers:
        column.append(row[i])
    columns.append(column)

df2 = pd.DataFrame({
col[0]: columns[0],
col[1]: columns[1],
col[2]: columns[2],
col[3]: columns[3],
col[4]: columns[4],
col[5]: columns[5],
col[6]: columns[6],
col[7]: columns[7]})

''' Método alternativo
english_speakers = df[df["language"] == "English"]
writer = ExcelWriter("MOCK_DATA_ENGLISH.xlsx")
english_speakers.to_excel(writer, 'sheet')
'''

writer = ExcelWriter('MOCK_DATA_ENGLISH.xlsx')
df2.to_excel(writer, 'sheet', index = False)
writer.save()