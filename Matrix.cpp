#include "Matrix.h"
#include <iomanip>
#include <iostream>
using namespace std;

Matrix::Matrix() 
{ 
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			ms[i][j] = 0;
}

Matrix::Matrix(float m[2][2]) 
{ 
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			ms[i][j] = m[i][j];
}

Matrix::Matrix(float x0, float x1, float y0, float y1) 
{
	ms[0][0] = x0;
	ms[0][1] = x1;
	ms[1][0] = y0;
	ms[1][1] = y1;
}

Matrix::~Matrix() 
{ 
}

void Matrix::display() 
{ 
	cout << "[ " << std::fixed << std::setw( 6 ) << std::setprecision( 2 ) << std::setfill( '0' ) << ms[0][0] << ", ";
	cout << std::fixed << std::setw( 6 ) << std::setprecision( 2 ) << std::setfill( '0' ) << ms[0][1] << " ]" << endl;
	cout << "[ " << std::fixed << std::setw( 6 ) << std::setprecision( 2 ) << std::setfill( '0' ) << ms[1][0] << ", ";
	cout << std::fixed << std::setw( 6 ) << std::setprecision( 2 ) << std::setfill( '0' ) << ms[1][1] << " ]" << endl;
}

Matrix Matrix::operator +(Matrix m2)
{
	Matrix T;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			T.ms[i][j] = ms[i][j] + m2.ms[i][j];
	return T;
}

Matrix Matrix::operator * (Matrix b)
{
	Matrix T;
	T.ms[0][0] = ms[0][0]*b.ms[0][0] + ms[0][1]*b.ms[1][0];
	T.ms[0][1] = ms[0][0]*b.ms[0][1] + ms[0][1]*b.ms[1][1];
	T.ms[1][0] = ms[1][0]*b.ms[0][0] + ms[1][1]*b.ms[1][0];
	T.ms[1][1] = ms[1][0]*b.ms[0][1] + ms[1][1]*b.ms[1][1];
	return T;
}