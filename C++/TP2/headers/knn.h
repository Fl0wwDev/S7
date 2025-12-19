#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>
#include "timeSeriesDataset.h"

using namespace std;

class KNN {
private:
    int k;                        // Nombre de voisins
    string similarity_measure;    // "euclidean_distance" ou "dtw"

public:
    // Constructeur
    KNN(int k = 1, const string& measure = "euclidean_distance");

    // Prédit la classe d'une série temporelle
    int predict(const TimeSeriesDataset& trainData, const vector<double>& testSeries) const;

    // Évalue le modèle et retourne l'accuracy
    double evaluate(const TimeSeriesDataset& trainData, 
                    const TimeSeriesDataset& testData, 
                    const vector<int>& ground_truth) const;

    // Getters
    int getK() const;
    string getSimilarityMeasure() const;

    // Setters
    void setK(int k);
    void setSimilarityMeasure(const string& measure);
};

#endif
