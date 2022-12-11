import pandas as pd
from matplotlib import pyplot as plt

plt.rcParams["figure.figsize"] = [7.00, 3.00]
plt.rcParams["figure.autolayout"] = True

columns = ['B1', 'B5', 'B10', 'RN', 'AVL']

df = pd.read_csv("arvore_medio.csv", usecols=columns, sep=";")
df.plot()

plt.yscale("linear")
plt.title('Caso médio')
plt.xlabel('Qtd Chaves')
plt.ylabel('Média de processamentos')
plt.savefig("arvore_medio.png")

df = pd.read_csv("arvore_pior.csv", usecols=columns, sep=";")
df.plot()
plt.yscale("linear")
plt.title('Pior caso')
plt.xlabel('Qtd Chaves')
plt.ylabel('Média de processamentos')
plt.savefig("arvore_pior.png")
