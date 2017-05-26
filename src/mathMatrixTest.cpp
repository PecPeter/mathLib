#include "mathMatrixTest.hpp"

void mathMatrixTest (void) {
	std::string errorString;
	if (matrixInitTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (matrixInitTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (matrixInitTest3(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (matrixCopyTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (matrixDestructorTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (setTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (getTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (resizeTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (getSizeTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (getRowSizeTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (getColSizeTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opEqualityTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opInequalityTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opMultiplyTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opMultiplyTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opMultiplyTest3(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opMultiplyEqualsTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opMultiplyEqualsTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opAddTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opAddTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opAddTest3(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opAddEqualsTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opAddEqualsTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opSubtractTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opSubtractTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opSubtractTest3(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opSubtractEqualsTest1(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opSubtractEqualsTest2(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (opOutputTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (mTransposeTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
 	if (mCoeffMultTest(errorString) == false)
		std::cout << "Failed " << errorString << "\n";
}

bool matrixInitTest1 (std::string& errorString) {
	// Test function for cMatrix(void)
	return true;
}

bool matrixInitTest2 (std::string& errorString) {
	return true;
}

bool matrixInitTest3 (std::string& errorString) {
	return true;
}

bool matrixCopyTest(std::string& errorString) {
	return true;
}

bool matrixDestructorTest(std::string& errorString) {
	return true;
}

bool setTest (std::string& errorString) {
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

