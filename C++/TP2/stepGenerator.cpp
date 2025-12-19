#include "headers/stepGenerator.h"

StepGenerator::StepGenerator(int seed)
    : TimeSeriesGenerator(seed),
      probDist(0.0, 1.0),
      valueDist(0, 100) {
    generator.seed(seed);
}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series;
    
    if (size <= 0) {
        return series;
    }
    
    double currentValue = 0.0;
    series.push_back(currentValue);
    
    for (int i = 1; i < size; ++i) {
        if (probDist(generator) < 0.5) {
            currentValue = static_cast<double>(valueDist(generator));
        }
        series.push_back(currentValue);
    }
    
    return series;
}

