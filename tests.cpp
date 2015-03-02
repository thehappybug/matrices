#include "gtest/gtest.h"
#include "Matrix.h"

/**
 * Object Construction tests
 */
TEST(MatrixContructionTests, ByZeroMatrix) {
	Matrix a;
	const char *expectedResult = "[ 000.00, 000.00 ]\n[ 000.00, 000.00 ]\n";
	EXPECT_STREQ(expectedResult, a.display());	
}

TEST(MatrixContructionTests, ByValue) {
	Matrix a(12.0, 45.0, 66.0, 10.0);
	const char *expectedResult = "[ 012.00, 045.00 ]\n[ 066.00, 010.00 ]\n";
	EXPECT_STREQ(expectedResult, a.display());	
}

TEST(MatrixContructionTests, ByArray) {
	float b[2][2] = {{2.0, 4.0}, {7.0, 10.0}};
	Matrix a(b);
	const char *expectedResult = "[ 002.00, 004.00 ]\n[ 007.00, 010.00 ]\n";
	EXPECT_STREQ(expectedResult, a.display());	
}


/**
 * Test matrix operations (PREP)
 */
class MatrixTests : public ::testing::Test {

protected:
	Matrix m1;
	Matrix m2;
	Matrix m3;

	virtual void SetUp() {
		m1 = Matrix (1, 2, 3, 4);
		m2 = Matrix (1, 2, 3, 4);
		m3 = Matrix (1, 1, 1, 1);
	}

};


/**
 * Test matrix operations (Unit tests)
 */
TEST_F(MatrixTests, AdditionTest) {
	Matrix m = m1 + m2;
	const char *expectedResult = "[ 002.00, 004.00 ]\n[ 006.00, 008.00 ]\n";
	EXPECT_STREQ(expectedResult, m.display());
}

TEST_F(MatrixTests, MultiplicationTest) {
	Matrix m = m2 * m3;
	const char *expectedResult = "[ 003.00, 003.00 ]\n[ 007.00, 007.00 ]\n";
	EXPECT_STREQ(expectedResult, m.display());
}

TEST_F(MatrixTests, AddAndMultiplyTest) {
	Matrix m = m2 * m3 + m1;
	const char *expectedResult = "[ 004.00, 005.00 ]\n[ 010.00, 011.00 ]\n";
	EXPECT_STREQ(expectedResult, m.display());
}