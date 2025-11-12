#include <ostream>
#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

class SearchingAlgorithm{
    private:

    public:
        static int totalComparisons;
        static int totalSearch;
        static int averageComparisons;
        int numberComparisons;
        SearchingAlgorithm() {};
        virtual int search(const std::vector<int>&, int target) = 0;
        void displaySearchResults(std::ostream&, int, int);
};

#endif