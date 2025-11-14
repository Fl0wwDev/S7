#include "linearSearch.h"
#include <string>

LinearSearch::LinearSearch() : SearchingAlgorithm() {
    numberComparisons = 0;
}

int LinearSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    
    for (int i = 0; i < elements.size(); i++) {
        numberComparisons++;
        if (elements[i] == target) {
            return i;
        }

    }
    
    return -1;
}