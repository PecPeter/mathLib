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
		std::cerr << "\tFailed opMultiplyTest2: " << errorString << "\n";
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
	cMatrix m1, m2(m1), m3(3,2),m4(m3);
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
	cMatrix m1(2,3), m2;
	m1.set(0,0) = 1;
	m1.set(0,1) = 2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4;
	m1.set(1,1) = 5;
	m1.set(1,2) = 6;

	m2 = m1;

	return true;
}

bool setTest (std::string& errorString) {
	cMatrix m1(1,2);
	bool caughtError = false;
	try {
		m1.set(2,1) = 123;
	}
	catch (std::out_of_range& error) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch out_of_range exception.";
		return false;
	}
	return true;
}

bool getTest (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = 2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4;
	m1.set(1,1) = 5;
	m1.set(1,2) = 6;

	double val = m1.get(1,2);
	if (val != 6) {
		errorString = "Expected 6, recieved: " + std::to_string(val);
		return false;
	}
	
	bool caughtError = false;
	try {
		val = m1.get(3,3);
	}
	catch (std::out_of_range& error) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch out_of_range exception.";
		return false;
	}
	return true;
}

bool resizeTest (std::string& errorString) {
	cMatrix m1;
	m1.resize(3,5);
	int nRow, nCol;
	m1.getSize(&nRow,&nCol);
	if (nRow != 3 && nCol != 5) {
		errorString = "Resized matrix incorrectly: nRows = " + 
			std::to_string(nRow) + ", nCol = " + std::to_string(nCol) +
			". Expected nRow = 3, nCol = 5.";
		return false;
	}
	
	bool caughtError = false;
	try {
		m1.resize(-1,3);
	}
	catch (std::invalid_argument& error) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch invalid_argument exception.";
		return false;
	}
	return true;
}

bool getSizeTest (std::string& errorString) {
	cMatrix m1(2,3), m2;
	int rows, cols;
	m1.getSize(&rows,&cols);
	if (rows != 2 || cols != 3) {
		errorString = "Incorrect matrix size. Expected (2x3), recieved (" +
			std::to_string(rows) + "x" + std::to_string(cols) + ")";
		return false;
	}
	m2.getSize(&rows,&cols);
	if (rows != 0 || cols != 0) {
		errorString = "Incorrect matrix size. Expected (0x0), recieved (" +
			std::to_string(rows) + "x" + std::to_string(cols) + ")";
		return false;
	}
	return true;
}

bool getRowSizeTest (std::string& errorString) {
	cMatrix m1(5,5);
	int val = m1.getRowSize();
	if (val != 5) {
		errorString = "Incorrect row size: Expected 5, received " + 
			std::to_string(val);
		return false;
	}
	return true;
}

bool getColSizeTest (std::string& errorString) {
	cMatrix m1(5,5);
	int val = m1.getColSize();
	if (val != 5) {
		errorString = "Incorrect col size: Expected 5, received " + 
			std::to_string(val);
		return false;
	}
	return true;
}

bool opEqualityTest (std::string& errorString) {
	cMatrix m1(2,2);
	m1.set(0,0) = 1;
	m1.set(0,1) = 2;
	m1.set(1,0) = 3;
	m1.set(1,1) = 4;

	cMatrix m2(m1);
	if ((m1 == m2) == false) {
		errorString = "Matrices expected to be equal.";
		return false;
	}
	
	cMatrix m3(2,3);
	m3.set(0,0) = 1;
	m3.set(0,1) = 2;
	m3.set(0,2) = 0;
	m3.set(1,0) = 3;
	m3.set(1,1) = 4;
	m3.set(1,2) = 0;
	if ((m1 == m3) == true) {
		errorString = "Matrices m1 and m3 expected to not be equal.";
		return false;
	}

	cMatrix m4(3,2);
	m4.set(0,0) = 1;
	m4.set(1,0) = 3;
	m4.set(2,0) = 0;
	m4.set(0,1) = 2;
	m4.set(1,1) = 4;
	m4.set(2,1) = 0;
	if ((m1 == m4) == true) {
		errorString = "Matrices m1 and m4 expected to not be equal.";
		return false;
	}
	return true;
}

bool opInequalityTest (std::string& errorString) {
	cMatrix m1(2,2);
	m1.set(0,0) = 1;
	m1.set(0,1) = 2;
	m1.set(1,0) = 3;
	m1.set(1,1) = 4;

	cMatrix m2(m1);
	if ((m1 != m2) == true) {
		errorString = "Matrices expected to be equal.";
		return false;
	}
	
	cMatrix m3(2,3);
	m3.set(0,0) = 1;
	m3.set(0,1) = 2;
	m3.set(0,2) = 0;
	m3.set(1,0) = 3;
	m3.set(1,1) = 4;
	m3.set(1,2) = 0;
	if ((m1 != m3) == false) {
		errorString = "Matrices m1 and m3 expected to not be equal.";
		return false;
	}

	cMatrix m4(3,2);
	m4.set(0,0) = 1;
	m4.set(1,0) = 3;
	m4.set(2,0) = 0;
	m4.set(0,1) = 2;
	m4.set(1,1) = 4;
	m4.set(2,1) = 0;
	if ((m1 != m4) == false) {
		errorString = "Matrices m1 and m4 expected to not be equal.";
		return false;
	}
	return true;
}

bool opMultiplyTest1 (std::string& errorString) {
	cMatrix m1(2,3), m2(3,2);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	m2.set(0,0) = 321;
	m2.set(0,1) = -0.00001;
	m2.set(1,0) = 432.0/123.9;
	m2.set(1,1) = 7;
	m2.set(2,0) = -48.5;
	m2.set(2,1) = 0;

	cMatrix m3 = m1 * m2;
	cMatrix expMatrix(2,2);
	expMatrix.set(0,0) = (1.0*321.0)+(-2.0*(432.0/123.9))+(3.0*-48.5);
	expMatrix.set(0,1) = (1.0*-0.00001)+(-2.0*7.0)+(3.0*0.0);
	expMatrix.set(1,0) = ((4.0/7.0)*321.0)+(-5.1234*(432.0/123.9))+(6.0*-48.5);
	expMatrix.set(1,1) = ((4.0/7.0)*-0.00001)+(-5.1234*7.0)+(6.0*0.0);
	if (m3 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}

	cMatrix m4(4,4);
	bool caughtError = false;
	try {
		cMatrix m5 = m1*m4;
	}
	catch (std::out_of_range& exception) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch exception";
		return false;
	}
	return true;
}

bool opMultiplyTest2 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 1.5;
	cMatrix m2 = val * m1;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0*val;
	expMatrix.set(0,1) = -2.0*val;
	expMatrix.set(0,2) = 3.0*val;
	expMatrix.set(1,0) = (4.0/7.0)*val;
	expMatrix.set(1,1) = -5.1234*val;
	expMatrix.set(1,2) = 6.0*val;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opMultiplyTest3 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 1.5;
	cMatrix m2 = m1 * val;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0*val;
	expMatrix.set(0,1) = -2.0*val;
	expMatrix.set(0,2) = 3.0*val;
	expMatrix.set(1,0) = (4.0/7.0)*val;
	expMatrix.set(1,1) = -5.1234*val;
	expMatrix.set(1,2) = 6.0*val;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opMultiplyEqualsTest1 (std::string& errorString) {
	cMatrix m1(2,3), m2(3,2);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	m2.set(0,0) = 321;
	m2.set(0,1) = -0.00001;
	m2.set(1,0) = 432.0/123.9;
	m2.set(1,1) = 7;
	m2.set(2,0) = -48.5;
	m2.set(2,1) = 0;

	m1 *= m2;
	cMatrix expMatrix(2,2);
	expMatrix.set(0,0) = (1.0*321.0)+(-2.0*(432.0/123.9))+(3.0*-48.5);
	expMatrix.set(0,1) = (1.0*-0.00001)+(-2.0*7.0)+(3.0*0.0);
	expMatrix.set(1,0) = ((4.0/7.0)*321.0)+(-5.1234*(432.0/123.9))+(6.0*-48.5);
	expMatrix.set(1,1) = ((4.0/7.0)*-0.00001)+(-5.1234*7.0)+(6.0*0.0);
	if (m1 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opMultiplyEqualsTest2 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 1.5;
	m1 *= val;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0*val;
	expMatrix.set(0,1) = -2.0*val;
	expMatrix.set(0,2) = 3.0*val;
	expMatrix.set(1,0) = (4.0/7.0)*val;
	expMatrix.set(1,1) = -5.1234*val;
	expMatrix.set(1,2) = 6.0*val;
	if (m1 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opAddTest1 (std::string& errorString) {
	cMatrix m1(2,3), m2(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	m2.set(0,0) = 321;
	m2.set(0,1) = -0.00001;
	m2.set(0,2) = 432.0/123.9;
	m2.set(1,0) = 7;
	m2.set(1,1) = -48.5;
	m2.set(1,2) = 0;

	cMatrix m3 = m1 + m2;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0+321.0;
	expMatrix.set(0,1) = -2.0+(-0.00001);
	expMatrix.set(0,2) = 3.0+(432.0/123.9);
	expMatrix.set(1,0) = (4.0/7.0)+7.0;
	expMatrix.set(1,1) = -5.1234+(-48.5);
	expMatrix.set(1,2) = 6.0+0.0;
	if (m3 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}

	cMatrix m4(4,4);
	bool caughtError = false;
	try {
		cMatrix m5 = m1+m4;
	}
	catch (std::out_of_range& exception) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch exception";
		return false;
	}
	return true;
}

bool opAddTest2 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 4.5;

	cMatrix m2 = val + m1;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0+val;
	expMatrix.set(0,1) = -2.0+val;
	expMatrix.set(0,2) = 3.0+val;
	expMatrix.set(1,0) = (4.0/7.0)+val;
	expMatrix.set(1,1) = -5.1234+val;
	expMatrix.set(1,2) = 6.0+val;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opAddTest3 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 4.5;

	cMatrix m2 = m1 + val;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0+val;
	expMatrix.set(0,1) = -2.0+val;
	expMatrix.set(0,2) = 3.0+val;
	expMatrix.set(1,0) = (4.0/7.0)+val;
	expMatrix.set(1,1) = -5.1234+val;
	expMatrix.set(1,2) = 6.0+val;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opAddEqualsTest1 (std::string& errorString) {
	cMatrix m1(2,3), m2(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	m2.set(0,0) = 321;
	m2.set(0,1) = -0.00001;
	m2.set(0,2) = 432.0/123.9;
	m2.set(1,0) = 7;
	m2.set(1,1) = -48.5;
	m2.set(1,2) = 0;

	m1 += m2;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0+321.0;
	expMatrix.set(0,1) = -2.0+(-0.00001);
	expMatrix.set(0,2) = 3.0+(432.0/123.9);
	expMatrix.set(1,0) = (4.0/7.0)+7.0;
	expMatrix.set(1,1) = -5.1234+(-48.5);
	expMatrix.set(1,2) = 6.0+0.0;
	if (m1 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}

	cMatrix m4(4,4);
	bool caughtError = false;
	try {
		 m1 += m4;
	}
	catch (std::out_of_range& exception) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch exception";
		return false;
	}
	return true;
}

bool opAddEqualsTest2 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 4.5;

	m1 += val;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0+val;
	expMatrix.set(0,1) = -2.0+val;
	expMatrix.set(0,2) = 3.0+val;
	expMatrix.set(1,0) = (4.0/7.0)+val;
	expMatrix.set(1,1) = -5.1234+val;
	expMatrix.set(1,2) = 6.0+val;
	if (m1 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opSubtractTest1 (std::string& errorString) {
	cMatrix m1(2,3), m2(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	m2.set(0,0) = 321;
	m2.set(0,1) = -0.00001;
	m2.set(0,2) = 432.0/123.9;
	m2.set(1,0) = 7;
	m2.set(1,1) = -48.5;
	m2.set(1,2) = 0;

	cMatrix m3 = m1 - m2;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0-321.0;
	expMatrix.set(0,1) = -2.0-(-0.00001);
	expMatrix.set(0,2) = 3.0-(432.0/123.9);
	expMatrix.set(1,0) = (4.0/7.0)-7.0;
	expMatrix.set(1,1) = -5.1234-(-48.5);
	expMatrix.set(1,2) = 6.0-0.0;
	if (m3 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}

	cMatrix m4(4,4);
	bool caughtError = false;
	try {
		cMatrix m5 = m1-m4;
	}
	catch (std::out_of_range& exception) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch exception";
		return false;
	}
	return true;
}

bool opSubtractTest2 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 4.5;

	cMatrix m2 = val - m1;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = val-1.0;
	expMatrix.set(0,1) = val-(-2.0);
	expMatrix.set(0,2) = val-3.0;
	expMatrix.set(1,0) = val-(4.0/7.0);
	expMatrix.set(1,1) = val-(-5.1234);
	expMatrix.set(1,2) = val-6.0;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opSubtractTest3 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 4.5;

	cMatrix m2 = m1 - val;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0-val;
	expMatrix.set(0,1) = -2.0-val;
	expMatrix.set(0,2) = 3.0-val;
	expMatrix.set(1,0) = (4.0/7.0)-val;
	expMatrix.set(1,1) = -5.1234-val;
	expMatrix.set(1,2) = 6.0-val;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opSubtractEqualsTest1 (std::string& errorString) {
	cMatrix m1(2,3), m2(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	m2.set(0,0) = 321;
	m2.set(0,1) = -0.00001;
	m2.set(0,2) = 432.0/123.9;
	m2.set(1,0) = 7;
	m2.set(1,1) = -48.5;
	m2.set(1,2) = 0;

	m1 -= m2;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0-321.0;
	expMatrix.set(0,1) = -2.0-(-0.00001);
	expMatrix.set(0,2) = 3.0-(432.0/123.9);
	expMatrix.set(1,0) = (4.0/7.0)-7.0;
	expMatrix.set(1,1) = -5.1234-(-48.5);
	expMatrix.set(1,2) = 6.0-0.0;
	if (m1 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}

	cMatrix m4(4,4);
	bool caughtError = false;
	try {
		 m1 -= m4;
	}
	catch (std::out_of_range& exception) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Did not catch exception";
		return false;
	}
	return true;
}

bool opSubtractEqualsTest2 (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4.0/7.0;
	m1.set(1,1) = -5.1234;
	m1.set(1,2) = 6;

	double val = 4.5;

	m1 -= val;
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0-val;
	expMatrix.set(0,1) = -2.0-val;
	expMatrix.set(0,2) = 3.0-val;
	expMatrix.set(1,0) = (4.0/7.0)-val;
	expMatrix.set(1,1) = -5.1234-val;
	expMatrix.set(1,2) = 6.0-val;
	if (m1 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool opOutputTest (std::string& errorString) {
	return true;
}

bool mTransposeTest (std::string& errorString) {
	cMatrix m1(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = 2;
	m1.set(0,2) = 3;
	m1.set(1,0) = 4;
	m1.set(1,1) = 5;
	m1.set(1,2) = 6;

	cMatrix m2 = mTranspose(m1);
	cMatrix expMatrix(3,2);
	expMatrix.set(0,0) = 1;
	expMatrix.set(0,1) = 4;
	expMatrix.set(1,0) = 2;
	expMatrix.set(1,1) = 5;
	expMatrix.set(2,0) = 3;
	expMatrix.set(2,1) = 6;
	if (m2 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	return true;
}

bool mCoeffMultTest (std::string& errorString) {
	cMatrix m1 (2,3), m2(2,3);
	m1.set(0,0) = 1;
	m1.set(0,1) = -2;
	m1.set(0,2) = 3.5;
	m1.set(1,0) = 4;
	m1.set(1,1) = 5;
	m1.set(1,2) = 6;

	m2.set(0,0) = 1;
	m2.set(0,1) = -2;
	m2.set(0,2) = -3.5;
	m2.set(1,0) = 4;
	m2.set(1,1) = 5;
	m2.set(1,2) = 6;
	
	cMatrix m3 = mCoeffMult(m1,m2);
	cMatrix expMatrix(2,3);
	expMatrix.set(0,0) = 1.0*1.0;
	expMatrix.set(0,1) = -2.0*-2.0;
	expMatrix.set(0,2) = 3.5*(-3.5);
	expMatrix.set(1,0) = 4.0*4.0;
	expMatrix.set(1,1) = 5.0*5.0;
	expMatrix.set(1,2) = 6.0*6.0;

	if (m3 != expMatrix) {
		errorString = "Resultant matrix doesn't equal the expected matrix";
		return false;
	}
	cMatrix m4(2,4);
	bool caughtError = false;
	try {
		cMatrix m5 = mCoeffMult(m1,m4);
	}
	catch (std::out_of_range& exception) {
		caughtError = true;
	}
	if (caughtError == false) {
		errorString = "Didn't catch the exception";
		return false;
	}
	return true;
}
