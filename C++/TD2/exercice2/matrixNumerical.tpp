#ifndef MATRIXNUMERICAL_TPP
#define MATRIXNUMERICAL_TPP

#include "matrixNumerical.h"

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::size_t r, std::size_t c) 
    : MatrixBase<T>(r, c) {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::size_t r, std::size_t c, const T& initValue) 
    : MatrixBase<T>(r, c, initValue) {}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        throw std::invalid_argument("Determinant requires a square matrix");
    }
    return calculateDeterminant(*this, this->rows);
}

template <typename T>
T MatrixNumerical<T>::calculateDeterminant(const MatrixBase<T>& matrix, std::size_t n) const {
    if (n == 1) {
        return matrix.getElement(0, 0);
    }
    
    if (n == 2) {
        return matrix.getElement(0, 0) * matrix.getElement(1, 1) - 
               matrix.getElement(0, 1) * matrix.getElement(1, 0);
    }
    
    T det = T(0);
    for (std::size_t p = 0; p < n; ++p) {
        MatrixBase<T> temp = getCofactor(matrix, 0, p);
        MatrixNumerical<T> tempNum(temp.getRows(), temp.getCols());
        for (std::size_t i = 0; i < temp.getRows(); ++i) {
            for (std::size_t j = 0; j < temp.getCols(); ++j) {
                tempNum.addElement(i, j, temp.getElement(i, j));
            }
        }
        
        int sign = (p % 2 == 0) ? 1 : -1;
        det += sign * matrix.getElement(0, p) * calculateDeterminant(tempNum, n - 1);
    }
    
    return det;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    MatrixNumerical<T> result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }
    
    MatrixNumerical<T> result(this->rows, this->cols);
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) const {
    if (this->cols != other.rows) {
        throw std::invalid_argument("Invalid matrix dimensions for multiplication");
    }
    
    MatrixNumerical<T> result(this->rows, other.cols, T(0));
    for (std::size_t i = 0; i < this->rows; ++i) {
        for (std::size_t j = 0; j < other.cols; ++j) {
            T sum = T(0);
            for (std::size_t k = 0; k < this->cols; ++k) {
                sum += this->getElement(i, k) * other.getElement(k, j);
            }
            result.addElement(i, j, sum);
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    if (this->rows != this->cols) {
        throw std::invalid_argument("Inverse requires a square matrix");
    }
    
    T det = getDeterminant();
    if (std::abs(det) < 1e-10) {
        throw std::runtime_error("Matrix is singular, cannot compute inverse");
    }
    
    std::size_t n = this->rows;
    MatrixNumerical<T> adjoint(n, n);
    
    if (n == 1) {
        adjoint.addElement(0, 0, T(1));
        return adjoint;
    }
    
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            MatrixBase<T> temp = getCofactor(*this, i, j);
            MatrixNumerical<T> tempNum(temp.getRows(), temp.getCols());
            for (std::size_t x = 0; x < temp.getRows(); ++x) {
                for (std::size_t y = 0; y < temp.getCols(); ++y) {
                    tempNum.addElement(x, y, temp.getElement(x, y));
                }
            }
            
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            T cofactor = sign * tempNum.getDeterminant();
            adjoint.addElement(j, i, cofactor);  // Transposée
        }
    }
    
    MatrixNumerical<T> inverse(n, n);
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            inverse.addElement(i, j, adjoint.getElement(i, j) / det);
        }
    }
    
    return inverse;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& other) const {
    return (*this) * other.getInverse();
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    
    MatrixNumerical<T> identity(size, size, T(0));
    for (int i = 0; i < size; ++i) {
        identity.addElement(i, i, T(1));
    }
    return identity;
}

#endif
