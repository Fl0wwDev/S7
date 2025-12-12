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
    StepGenerator(int seed = 0) 
        : TimeSeriesGenerator(seed), probDist(0.0, 1.0), valueDist(0, 100) {
        generator.seed(seed);
    }

    vector<double> generateTimeSeries(int size) override {
        vector<double> series;
        if (size <= 0) return series;
        
        double current = 0.0;
        series.push_back(current);
        
        for (int i = 1; i < size; ++i) {
            if (probDist(generator) < 0.5) {
                current = static_cast<double>(valueDist(generator));
            }
            series.push_back(current);
        }
        
        return series;
    }
};

#endif