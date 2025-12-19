#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "timeSeriesGenerator.h"
#include <random>

class StepGenerator : public TimeSeriesGenerator {
private:
    std::mt19937 generator;
    std::uniform_real_distribution<double> probDist;
    std::uniform_int_distribution<int> valueDist;

public:
    StepGenerator(int seed = 0);
    
    vector<double> generateTimeSeries(int size) override;
};

#endif
