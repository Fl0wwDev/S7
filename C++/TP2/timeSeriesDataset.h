#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H

#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;                          // Si true, normalise les séries
    int maxLength;                            // Longueur maximale des séries
    int numberOfSeries;                       // Nombre de séries dans le dataset
    vector<vector<double>> data;              // Données (séries temporelles)
    vector<int> labels;                       // Étiquettes associées aux séries

    // Calcule la moyenne d'une série temporelle
    double calculateMean(const vector<double>& series) const {
        if (series.empty()) return 0.0;
        double sum = accumulate(series.begin(), series.end(), 0.0);
        return sum / series.size();
    }

    // Calcule l'écart-type d'une série temporelle
    double calculateStdDev(const vector<double>& series, double mean) const {
        if (series.empty()) return 1.0;
        
        double sumSquaredDiff = 0.0;
        for (double value : series) {
            double diff = value - mean;
            sumSquaredDiff += diff * diff;
        }
        
        double variance = sumSquaredDiff / series.size();
        double stdDev = sqrt(variance);
        
        // Éviter la division par zéro
        return (stdDev == 0.0) ? 1.0 : stdDev;
    }

    // Normalise une série temporelle avec la normalisation Z
    vector<double> zNormalize(const vector<double>& series) const {
        if (series.empty()) return series;
        
        double mean = calculateMean(series);
        double stdDev = calculateStdDev(series, mean);
        
        vector<double> normalized;
        normalized.reserve(series.size());
        
        for (double value : series) {
            double normalizedValue = (value - mean) / stdDev;
            normalized.push_back(normalizedValue);
        }
        
        return normalized;
    }

public:
    // Constructeur par défaut
    TimeSeriesDataset(bool normalize = false, int maxLen = 0)
        : znormalize(normalize), maxLength(maxLen), numberOfSeries(0) {}

    // Ajoute une série temporelle au dataset
    void addTimeSeries(const vector<double>& series, int label = 0) {
        vector<double> seriesToAdd = series;
        
        // Normaliser si nécessaire
        if (znormalize && !series.empty()) {
            seriesToAdd = zNormalize(series);
        }
        
        // Mettre à jour la longueur maximale
        if (seriesToAdd.size() > static_cast<size_t>(maxLength)) {
            maxLength = seriesToAdd.size();
        }
        
        data.push_back(seriesToAdd);
        labels.push_back(label);
        numberOfSeries++;
    }

    // Getters
    bool isZNormalized() const { return znormalize; }
    int getMaxLength() const { return maxLength; }
    int getNumberOfSeries() const { return numberOfSeries; }
    const vector<vector<double>>& getData() const { return data; }
    const vector<int>& getLabels() const { return labels; }
    
    // Récupère une série spécifique
    vector<double> getTimeSeries(int index) const {
        if (index >= 0 && index < numberOfSeries) {
            return data[index];
        }
        return vector<double>();
    }
    
    // Récupère le label d'une série
    int getLabel(int index) const {
        if (index >= 0 && index < numberOfSeries) {
            return labels[index];
        }
        return -1;
    }

    // Setters
    void setZNormalize(bool normalize) { znormalize = normalize; }
    
    // Affiche les informations du dataset
    void printInfo() const {
        cout << "TimeSeriesDataset Info:" << endl;
        cout << "  Number of series: " << numberOfSeries << endl;
        cout << "  Max length: " << maxLength << endl;
        cout << "  Z-normalization: " << (znormalize ? "enabled" : "disabled") << endl;
    }
    
    // Affiche une série temporelle
    void printTimeSeries(int index) const {
        if (index < 0 || index >= numberOfSeries) {
            cout << "Invalid index" << endl;
            return;
        }
        
        cout << "Series " << index << " (label=" << labels[index] << "): ";
        for (double value : data[index]) {
            cout << value << " ";
        }
        cout << endl;
    }
};

#endif
