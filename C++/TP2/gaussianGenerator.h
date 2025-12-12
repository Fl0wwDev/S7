#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

#include "timeSeriesGenerator.h"
#include <cmath>
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double standardDeviation;
    std::mt19937 generator;
    std::uniform_real_distribution<double> uniform;

    double boxMuller() {
        double u1 = uniform(generator);
        double u2 = uniform(generator);
        while (u1 <= 0.0) {
            u1 = uniform(generator);
        }
        
        double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
        return mean + standardDeviation * z0;
    }

public:
    GaussianGenerator(double m, double sd) 
        : mean(m), standardDeviation(sd), uniform(0.0, 1.0) {}

    double generate() {
        return boxMuller();
    }

    void setMean(double m) { mean = m; }
    void setStandardDeviation(double sd) { standardDeviation = sd; }
    double getMean() const { return mean; }
    double getStandardDeviation() const { return standardDeviation; }
};

#endif