#include <iostream>
#include <vector>
#include <map>
#include "countFrequencyBruteForce.h"
#include "countFrequencyOptimal.h"


using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> numbers = {1, 2, 3 , 2, 4, 1, 5, 5, 6};

    //Test countFrequencyBruteForce
    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);


    //Test countFrequencyOptimal
    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry: frequencyMapOptimal) {
        cout << entry.first << ":" << entry.second << "times" << endl;
    }
    return 0;
}
