#pragma once
#include <iostream>
#include <vector>

class Matrix {
   private:
    int rows, cols;
    std::vector<std::vector<int>> matrixData;

   public:
    Matrix(int r, int c);
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getValue(int r, int c) const;
    void setValue(int r, int c, int value);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    void scalarMultiplication(int k);
};
