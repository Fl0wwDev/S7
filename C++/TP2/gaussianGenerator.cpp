#include "headers/gaussianGenerator.h"
#include <cmath>

double GaussianGenerator::boxMuller() {
    double u1 = uniform(generator);
    double u2 = uniform(generator);
    while (u1 <= 0.0) {
        u1 = uniform(generator);
    }
    
    double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
    return mean + standardDeviation * z0;
}

GaussianGenerator::GaussianGenerator(double m, double sd) 
    : TimeSeriesGenerator(), mean(m), standardDeviation(sd), uniform(0.0, 1.0) {
    generator.seed(0);
}

GaussianGenerator::GaussianGenerator(int seed, double m, double sd) 
    : TimeSeriesGenerator(seed), mean(m), standardDeviation(sd), uniform(0.0, 1.0) {
    generator.seed(seed);
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> series;
    if (size <= 0) return series;
    
    for (int i = 0; i < size; ++i) {
        series.push_back(boxMuller());
    }
    
    return series;
}

double GaussianGenerator::getMean() const { 
    return mean; 
}

double GaussianGenerator::getStandardDeviation() const { 
    return standardDeviation; 
}

void GaussianGenerator::setMean(double m) { 
    mean = m; 
}

void GaussianGenerator::setStandardDeviation(double sd) { 
    standardDeviation = sd; 
}
