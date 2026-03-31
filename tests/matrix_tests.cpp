#include <gtest/gtest.h>

#include "../src/matrix.hpp"

// Test 1: Check if the Matrix initializes with correct dimensions
TEST(MatrixTest, ConstructorSetsDimensions) {
    int rows = 3;
    int cols = 3;
    Matrix m(rows, cols);

    // Assuming you have getter methods in your Matrix class
    // If not, you'll need to add them to matrix.hpp
    EXPECT_EQ(m.getRows(), 3);
    EXPECT_EQ(m.getCols(), 3);
}

// Test 2: Check if the Matrix is initialized with zeros
TEST(MatrixTest, InitializedToZero) {
    Matrix m(2, 2);
    // This is a placeholder; you'll check actual values once you
    // implement the logic in matrix.cpp
    EXPECT_TRUE(true);
}

TEST(MatrixTest, MatrixAdditionLogic) {
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    // Set some values
    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(1, 0, 3);
    m1.setValue(1, 1, 4);

    m2.setValue(0, 0, 5);
    m2.setValue(0, 1, 6);
    m2.setValue(1, 0, 7);
    m2.setValue(1, 1, 8);

    // Perform addition
    Matrix result = m1 + m2;

    // Verify the results (1+5=6, 2+6=8, etc.)
    EXPECT_EQ(result.getValue(0, 0), 6);
    EXPECT_EQ(result.getValue(0, 1), 8);
    EXPECT_EQ(result.getValue(1, 0), 10);
    EXPECT_EQ(result.getValue(1, 1), 12);
}

TEST(MatrixTest, MatrixSubtractionLogic) {
	Matrix m1(4, 4);
	Matrix m2(4, 4);

	// Set some values
	m1.setValue(0, 0, 1);
	m1.setValue(0, 1, 2);
	m1.setValue(1, 0, 3);
	m1.setValue(1, 1, 4);

	m2.setValue(0, 0, 5);
	m2.setValue(0, 1, 6);
	m2.setValue(1, 0, 7);
	m2.setValue(1, 1, 8);

	// Perform subtraction
	Matrix result = m1 - m2;

	// Verify the results
	EXPECT_EQ(result.getValue(0, 0), -4);
	EXPECT_EQ(result.getValue(0, 1), -4);
	EXPECT_EQ(result.getValue(1, 0), -4);
	EXPECT_EQ(result.getValue(1, 1), -4);
}

TEST(MatrixTest, MatrixScalarMultiplication) {
	Matrix m(2, 2);

	m.setValue(0, 0, 1);
	m.setValue(0, 1, 2);
	m.setValue(1, 0, 3);
	m.setValue(1, 1, 4);

	int k = 2;
	m.scalarMultiplication(k);

	EXPECT_EQ(m.getValue(0, 0), 2);
	EXPECT_EQ(m.getValue(0, 1), 4);
	EXPECT_EQ(m.getValue(1, 0), 6);
	EXPECT_EQ(m.getValue(1, 1), 8);
}

