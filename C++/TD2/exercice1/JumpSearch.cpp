#include "JumpSearch.h"
#include <cmath>

JumpSearch::JumpSearch() : SearchingAlgorithm() {
    numberComparisons = 0;
}

int JumpSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int n = elements.size();
    
    if (n == 0) return -1;
    
    int step = sqrt(n);
    int prev = 0;
    
    while (prev < n && elements[std::min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += sqrt(n);
        
        if (prev >= n) {
            return -1;
        }
    }
    
    for (int i = prev; i < std::min(step, n); i++) {
        numberComparisons++;
        if (elements[i] == target) {
            return i;
        }
        if (elements[i] > target) {
            return -1;
        }
    }
    
    return -1;
}
