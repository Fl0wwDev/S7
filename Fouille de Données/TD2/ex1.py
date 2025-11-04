import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv('TD2/herbicide.csv',header=0)
nb_plants = df["nb_plants"]
arr= nb_plants.values.astype(float)

mean = np.mean(arr)
variance = np.var(arr)
std = np.std(arr)
min_val = np.min(arr)
max_val = np.max(arr)

df["survival_pct"] = (df["nb_plants_survivants"].astype(float) / df["nb_plants"].astype(float)) * 100
df["survival_pct"] = df["survival_pct"].round(2)

mask = df["survival_pct"] < 5
count = mask.sum()                    
print(f"Nombre d'expérimentations avec < 5% de survivants : {count}")


temoin = df[df["herbicide"].str.contains("aucun")]
temoin_pct = temoin["survival_pct"].astype(float).values
mean_temoin = np.mean(temoin_pct)
std_temoin = np.std(temoin_pct)


plt.figure(figsize=(8,5))
plt.hist(df["survival_pct"].dropna(), bins=20, color='C0', edgecolor='black')
plt.title("Histogramme du pourcentage de plantes survivantes")
plt.xlabel("Taux de survie (%)")
plt.ylabel("Nombre d'expérimentations")
plt.grid(axis='y', alpha=0.3)
plt.tight_layout()
plt.show()

plt.figure(figsize=(6,6))
counts = df['plante'].value_counts()
labels = counts.index.tolist()
sizes = counts.values
plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=90, colors=plt.cm.Set3.colors)
plt.title("Proportion des plantes dans l'étude")
plt.axis('equal')
plt.tight_layout()
plt.show()



treated = df[df["herbicide"] != "aucun"]

plt.figure(figsize=(8,5))
sns.boxplot(x="plante", y="survival_pct", data=treated, palette="Set2")
sns.stripplot(x="plante", y="survival_pct", data=treated, color="k", size=3, jitter=True, alpha=0.6)
plt.title("Taux de survie par espèce (traitements)")
plt.ylabel("Taux de survie (%)")
plt.xlabel("Espèce")
plt.tight_layout()
plt.show()

# Espèce qui résiste le mieux aux herbicides (moyenne sur traitements)
best_species = treated.groupby("plante")["survival_pct"].mean().idxmax()
best_species_mean = treated.groupby("plante")["survival_pct"].mean().max()
print(f"Espèce la mieux résistante (moyenne sous herbicides) : {best_species} ({best_species_mean:.2f}%)")

plt.figure(figsize=(8,5))
sns.boxplot(x="herbicide", y="survival_pct", data=df, palette="Set3")
sns.stripplot(x="herbicide", y="survival_pct", data=df, color="k", size=3, jitter=True, alpha=0.6)
plt.title("Taux de survie par herbicide")
plt.ylabel("Taux de survie (%)")
plt.xlabel("Herbicide")
plt.tight_layout()
plt.show()

best_herb = treated.groupby("herbicide")["survival_pct"].mean().idxmin()
best_herb_mean = treated.groupby("herbicide")["survival_pct"].mean().min()
print(f"Herbicide le plus efficace (moyenne survie la plus basse) : {best_herb} ({best_herb_mean:.2f}%)")

plt.figure(figsize=(8,5))
sns.stripplot(x="herbicide", y="survival_pct", hue="plante", data=df, jitter=True, dodge=True, palette="Set1")
plt.title("Dispersion du taux de survie par herbicide et plante")
plt.ylabel("Taux de survie (%)")
plt.xlabel("Herbicide")
plt.legend(title="Plante")
plt.tight_layout()
plt.show()

pivot = df.pivot_table(values="survival_pct", index="herbicide", columns="plante", aggfunc="mean")
print("\nTableau des taux moyens de survie (herbicide x plante) :")
print(pivot.round(2))

plt.figure(figsize=(6,5))
sns.heatmap(pivot, annot=True, fmt=".1f", cmap="YlOrRd", cbar_kws={'label': 'Taux de survie (%)'})
plt.title("Heatmap : taux moyen de survie par herbicide et plante")
plt.ylabel("Herbicide")
plt.xlabel("Plante")
plt.tight_layout()
plt.show()


min_val = pivot.min().min()
min_pos = list(zip(*((pivot == min_val).to_numpy().nonzero())))
# retrouver labels
if len(min_pos) > 0:
    row_idx, col_idx = min_pos[0]
    herb_min = pivot.index[row_idx]
    plante_min = pivot.columns[col_idx]
    print(f"\nCombinaison la plus destructive : herbicide '{herb_min}' sur plante '{plante_min}' (survie {min_val:.2f}%).")
else:
    print("\nImpossible de localiser la valeur minimale dans le pivot.")

if "ble" in pivot.columns:
    ble_by_herb = pivot["ble"].sort_values(ascending=False)
    preferred_for_ble = ble_by_herb.idxmax()
    print(f"Herbicide le plus favorable pour le blé (le laisse le mieux) : {preferred_for_ble} ({ble_by_herb.max():.2f}%).")
else:
    print("Colonne 'ble' absente du pivot.")

print("Expérience suggérée : tester des dosages croissants et/ou combinaisons d'herbicides sur parcelles témoins pour optimiser efficacité vs sélectivité.")