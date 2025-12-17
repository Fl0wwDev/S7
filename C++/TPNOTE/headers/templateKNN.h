#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <vector>
#include <cmath>
#include <algorithm>
#include "networkDevice.h"
using namespace std;

template <typename T>
class KNN{
    protected:
        int k;
    public:
        KNN();
        KNN(int k);

        int getK() const;

        vector<int> findNearestNeighbors(
            vector<T>& trainData,
            T& target
        );

        virtual double similarityMeasure(
            T& a,
            T& b

        ) = 0;
};

template <typename T>
KNN<T>::KNN() : k(3) {}

template <typename T>
KNN<T>::KNN(int k) : k(k) {}

template <typename T>
int KNN<T>::getK() const {
    return k;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbors(vector<T>& trainData, T& target) {
    vector<pair<double, int>> distances;
    
    for (int i = 0; i < trainData.size(); i++) {
        double dist = similarityMeasure(trainData[i], target);
        distances.push_back(make_pair(dist, i));
    }
    
    sort(distances.begin(), distances.end());
    
    //plus proche voisin
    vector<int> nearestIndices;
    for (int i = 0; i < k && i < distances.size(); i++) {
        nearestIndices.push_back(distances[i].second);
    }
    
    return nearestIndices;
}

#endif