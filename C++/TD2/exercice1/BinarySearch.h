#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "searchingAlgorithm.h"
#include <vector>

class BinarySearch : public SearchingAlgorithm {
    public:
        BinarySearch();
        int search(const std::vector<int>& elements, int target) override;
};

#endif
