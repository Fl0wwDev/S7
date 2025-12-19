#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H

#include <vector>
#include <string>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;                          // Si true, normalise les séries avec Z-normalization
    bool isTrain;                             // Si true, c'est un jeu d'entraînement
    int maxLength;                            // Longueur maximale des séries
    int numberOfSamples;                      // Nombre d'échantillons (séries) dans le dataset
    vector<vector<double>> data;              // Données (séries temporelles)
    vector<int> labels;                       // Étiquettes associées aux séries

    // Méthodes privées pour la normalisation
    double calculateMean(const vector<double>& series) const;
    double calculateStdDev(const vector<double>& series, double mean) const;
    vector<double> zNormalize(const vector<double>& series) const;

public:
    // Constructeur
    TimeSeriesDataset(bool normalize = false, bool train = true, int maxLen = 0);

    // Méthodes statiques pour le calcul de distance
    static double euclidean_distance(const vector<double>& x, const vector<double>& y);
    static double dtw_distance(const vector<double>& x, const vector<double>& y);

    // Ajoute une série temporelle au dataset
    void addTimeSeries(const vector<double>& series, int label = 0);

    // Getters
    bool isZNormalized() const;
    bool getIsTrain() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;
    const vector<vector<double>>& getData() const;
    const vector<int>& getLabels() const;
    vector<double> getTimeSeries(int index) const;
    int getLabel(int index) const;

    // Setters
    void setZNormalize(bool normalize);
    void setIsTrain(bool train);

    // Affichage
    void printInfo() const;
    void printTimeSeries(int index) const;
};

#endif
