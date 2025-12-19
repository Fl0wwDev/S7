#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <vector>

using namespace std;

class TimeSeriesGenerator {
private:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int _seed);

    virtual vector<double> generateTimeSeries(int size) = 0;

    static void printTimeSerie(const vector<double>& series);

    // Getter
    int getSeed() const;
};

#endif
