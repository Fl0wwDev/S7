#include "JumpSearch.h"
#include <cmath>

JumpSearch::JumpSearch() : SearchingAlgorithm() {
    numberComparisons = 0;
}

int JumpSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int n = elements.size();
    
    if (n == 0) return -1;
    
    // Taille du saut optimal
    int step = sqrt(n);
    int prev = 0;
    
    // Sauter jusqu'à trouver un bloc où l'élément pourrait être
    while (prev < n && elements[std::min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += sqrt(n);
        
        if (prev >= n) {
            return -1;
        }
    }
    
    // Recherche linéaire dans le bloc
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
