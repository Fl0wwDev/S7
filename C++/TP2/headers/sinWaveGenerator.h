#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

#include "timeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;      // A
    double frequency;      // w 
    double phaseShift;     // φ 

public:
    SinWaveGenerator(double A = 1.0, double w = 1.0, double phi = 0.0);
    SinWaveGenerator(int seed, double A = 1.0, double w = 1.0, double phi = 0.0);

    vector<double> generateTimeSeries(int size) override;

    // Getters
    double getAmplitude() const;
    double getFrequency() const;
    double getPhaseShift() const;

    // Setters
    void setAmplitude(double A);
    void setFrequency(double w);
    void setPhaseShift(double phi);
};

#endif
