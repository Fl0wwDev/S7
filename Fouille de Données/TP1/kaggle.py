import kagglehub
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import seaborn as sns

frame = pd.read_csv(f"Pokemon.csv")

# Graphique des types les plus courants
vals1 = [frame['Type 1'].value_counts()[key] for key in frame['Type 1'].value_counts().index]
vals2 = [frame['Type 2'].value_counts()[key] for key in frame['Type 1'].value_counts().index]
inds = np.arange(len(frame['Type 1'].value_counts().index))
width = .45
color1 = '#1f77b4'
color2 = '#2ca02c'
handles = [patches.Patch(color=color1, label='Type 1'), patches.Patch(color=color2, label='Type 2')]

plt.figure(figsize=(12, 6))
plt.bar(inds, vals1, width, color=color1)
plt.bar(inds+width, vals2, width, color=color2)
plt.gca().set_xticklabels(frame['Type 1'].value_counts().index)
plt.gca().set_xticks(inds+width)
plt.xticks(rotation=90)
plt.legend(handles=handles)
plt.title("Distribution des types de Pokémon (Type 1 vs Type 2)")
plt.ylabel("Nombre de Pokémon")
plt.xlabel("Type")
plt.tight_layout()
plt.show(block=False)


df_full = frame.copy()
df_full['Legendary_map'] = df_full['Legendary'].map({True: 'Legendary', False: 'Non-Legendary'})

cols = ['HP','Attack','Defense','Sp. Atk','Sp. Def','Speed']
for i,c in enumerate(cols): 
    sns.set_style('whitegrid')
    g = sns.FacetGrid(df_full, col="Generation", hue='Legendary_map', height=2.5, aspect=0.8, palette=['red','black'])
    g.set_axis_labels("Total", c)
    g.map(sns.scatterplot, 'Total', c)
    g.add_legend()
    plt.show(block=False)
    

max_total = df_full['Total'].max()
pokemon_max = df_full.loc[df_full['Total'] == max_total, 'Name'].values
print(f"\nLes Pokémon avec le plus de stats sont:")
for name in pokemon_max:
    print(f"  - {name}")


min_total = df_full['Total'].min()
pokemon_min = df_full.loc[df_full['Total'] == min_total, 'Name'].values
print(f"\nLe Pokémon avec le moins de stats sont:")
for name in pokemon_min:
    print(f"  - {name}")


plt.pause(2)
input("appuyez pour stop")