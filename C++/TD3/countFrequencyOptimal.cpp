#include <map>
#include <vector>
#include "countFrequencyOptimal.h"
using namespace std;

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    
    for (int num : numbers) {
        frequencyMap[num]++;
    }
    
    return frequencyMap;
}