# --- 2.2 Librairies [cite: 36-43] ---
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

url = 'http://archive.ics.uci.edu/ml/machine-learning-databases/auto-mpg/auto-mpg.data'
column_names = ['MPG', 'Cylinders', 'Displacement', 'Horsepower', 'Weight',
                'Acceleration', 'Model Year', 'Origin']

raw_dataset = pd.read_csv(url, names=column_names,
                          na_values='?', comment='\t',
                          sep=' ', skipinitialspace=True)

dataset = raw_dataset.copy()

# --- 2.3.2 Nettoyage des données [cite: 55-58] ---
dataset = dataset.dropna()

# Encodage One-Hot pour 'Origin' [cite: 65]
dataset['Origin'] = dataset['Origin'].map({1: 'USA', 2: 'Europe', 3: 'Japan'})
dataset = pd.get_dummies(dataset, columns=['Origin'], prefix='', prefix_sep='')

# --- 2.3.3 Train / Test Split [cite: 67, 68] ---
train_dataset = dataset.sample(frac=0.8, random_state=0)
test_dataset = dataset.drop(train_dataset.indexx)

# --- 2.3.4 Visualisation rapide (Optionnel mais demandé) [cite: 73] ---
# sns.pairplot(train_dataset[['MPG', 'Cylinders', 'Displacement', 'Weight']], diag_kind='kde')
# plt.show()

# --- 2.3.5 Séparation Labels / Features [cite: 84, 85] ---
train_features = train_dataset.copy()
test_features = test_dataset.copy()

train_labels = train_features.pop('MPG')
test_labels = test_features.pop('MPG')

# --- 2.3.6 Normalisation [cite: 92, 94] ---
normalizer = tf.keras.layers.Normalization(axis=-1)
normalizer.adapt(np.array(train_features))

print("Données prêtes. Exemple normalisé :")
first = np.array(train_features[:1])
print(normalizer(first).numpy())