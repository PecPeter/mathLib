#include "mathMatrixTest.hpp"

void mathMatrixTest (void) {
	std::string errorString;
	if (matrixInitTest1(errorString) == false)
		std::cerr << "\tFailed matrixInitTest1: " << errorString << "\n";
 	if (matrixInitTest2(errorString) == false)
		std::cerr << "\tFailed matrixInitTest2: " << errorString << "\n";
 	if (matrixInitTest3(errorString) == false)
		std::cerr << "\tFailed matrixInitTest3: " << errorString << "\n";
 	if (matrixCopyTest(errorString) == false)
		std::cerr << "\tFailed matrixCopyTest: " << errorString << "\n";
 	if (setTest(errorString) == false)
		std::cerr << "\tFailed setTest: " << errorString << "\n";
 	if (getTest(errorString) == false)
		std::cerr << "\tFailed getTest: " << errorString << "\n";
 	if (resizeTest(errorString) == false)
		std::cerr << "\tFailed resizeTest: " << errorString << "\n";
 	if (getSizeTest(errorString) == false)
		std::cerr << "\tFailed getSizeTest: " << errorString << "\n";
 	if (getRowSizeTest(errorString) == false)
		std::cerr << "\tFailed getRowSizeTest: " << errorString << "\n";
 	if (getColSizeTest(errorString) == false)
		std::cerr << "\tFailed getColSizeTest: " << errorString << "\n";
 	if (opEqualityTest(errorString) == false)
		std::cerr << "\tFailed opEqualityTest: " << errorString << "\n";
 	if (opInequalityTest(errorString) == false)
		std::cerr << "\tFailed opInequalityTest: " << errorString << "\n";
 	if (opMultiplyTest1(errorString) == false)
		std::cerr << "\tFailed opMultiplyTest1: " << errorString << "\n";
 	if (opMultiplyTest2(errorString) == false)
		std::cerr << "\tFailed :opMultiplyTest2" << errorString << "\n";
 	if (opMultiplyTest3(errorString) == false)
		std::cerr << "\tFailed opMultiplyTest3: " << errorString << "\n";
 	if (opMultiplyEqualsTest1(errorString) == false)
		std::cerr << "\tFailed opMultiplyEqualsTest1: " << errorString << "\n";
 	if (opMultiplyEqualsTest2(errorString) == false)
		std::cerr << "\tFailed opMultiplyEqualsTest1: " << errorString << "\n";
 	if (opAddTest1(errorString) == false)
		std::cerr << "\tFailed opAddTest1: " << errorString << "\n";
 	if (opAddTest2(errorString) == false)
		std::cerr << "\tFailed opAddTest2: " << errorString << "\n";
 	if (opAddTest3(errorString) == false)
		std::cerr << "\tFailed opAddTest3: " << errorString << "\n";
 	if (opAddEqualsTest1(errorString) == false)
		std::cerr << "\tFailed opAddEqualsTest1: " << errorString << "\n";
 	if (opAddEqualsTest2(errorString) == false)
		std::cerr << "\tFailed opAddEqualsTest2: " << errorString << "\n";
 	if (opSubtractTest1(errorString) == false)
		std::cerr << "\tFailed opSubtractTest1: " << errorString << "\n";
 	if (opSubtractTest2(errorString) == false)
		std::cerr << "\tFailed opSubtractTest2: " << errorString << "\n";
 	if (opSubtractTest3(errorString) == false)
		std::cerr << "\tFailed opSubtractTest3: " << errorString << "\n";
 	if (opSubtractEqualsTest1(errorString) == false)
		std::cerr << "\tFailed opSubtractEqualsTest1: " << errorString << "\n";
 	if (opSubtractEqualsTest2(errorString) == false)
		std::cerr << "\tFailed opSubtractEqualsTest2: " << errorString << "\n";
 	if (opOutputTest(errorString) == false)
		std::cerr << "\tFailed opOutputTest: " << errorString << "\n";
 	if (mTransposeTest(errorString) == false)
		std::cerr << "\tFailed mTransposeTest: " << errorString << "\n";
 	if (mCoeffMultTest(errorString) == false)
		std::cerr << "\tFailed mCoeffMultTest: " << errorString << "\n";
}

bool matrixInitTest1 (std::string& errorString) {
	cMatrix m1;
	return true;
}

bool matrixInitTest2 (std::string& errorString) {
	cMatrix m1, m2(m1);
	return true;
}

bool matrixInitTest3 (std::string& errorString) {
	bool caughtExcept = false;
	try {
		cMatrix m1(-1,2);
	}
	catch (std::invalid_argument& exception) {
		caughtExcept = true;
	}
	if (caughtExcept == false)
		return false;
	cMatrix m2(1.0,4);
	return true;
}

bool matrixCopyTest(std::string& errorString) {
	errorString = "Have to write a function for this still.";
	return false;
}

bool setTest (std::string& errorString) {
	cMatrix m1, m2, m3, m4, m5;
	return true;
}

bool getTest (std::string& errorString) {
	return true;
}

bool resizeTest (std::string& errorString) {
	return true;
}

bool getSizeTest (std::string& errorString) {
	return true;
}

bool getRowSizeTest (std::string& errorString) {
	return true;
}

bool getColSizeTest (std::string& errorString) {
	return true;
}

bool opEqualityTest (std::string& errorString) {
	return true;
}

bool opInequalityTest (std::string& errorString) {
	return true;
}

bool opMultiplyTest1 (std::string& errorString) {
	return true;
}

bool opMultiplyTest2 (std::string& errorString) {
	return true;
}

bool opMultiplyTest3 (std::string& errorString) {
	return true;
}

bool opMultiplyEqualsTest1 (std::string& errorString) {
	return true;
}

bool opMultiplyEqualsTest2 (std::string& errorString) {
	return true;
}

bool opAddTest1 (std::string& errorString) {
	return true;
}

bool opAddTest2 (std::string& errorString) {
	return true;
}

bool opAddTest3 (std::string& errorString) {
	return true;
}

bool opAddEqualsTest1 (std::string& errorString) {
	return true;
}

bool opAddEqualsTest2 (std::string& errorString) {
	return true;
}

bool opSubtractTest1 (std::string& errorString) {
	return true;
}

bool opSubtractTest2 (std::string& errorString) {
	return true;
}

bool opSubtractTest3 (std::string& errorString) {
	return true;
}

bool opSubtractEqualsTest1 (std::string& errorString) {
	return true;
}

bool opSubtractEqualsTest2 (std::string& errorString) {
	return true;
}

bool opOutputTest (std::string& errorString) {
	return true;
}

bool mTransposeTest (std::string& errorString) {
	return true;
}

bool mCoeffMultTest (std::string& errorString) {
	return true;
}

