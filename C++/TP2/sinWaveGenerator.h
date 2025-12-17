#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

#include "timeSeriesGenerator.h"
#include <cmath>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;      // A
    double frequency;      // w 
    double phaseShift;     // φ 

public:
    SinWaveGenerator(double A = 1.0, double w = 1.0, double phi = 0.0)
        : amplitude(A), frequency(w), phaseShift(phi) {}

    SinWaveGenerator(int seed, double A = 1.0, double w = 1.0, double phi = 0.0)
        : TimeSeriesGenerator(seed), amplitude(A), frequency(w), phaseShift(phi) {}

    vector<double> generateTimeSeries(int size) override {
        vector<double> series;
        if (size <= 0) return series;

        for (int x = 0; x < size; ++x) {
            double value = amplitude * sin(frequency * x + phaseShift);
            series.push_back(value);
        }

        return series;
    }

    // Getters
    double getAmplitude() const { return amplitude; }
    double getFrequency() const { return frequency; }
    double getPhaseShift() const { return phaseShift; }

    // Setters
    void setAmplitude(double A) { amplitude = A; }
    void setFrequency(double w) { frequency = w; }
    void setPhaseShift(double phi) { phaseShift = phi; }
};

#endif
