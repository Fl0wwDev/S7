#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

#include "timeSeriesGenerator.h"
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double standardDeviation;
    std::mt19937 generator;
    std::uniform_real_distribution<double> uniform;

    double boxMuller();

public:
    GaussianGenerator(double m, double sd);
    GaussianGenerator(int seed, double m, double sd);

    vector<double> generateTimeSeries(int size) override;

    // Getters
    double getMean() const;
    double getStandardDeviation() const;

    // Setters
    void setMean(double m);
    void setStandardDeviation(double sd);
};

#endif
