#include "headers/knnDouble.h"

KNNDouble::KNNDouble() : KNN<NetworkDevice*>() {}

KNNDouble::KNNDouble(int k) : KNN<NetworkDevice*>(k) {}

double KNNDouble::similarityMeasure(NetworkDevice*& a, NetworkDevice*& b) {
    double powerDiff = a->getPowerConsumption() - b->getPowerConsumption();
    double yearDiff = a->getYear() - b->getYear();
    
    return sqrt(powerDiff * powerDiff + yearDiff * yearDiff);
}
