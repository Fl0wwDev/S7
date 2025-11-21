import kagglehub
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import warnings
warnings.filterwarnings('ignore')

frame = pd.read_csv(f"Pokemon.csv")

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

print("\n" + "="*60)
print("CLASSIFICATION DES POKÉMON LÉGENDAIRES")
print("="*60)

features = ['HP', 'Attack', 'Defense', 'Sp. Atk', 'Sp. Def', 'Speed', 'Total', 'Generation']
X = df_full[features].values
y = df_full['Legendary'].values

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

print(f"\nTaille du jeu d'entraînement : {len(X_train)} Pokémon")
print(f"Taille du jeu de test : {len(X_test)} Pokémon")
print(f"Proportion de légendaires : {y.sum() / len(y) * 100:.2f}%")

print("\n" + "-"*60)
print("1. K-PLUS PROCHES VOISINS (KNN)")
print("-"*60)

k_values = [1, 3, 5, 7, 9, 11, 15, 20]
knn_results = []

for k in k_values:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train_scaled, y_train)
    y_pred = knn.predict(X_test_scaled)
    acc = accuracy_score(y_test, y_pred)
    knn_results.append((k, acc))
    print(f"  k={k:2d} : Accuracy = {acc:.4f} ({acc*100:.2f}%)")

best_k, best_acc = max(knn_results, key=lambda x: x[1])
print(f"\n✓ Meilleur k : {best_k} avec accuracy = {best_acc:.4f}")

best_knn = KNeighborsClassifier(n_neighbors=best_k)
best_knn.fit(X_train_scaled, y_train)
y_pred_knn = best_knn.predict(X_test_scaled)

print("\nRapport de classification (KNN) :")
print(classification_report(y_test, y_pred_knn, target_names=['Non-Legendary', 'Legendary']))

print("Matrice de confusion (KNN) :")
print(confusion_matrix(y_test, y_pred_knn))

print("\n" + "-"*60)
print("2. ARBRES DE DÉCISION")
print("-"*60)

max_depths = [None, 3, 5, 7, 10, 15, 20]
dt_results = []

for depth in max_depths:
    dt = DecisionTreeClassifier(max_depth=depth, random_state=42)
    dt.fit(X_train, y_train)
    y_pred = dt.predict(X_test)
    acc = accuracy_score(y_test, y_pred)
    dt_results.append((depth, acc))
    depth_str = "None" if depth is None else f"{depth:2d}"
    print(f"  max_depth={depth_str:4s} : Accuracy = {acc:.4f} ({acc*100:.2f}%)")

best_depth, best_acc_dt = max(dt_results, key=lambda x: x[1])
print(f"\n✓ Meilleure profondeur : {best_depth} avec accuracy = {best_acc_dt:.4f}")

best_dt = DecisionTreeClassifier(max_depth=best_depth, random_state=42)
best_dt.fit(X_train, y_train)
y_pred_dt = best_dt.predict(X_test)

print("\nRapport de classification (Arbre de décision) :")
print(classification_report(y_test, y_pred_dt, target_names=['Non-Legendary', 'Legendary']))

print("Matrice de confusion (Arbre de décision) :")
print(confusion_matrix(y_test, y_pred_dt))

print("\n" + "="*60)
print("COMPARAISON DES MODÈLES")
print("="*60)
print(f"KNN (k={best_k})                : {best_acc:.4f} ({best_acc*100:.2f}%)")
print(f"Arbre de décision (depth={best_depth}) : {best_acc_dt:.4f} ({best_acc_dt*100:.2f}%)")