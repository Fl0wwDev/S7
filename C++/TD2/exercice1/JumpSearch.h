#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "searchingAlgorithm.h"
#include <vector>

class JumpSearch : public SearchingAlgorithm {
    public:
        JumpSearch();
        int search(const std::vector<int>& elements, int target) override;
};

#endif
