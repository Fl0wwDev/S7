#include <ostream>
#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

class SearchingAlgorithm{
    public:
        SearchingAlgorithm() {};
        void numberComparaisons();
        void totalComparaisons();
        void totalSearch();
        void averageComparisons();
        virtual void search(int);
        void displaySearchResults(std::ostream&, int, int);
        void LinearSearch();
        void JumpSearch();
        void BiarySearch();
};


#endif