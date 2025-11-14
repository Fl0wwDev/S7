#include "BinarySearch.h"

BinarySearch::BinarySearch() : SearchingAlgorithm() {
    numberComparisons = 0;
}

int BinarySearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int left = 0;
    int right = elements.size() - 1;
    
    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;
        
        if (elements[mid] == target) {
            return mid;
        }
        
        if (elements[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
