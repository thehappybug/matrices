#include <iostream>
#include "Matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Matrix m1(1, 2, 3, 4);
	Matrix m2(1, 2, 3, 4);
	Matrix m3(1, 1, 1, 1);
	Matrix m4;
	Matrix m5;
	Matrix m6;

	cout << "Matrix m1:" << endl; 
	m1.display();

	cout << "Matrix m2:" << endl; 
	m2.display();

	cout << "Matrix m3:" << endl; 
	m3.display();

	cout << "Matrix m4 = m1 + m2:" << endl; 
	m4 = m1 + m2;
	m4.display();

	cout << "Matrix m5 = m2 * m3:" << endl; 
	m5 = m2 * m3;
	m5.display();

	cout << "Matrix m6 = m2 * m3 + m1:" << endl; 
	m6 = m2 * m3 + m1;
	m6.display();
	return 0;
}