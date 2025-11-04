import pandas as pd
import matplotlib.pyplot as plt




df = pd.read_csv('TD2/cockroft.csv')
age = df['age']
poids = df['poids']
creatininemie = df['creatininemie']

def clairance_de_cockcroft():
    clairance = ((140-age)*poids * 1.04) / creatininemie
    df["clairance_de_cockcroft"] = clairance
    return df 

def graphique():
    plt.title("l’âge des patientes, et leur poids")
    plt.xlabel("age")
    plt.ylabel("poids")
    plt.(age,poids)
    plt.show()

print(clairance_de_cockcroft())

print(graphique())