#include <gtest/gtest.h>

#include "../src/matrix.hpp"

// Test 1: Check if the Matrix initializes with correct dimensions
TEST(MatrixTest, ConstructorSetsDimensions) {
    int rows = 3;
    int cols = 3;
    Matrix<double> m(rows, cols);

    // Assuming you have getter methods in your Matrix class
    // If not, you'll need to add them to matrix.hpp
    EXPECT_EQ(m.getRows(), 3);
    EXPECT_EQ(m.getCols(), 3);
}

// Test 2: Check if the Matrix is initialized with zeros
TEST(MatrixTest, InitializedToZero) {
    Matrix<double> m(2, 2);
    for(int i = 0 ; i < 2 ; i++) {
	for(int j = 0 ; j < 2 ; j++) {
		EXPECT_DOUBLE_EQ(m.getValue(i, j), 0.0);
	}
    }
}

TEST(MatrixTest, MatrixAdditionLogic) {
    Matrix<double> m1(2, 2);
    Matrix<double> m2(2, 2);

    // Set some values
    m1.setValue(0, 0, 1.8);
    m1.setValue(0, 1, 2.8);
    m1.setValue(1, 0, 3.8);
    m1.setValue(1, 1, 4.8);

    m2.setValue(0, 0, 5.1);
    m2.setValue(0, 1, 6.1);
    m2.setValue(1, 0, 7.1);
    m2.setValue(1, 1, 8.1);

    // Perform addition
    Matrix<double> result = m1 + m2;

    // Verify the results
    EXPECT_DOUBLE_EQ(result.getValue(0, 0), 6.9);
    EXPECT_DOUBLE_EQ(result.getValue(0, 1), 8.9);
    EXPECT_DOUBLE_EQ(result.getValue(1, 0), 10.9);
    EXPECT_DOUBLE_EQ(result.getValue(1, 1), 12.9);
}

TEST(MatrixTest, MatrixSubtractionLogic) {
	Matrix<double> m1(2, 2);
	Matrix<double> m2(2, 2);

	// Set some values
	m1.setValue(0, 0, 1.5);
	m1.setValue(0, 1, 2.5);
	m1.setValue(1, 0, 3.5);
	m1.setValue(1, 1, 4.5);

	m2.setValue(0, 0, 5.4);
	m2.setValue(0, 1, 6.4);
	m2.setValue(1, 0, 7.4);
	m2.setValue(1, 1, 8.4);

	// Perform subtraction
	Matrix<double> result = m1 - m2;

	// Verify the results
	EXPECT_DOUBLE_EQ(result.getValue(0, 0), -3.9);
	EXPECT_DOUBLE_EQ(result.getValue(0, 1), -3.9);
	EXPECT_DOUBLE_EQ(result.getValue(1, 0), -3.9);
	EXPECT_DOUBLE_EQ(result.getValue(1, 1), -3.9);
}

TEST(MatrixTest, MatrixScalarMultiplication) {
	Matrix<double> m(2, 2);

	m.setValue(0, 0, 1.1);
	m.setValue(0, 1, 2.2);
	m.setValue(1, 0, 3.3);
	m.setValue(1, 1, 4.4);

	int k = 2;
	m.scalarMultiplication(k);

	EXPECT_DOUBLE_EQ(m.getValue(0, 0), 2.2);
	EXPECT_DOUBLE_EQ(m.getValue(0, 1), 4.4);
	EXPECT_DOUBLE_EQ(m.getValue(1, 0), 6.6);
	EXPECT_DOUBLE_EQ(m.getValue(1, 1), 8.8);
}

TEST(MatrixTest, ComplicatedMatrixMultiplication) {
	Matrix<double> m1(2, 3);
	Matrix<double> m2(3, 1);

	m1.setValue(0, 0, 7.6);
        m1.setValue(0, 1, 9.6);
	m1.setValue(0, 2, 6.8);
        m1.setValue(1, 0, 6.9);
        m1.setValue(1, 1, 9.11);
	m1.setValue(1, 2, 6.7);

        m2.setValue(0, 0, 1.2);
        m2.setValue(1, 0, 2.3);
        m2.setValue(2, 0, 3.4);

	Matrix<double> res = m1 * m2;

    	EXPECT_EQ(res.getRows(), 2);
   	EXPECT_EQ(res.getCols(), 1);

    	EXPECT_DOUBLE_EQ(res.getValue(0, 0), 54.32);
    	EXPECT_DOUBLE_EQ(res.getValue(1, 0), 52.013);
}

