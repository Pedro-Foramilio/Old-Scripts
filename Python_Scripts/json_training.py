import json

tabela_jason = "" #insira json aqui

parsed_tbl = json.loads(tabela_jason)
print(json.dumps(parsed_tbl, indent = 2, separators = (";", "=")))

creditos_feitos = 0
for item in parsed_tbl:
    creditos_feitos += item["creditos"]
print("creditos feitos:", creditos_feitos)