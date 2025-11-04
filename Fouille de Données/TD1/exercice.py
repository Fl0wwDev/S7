import pandas as pd
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report, precision_score

df = pd.read_csv ('iris.csv', header =0)


real = ['setosa','setosa','versicolor','versicolor','virginica','virginica']
pred = ['setosa','setosa','versicolor','virginica','virginica','virginica']

print(confusion_matrix(real,pred))
print(classification_report(real,pred))
print(precision_score(real,pred,average='micro'))