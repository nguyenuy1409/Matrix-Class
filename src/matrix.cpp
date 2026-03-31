#include "matrix.hpp"

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    matrixData.resize(rows, std::vector<int>(cols, 0));
}
int Matrix::getValue(int r, int c) const { return matrixData[r][c]; }
void Matrix::setValue(int r, int c, int value) { matrixData[r][c] = value; }
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    if ((this->rows != other.rows) || (this->cols != other.cols)) {
        std::cout << "Error!" << std::endl;
        return Matrix(0, 0);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrixData[i][j] = this->matrixData[i][j] + other.matrixData[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols);
    if ((this->rows != other.rows) || (this->cols != other.cols)) {
	    std::cout << "Error!" << std::endl;
	    return Matrix(0, 0);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrixData[i][j] = this->matrixData[i][j] - other.matrixData[i][j];
        }
    }
    return result;
}

void Matrix::scalarMultiplication(int k) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixData[i][j] *= k;
        }
    }
}
