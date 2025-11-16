#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "matrixBase.h"
#include <cmath>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical();
    MatrixNumerical(std::size_t r, std::size_t c);
    MatrixNumerical(std::size_t r, std::size_t c, const T& initValue);

    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;
    
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;
    
    static MatrixNumerical<T> getIdentity(int size);

private:
    T calculateDeterminant(const MatrixBase<T>& matrix, std::size_t n) const;
};

#include "matrixNumerical.tpp"

#endif
