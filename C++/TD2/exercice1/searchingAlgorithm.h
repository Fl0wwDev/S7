#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <ostream>
#include <vector>

class SearchingAlgorithm{
    public:
        static int totalComparisons;
        static int totalSearch;
        static int averageComparisons;
        int numberComparisons;
        SearchingAlgorithm() {};
        virtual int search(const std::vector<int>&, int target) = 0;
        void displaySearchResults(std::ostream &os, int results, int target);
};

#endif