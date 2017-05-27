#ifndef MATHMATRIXTEST_HPP
#define MATHMATRIXTEST_HPP

#include <iostream>
#include <string>

#include "./mathLib/mathMatrix.hpp"

void mathMatrixTest (void);

bool matrixInitTest1 (std::string& errorString);
bool matrixInitTest2 (std::string& errorString);
bool matrixInitTest3 (std::string& errorString);
bool matrixCopyTest(std::string& errorString);
//bool matrixDestructorTest(std::string& errorString);
bool setTest (std::string& errorString);
bool getTest (std::string& errorString);
bool resizeTest (std::string& errorString);
bool getSizeTest (std::string& errorString);
bool getRowSizeTest (std::string& errorString);
bool getColSizeTest (std::string& errorString);
bool opEqualityTest (std::string& errorString);
bool opInequalityTest (std::string& errorString);
bool opMultiplyTest1 (std::string& errorString);
bool opMultiplyTest2 (std::string& errorString);
bool opMultiplyTest3 (std::string& errorString);
bool opMultiplyEqualsTest1 (std::string& errorString);
bool opMultiplyEqualsTest2 (std::string& errorString);
bool opAddTest1 (std::string& errorString);
bool opAddTest2 (std::string& errorString);
bool opAddTest3 (std::string& errorString);
bool opAddEqualsTest1 (std::string& errorString);
bool opAddEqualsTest2 (std::string& errorString);
bool opSubtractTest1 (std::string& errorString);
bool opSubtractTest2 (std::string& errorString);
bool opSubtractTest3 (std::string& errorString);
bool opSubtractEqualsTest1 (std::string& errorString);
bool opSubtractEqualsTest2 (std::string& errorString);
bool opOutputTest (std::string& errorString);
bool mTransposeTest (std::string& errorString);
bool mCoeffMultTest (std::string& errorString);

#endif
