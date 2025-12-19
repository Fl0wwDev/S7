#include "headers/timeSeriesGenerator.h"
#include <iostream>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {
}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed) : seed(_seed) {
}

void TimeSeriesGenerator::printTimeSerie(const vector<double>& series) {
    cout << "[ ";
    for (size_t i = 0; i < series.size(); i++) {
        cout << series[i];
        if (i < series.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int TimeSeriesGenerator::getSeed() const {
    return seed;
}
