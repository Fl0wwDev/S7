#ifndef MATRIXBASE_H
#define MATRIXBASE_Hvc
#include <iostream>


template <typename T>
class MatrixBase{
    protected:
        std::size_t rows;
        std::size_t cols;
        std::vector<T, T> data;
    public:
        MatrixBase();




};

#endif