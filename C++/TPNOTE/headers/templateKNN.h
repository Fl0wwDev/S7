#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "networkDevice.h"
#include "router.h"
#include "server.h"
#include "switch.h"
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

#endif