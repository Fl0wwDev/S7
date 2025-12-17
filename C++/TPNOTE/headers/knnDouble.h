#ifndef KNNDOUBLE_H
#define KNNDOUBLE_H

#include "templateKNN.h"

class KNNDouble : public KNN<NetworkDevice*> {
public:
    KNNDouble();
    KNNDouble(int k);
    
    double similarityMeasure(NetworkDevice*& a, NetworkDevice*& b) override;
};
#endif