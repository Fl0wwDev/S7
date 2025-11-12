#include <ostream>
#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

class SearchingAlgorithm{
    private:
        int totalComparisons;
        int numberComparisons;
        int totalSearch;
        int averageComparisons;
    public:
        SearchingAlgorithm() {};
        SearchingAlgorithm(int _totalComparisons, int _numberComparisons, int _totalSearch, int _averageComparisons);
        virtual void search(int) = 0;
        void displaySearchResults(std::ostream&, int, int);
        void LinearSearch();
        void JumpSearch();
        void BiarySearch();
};


#endif