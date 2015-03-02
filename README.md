```
  __  __       _        _               
 |  \/  |     | |      (_)              
 | \  / | __ _| |_ _ __ _  ___ ___  ___ 
 | |\/| |/ _` | __| '__| |/ __/ _ \/ __|
 | |  | | (_| | |_| |  | | (_|  __/\__ \
 |_|  |_|\__,_|\__|_|  |_|\___\___||___/
                                        
```

*Authored by*: Mehdi Raza  
*Version*: 1  
*Timestamp*: 1425319847

## Introduction

Matrices program was written for Lab 2 of Advanced Programming.

It demonstrate the use of classes in the Matrix class. The interface for
the Matrix class is given below:

```c++
class Matrix {

public:
	Matrix(); 

	Matrix(float m[2][2]); 

	Matrix(float x0, float x1, float y0, float y1);

	~Matrix(); 

	const char *display(); 

	Matrix operator +(Matrix m2);

	Matrix operator * (Matrix b);
};
```

## Compiling the program

To compile the program alongwith the unit tests, use `make`:

```
$ make
g++ Matrix.cpp main.cpp -o matrix_main                                                                         
g++ -isystem ../gtest-1.7.0/include -g -Wall -Wextra -pthread -c .//Matrix.cpp                                 
g++ -isystem ../gtest-1.7.0/include -g -Wall -Wextra -pthread -c .//tests.cpp                                  
g++ -isystem ../gtest-1.7.0/include -I../gtest-1.7.0 -g -Wall -Wextra -pthread -c \                            
            ../gtest-1.7.0/src/gtest-all.cc                                                                    
g++ -isystem ../gtest-1.7.0/include -I../gtest-1.7.0 -g -Wall -Wextra -pthread -c \                            
            ../gtest-1.7.0/src/gtest_main.cc                                                                   
ar rv gtest_main.a gtest-all.o gtest_main.o                                                                    
ar: creating gtest_main.a                                                                                      
a - gtest-all.o                                                                                                
a - gtest_main.o                                                                                               
g++ -isystem ../gtest-1.7.0/include -g -Wall -Wextra -pthread -lpthread Matrix.o tests.o gtest_main.a -o matrix _unittest
```

You can safely ignore any warnings produced by the compiler. Those are caused by `Gtest`.

## Running the program

Run the executable `matrix_main`. You should see the following output: 

```
$ matrix_main.exe
Matrix m1:
[ 001.00, 002.00 ]
[ 003.00, 004.00 ]
Matrix m2:
[ 001.00, 002.00 ]
[ 003.00, 004.00 ]
Matrix m3:
[ 001.00, 001.00 ]
[ 001.00, 001.00 ]
Matrix m4 = m1 + m2:
[ 002.00, 004.00 ]
[ 006.00, 008.00 ]
Matrix m5 = m2 * m3:
[ 003.00, 003.00 ]
[ 007.00, 007.00 ]
Matrix m6 = m2 * m3 + m1:
[ 004.00, 005.00 ]
[ 010.00, 011.00 ]
```

You can run the test using `matrix_unittest` file:

```
$ matrix_unittest.exe
Running main() from gtest_main.cc
[==========] Running 6 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from MatrixContructionTests
[ RUN      ] MatrixContructionTests.ByZeroMatrix
[       OK ] MatrixContructionTests.ByZeroMatrix (0 ms)
[ RUN      ] MatrixContructionTests.ByValue
[       OK ] MatrixContructionTests.ByValue (0 ms)
[ RUN      ] MatrixContructionTests.ByArray
[       OK ] MatrixContructionTests.ByArray (0 ms)
[----------] 3 tests from MatrixContructionTests (77 ms total)

[----------] 3 tests from MatrixTests
[ RUN      ] MatrixTests.AdditionTest
[       OK ] MatrixTests.AdditionTest (0 ms)
[ RUN      ] MatrixTests.MultiplicationTest
[       OK ] MatrixTests.MultiplicationTest (0 ms)
[ RUN      ] MatrixTests.AddAndMultiplyTest
[       OK ] MatrixTests.AddAndMultiplyTest (0 ms)
[----------] 3 tests from MatrixTests (70 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 2 test cases ran. (227 ms total)
[  PASSED  ] 6 tests.
```