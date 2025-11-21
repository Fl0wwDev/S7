import kagglehub
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
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

# plt.figure(figsize=(12, 6))
# plt.bar(inds, vals1, width, color=color1)
# plt.bar(inds+width, vals2, width, color=color2)
# plt.gca().set_xticklabels(frame['Type 1'].value_counts().index)
# plt.gca().set_xticks(inds+width)
# plt.xticks(rotation=90)
# plt.legend(handles=handles)
# plt.title("Distribution des types de Pokémon (Type 1 vs Type 2)")
# plt.ylabel("Nombre de Pokémon")
# plt.xlabel("Type")
# plt.tight_layout()
# plt.show(block=False)

df_full = frame.copy()
df_full['Legendary_map'] = df_full['Legendary'].map({True: 'Legendary', False: 'Non-Legendary'})

# cols = ['HP','Attack','Defense','Sp. Atk','Sp. Def','Speed']
# for i,c in enumerate(cols): 
#     sns.set_style('whitegrid')
#     g = sns.FacetGrid(df_full, col="Generation", hue='Legendary_map', height=2.5, aspect=0.8, palette=['red','black'])
#     g.set_axis_labels("Total", c)
#     g.map(sns.scatterplot, 'Total', c)
#     g.add_legend()
#     plt.show(block=False)

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

k_values = [1, 3, 5, 7, 9, 11, 15, 20]
knn_results = []

for k in k_values:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train_scaled, y_train)
    y_pred = knn.predict(X_test_scaled)
    acc = accuracy_score(y_test, y_pred)
    knn_results.append((k, acc))

best_k, best_acc_knn = max(knn_results, key=lambda x: x[1])

best_knn = KNeighborsClassifier(n_neighbors=best_k)
best_knn.fit(X_train_scaled, y_train)
y_pred_knn = best_knn.predict(X_test_scaled)
cm_knn = confusion_matrix(y_test, y_pred_knn)

plt.figure(figsize=(8, 6))
sns.heatmap(cm_knn, annot=True, fmt='d', cmap='Blues', 
            xticklabels=['Non-Legendary', 'Legendary'],
            yticklabels=['Non-Legendary', 'Legendary'])
plt.title(f'Matrice de confusion KNN (k={best_k})')
plt.ylabel('Vraie classe')
plt.xlabel('Classe prédite')
plt.tight_layout()
plt.show()