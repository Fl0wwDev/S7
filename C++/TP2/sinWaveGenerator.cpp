#include "headers/sinWaveGenerator.h"
#include <cmath>

SinWaveGenerator::SinWaveGenerator(double A, double w, double phi)
    : TimeSeriesGenerator(), amplitude(A), frequency(w), phaseShift(phi) {}

SinWaveGenerator::SinWaveGenerator(int seed, double A, double w, double phi)
    : TimeSeriesGenerator(seed), amplitude(A), frequency(w), phaseShift(phi) {}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> series;
    if (size <= 0) return series;

    for (int x = 0; x < size; ++x) {
        double value = amplitude * sin(frequency * x + phaseShift);
        series.push_back(value);
    }

    return series;
}

double SinWaveGenerator::getAmplitude() const { 
    return amplitude; 
}

double SinWaveGenerator::getFrequency() const { 
    return frequency; 
}

double SinWaveGenerator::getPhaseShift() const { 
    return phaseShift; 
}

void SinWaveGenerator::setAmplitude(double A) { 
    amplitude = A; 
}

void SinWaveGenerator::setFrequency(double w) { 
    frequency = w; 
}

void SinWaveGenerator::setPhaseShift(double phi) { 
    phaseShift = phi; 
}
