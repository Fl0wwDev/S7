#ifndef MATRIXBASE_TPP
#define MATRIXBASE_TPP

#include "matrixBase.h"

// Constructeur par défaut
template <typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(std::size_t r, std::size_t c) : rows(r), cols(c) {
    data.resize(rows, std::vector<T>(cols, T()));
}

template <typename T>
MatrixBase<T>::MatrixBase(std::size_t r, std::size_t c, const T& initValue) 
    : rows(r), cols(c) {
    data.resize(rows, std::vector<T>(cols, initValue));
}

template <typename T>
MatrixBase<T>::~MatrixBase() {}

template <typename T>
void MatrixBase<T>::addElement(std::size_t i, std::size_t j, const T& value) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    data[i][j] = value;
}

template <typename T>
T MatrixBase<T>::getElement(std::size_t i, std::size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[i][j];
}

template <typename T>
std::size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
std::size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::display() const {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
MatrixBase<T> getCofactor(const MatrixBase<T>& matrix, std::size_t p, std::size_t q) {
    std::size_t n = matrix.getRows();
    MatrixBase<T> temp(n - 1, n - 1);
    
    std::size_t i = 0, j = 0;
    for (std::size_t row = 0; row < n; row++) {
        for (std::size_t col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp.addElement(i, j++, matrix.getElement(row, col));
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}

#endif
