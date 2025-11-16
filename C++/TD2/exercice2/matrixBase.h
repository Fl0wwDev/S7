#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class MatrixBase {
protected:
    std::size_t rows;
    std::size_t cols;
    std::vector<std::vector<T>> data;

public:
    MatrixBase();
    MatrixBase(std::size_t r, std::size_t c);
    MatrixBase(std::size_t r, std::size_t c, const T& initValue);
    
    virtual ~MatrixBase();

    virtual void addElement(std::size_t i, std::size_t j, const T& value);
    virtual T getElement(std::size_t i, std::size_t j) const;
    virtual std::size_t getRows() const;
    virtual std::size_t getCols() const;
    virtual void display() const;
};

template <typename T>
MatrixBase<T> getCofactor(const MatrixBase<T>& matrix, std::size_t p, std::size_t q);

#include "matrixBase.tpp"

#endif