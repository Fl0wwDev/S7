#include "headers/knn.h"
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

// Constructeur
KNN::KNN(int k, const string& measure) 
    : k(k), similarity_measure(measure) {}

int KNN::predict(const TimeSeriesDataset& trainData, const vector<double>& testSeries) const {
    const vector<vector<double>>& data = trainData.getData();
    const vector<int>& labels = trainData.getLabels();
    int n = trainData.getNumberOfSamples();
    
    if (n == 0) return -1;
    
    vector<pair<double, int>> distances;
    
    for (int i = 0; i < n; i++) {
        double dist;
        if (similarity_measure == "dtw") {
            dist = TimeSeriesDataset::dtw_distance(testSeries, data[i]);
        } else {
            dist = TimeSeriesDataset::euclidean_distance(testSeries, data[i]);
        }
        distances.push_back({dist, labels[i]});
    }
    
    // Trier par distance croissante
    sort(distances.begin(), distances.end(), 
         [](const pair<double, int>& a, const pair<double, int>& b) {
             return a.first < b.first;
         });
    
    int kEffective = min(k, n);
    
    if (kEffective == 1) {
        return distances[0].second;
    }
    
    // Cas k > 1 : vote majoritaire
    map<int, int> votes;
    for (int i = 0; i < kEffective; i++) {
        votes[distances[i].second]++;
    }
    
    // Trouver la classe avec le plus de votes
    int bestLabel = -1;
    int maxVotes = 0;
    for (const auto& vote : votes) {
        if (vote.second > maxVotes) {
            maxVotes = vote.second;
            bestLabel = vote.first;
        }
    }
    
    return bestLabel;
}

// Évalue le modèle et retourne l'accuracy
double KNN::evaluate(const TimeSeriesDataset& trainData, 
                     const TimeSeriesDataset& testData, 
                     const vector<int>& ground_truth) const {
    const vector<vector<double>>& testSeries = testData.getData();
    int nTest = testData.getNumberOfSamples();
    
    if (nTest == 0 || ground_truth.size() != static_cast<size_t>(nTest)) {
        return 0.0;
    }
    
    int correct = 0;
    for (int i = 0; i < nTest; i++) {
        int predicted = predict(trainData, testSeries[i]);
        if (predicted == ground_truth[i]) {
            correct++;
        }
    }
    
    // accuracy = (1/len(ytest)) * sum(ypred[i] == ytest[i])
    return static_cast<double>(correct) / nTest;
}

// Getters
int KNN::getK() const { 
    return k; 
}

string KNN::getSimilarityMeasure() const { 
    return similarity_measure; 
}

// Setters
void KNN::setK(int newK) { 
    k = newK; 
}

void KNN::setSimilarityMeasure(const string& measure) { 
    similarity_measure = measure; 
}
