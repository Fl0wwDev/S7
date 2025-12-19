#include "headers/timeSeriesDataset.h"
#include <cmath>
#include <numeric>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

// ==================== Méthodes privées ====================

double TimeSeriesDataset::calculateMean(const vector<double>& series) const {
    if (series.empty()) return 0.0;
    double sum = accumulate(series.begin(), series.end(), 0.0);
    return sum / series.size();
}

double TimeSeriesDataset::calculateStdDev(const vector<double>& series, double mean) const {
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

vector<double> TimeSeriesDataset::zNormalize(const vector<double>& series) const {
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

// ==================== Constructeur ====================

TimeSeriesDataset::TimeSeriesDataset(bool normalize, bool train, int maxLen)
    : znormalize(normalize), isTrain(train), maxLength(maxLen), numberOfSamples(0) {}

// ==================== Méthodes statiques de distance ====================

double TimeSeriesDataset::euclidean_distance(const vector<double>& x, const vector<double>& y) {
    size_t len = min(x.size(), y.size());
    
    double sumSquaredDiff = 0.0;
    for (size_t i = 0; i < len; i++) {
        double diff = x[i] - y[i];
        sumSquaredDiff += diff * diff;
    }
    
    return sqrt(sumSquaredDiff);
}

double TimeSeriesDataset::dtw_distance(const vector<double>& x, const vector<double>& y) {
    size_t L1 = x.size();
    size_t L2 = y.size();
    
    if (L1 == 0 || L2 == 0) return 0.0;
    
    const double INF = numeric_limits<double>::infinity();
    vector<vector<double>> D(L1 + 1, vector<double>(L2 + 1, INF));
    
    D[0][0] = 0.0;
    
    for (size_t i = 1; i <= L1; i++) {
        for (size_t j = 1; j <= L2; j++) {
            double d = (x[i-1] - y[j-1]) * (x[i-1] - y[j-1]);
            double minVal = min({D[i-1][j], D[i][j-1], D[i-1][j-1]});
            D[i][j] = d + minVal;
        }
    }
    
    return sqrt(D[L1][L2]);
}

// ==================== Ajout de données ====================

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    vector<double> seriesToAdd = series;
    
    if (znormalize && !series.empty()) {
        seriesToAdd = zNormalize(series);
    }
    
    if (seriesToAdd.size() > static_cast<size_t>(maxLength)) {
        maxLength = seriesToAdd.size();
    }
    
    data.push_back(seriesToAdd);
    labels.push_back(label);
    numberOfSamples++;
}

// ==================== Getters ====================

bool TimeSeriesDataset::isZNormalized() const { 
    return znormalize; 
}

bool TimeSeriesDataset::getIsTrain() const { 
    return isTrain; 
}

int TimeSeriesDataset::getMaxLength() const { 
    return maxLength; 
}

int TimeSeriesDataset::getNumberOfSamples() const { 
    return numberOfSamples; 
}

const vector<vector<double>>& TimeSeriesDataset::getData() const { 
    return data; 
}

const vector<int>& TimeSeriesDataset::getLabels() const { 
    return labels; 
}

vector<double> TimeSeriesDataset::getTimeSeries(int index) const {
    if (index >= 0 && index < numberOfSamples) {
        return data[index];
    }
    return vector<double>();
}

int TimeSeriesDataset::getLabel(int index) const {
    if (index >= 0 && index < numberOfSamples) {
        return labels[index];
    }
    return -1;
}

// ==================== Setters ====================

void TimeSeriesDataset::setZNormalize(bool normalize) { 
    znormalize = normalize; 
}

void TimeSeriesDataset::setIsTrain(bool train) { 
    isTrain = train; 
}

// ==================== Affichage ====================

void TimeSeriesDataset::printInfo() const {
    cout << "TimeSeriesDataset Info:" << endl;
    cout << "  Number of samples: " << numberOfSamples << endl;
    cout << "  Max length: " << maxLength << endl;
    cout << "  Is training set: " << (isTrain ? "yes" : "no") << endl;
    cout << "  Z-normalization: " << (znormalize ? "enabled" : "disabled") << endl;
}

void TimeSeriesDataset::printTimeSeries(int index) const {
    if (index < 0 || index >= numberOfSamples) {
        cout << "Invalid index" << endl;
        return;
    }
    
    cout << "Series " << index << " (label=" << labels[index] << "): ";
    for (double value : data[index]) {
        cout << value << " ";
    }
    cout << endl;
}
