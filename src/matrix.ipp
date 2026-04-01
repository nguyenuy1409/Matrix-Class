
template <typename T>
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    cols = c;
    matrixData.resize(rows, std::vector<T>(cols, T(0)));
}

template <typename T>
T Matrix<T>::getValue(int r, int c) const { return matrixData[r][c]; }

template <typename T>
void Matrix<T>::setValue(int r, int c, T value) { matrixData[r][c] = value; }

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    Matrix<T> result(rows, cols);
    if ((this->rows != other.rows) || (this->cols != other.cols)) {
        std::cout << "Error!" << std::endl;
        return Matrix<T>(0, 0);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrixData[i][j] = this->matrixData[i][j] + other.matrixData[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    Matrix<T> result(rows, cols);
    if ((this->rows != other.rows) || (this->cols != other.cols)) {
            std::cout << "Error!" << std::endl;
            return Matrix<T>(0, 0);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrixData[i][j] = this->matrixData[i][j] - other.matrixData[i][j];
	}
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
        if(this->cols != other.rows) {
		std::cout << "Error!" << std::endl;
		return Matrix<T> (0, 0);
	}
	Matrix<T> result(this->rows, other.cols);
	for(int i = 0 ; i < this->rows ; i++) {
		for(int j = 0 ; j < other.cols ; j++) {
			T sum = T(0);
			for(int l = 0 ; l < this->cols ; l++) {
				sum+= this->matrixData[i][l] * other.matrixData[l][j];
			}
			result.matrixData[i][j] = sum;
		}
	}
	return result;
}


template <typename T>
void Matrix<T>::scalarMultiplication(T k) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixData[i][j] *= k;
        }
    }
}
