#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "searchingAlgorithm.h"
#include <vector>

class LinearSearch : public SearchingAlgorithm {
    public:
        LinearSearch();
        int search(const std::vector<int>& elements, int target) override;
};

#endif