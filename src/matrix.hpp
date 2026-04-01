#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Matrix {
   private:
    int rows, cols;
    std::vector<std::vector<T>> matrixData;

   public:
    Matrix(int r, int c);
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    T getValue(int r, int c) const;
    void setValue(int r, int c, T value);
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    void scalarMultiplication(T k);
};

#include "matrix.ipp"
