#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <vector>
#include <iostream>

using namespace std;

class TimeSeriesGenerator {
private:
    int seed;

public:
    TimeSeriesGenerator();

    TimeSeriesGenerator(int _seed);

    virtual vector<double> generateTimeSeries(int) = 0;

    static void printTimeSerie(const vector<double>&);
};

#endif