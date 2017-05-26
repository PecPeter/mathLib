#include "mathLinAlgebraTest.hpp"

void mathLinAlgebraTest (void) {
	std::string errorString;
	if (maxTest(errorString) == false)
		std::cout << "Failed maxTest(). Error: " << errorString << "\n";
	if (minTest(errorString) == false)
		std::cout << "Failed minTest(). Error: " << errorString << "\n";
	if (clampMaxTest(errorString) == false)
		std::cout << "Failed clampMaxTest(). Error: " << errorString << "\n";
	if (clampMinTest(errorString) == false)
		std::cout << "Failed clampMinTest(). Error: " << errorString << "\n";
	if (clampRangeTest(errorString) == false)
		std::cout << "Failed clampRangeTest(). Error: " << errorString << "\n";
	if (isWithinRangeTest(errorString) == false)
		std::cout << "Failed isWithinRangeTest(). Error: " << errorString << "\n";
	if (rotnTransformTest(errorString) == false)
		std::cout << "Failed rotnTransformTest(). Error: " << errorString << "\n";
	if (lineIntersectionTest(errorString) == false)
		std::cout << "Failed lineIntersectionTest(). Error: " << errorString << 
					 "\n";
}

bool maxTest (std::string& errorString) {
	double v1, v2, v3, v4, v5;
	v1 = max(0,1);
	v2 = max(1,0);
	v3 = max(1,1);
	v4 = max(-2,-3);
	v5 = max(-1.00000001,-1.00000002);

	if (v1 != 1) {
		errorString = "\tmax(0,1): expected 1\n";
		return false;
	}
	if (v2 != 1) {
		errorString = "\tmax(1,0): expected 1\n";
		return false;
	}
	if (v3 != 1) {
		errorString = "\tmax(1,1): expected 1\n";
		return false;
	}
	if (v4 != -2) {
		errorString = "\tmax(-2,-3): expected -2\n";
		return false;
	}
	if (v5 != -1.00000001) {
		errorString = "\tmax(-1.00000001,-1.00000002): expected -1.00000001\n";
		return false;
	}
	return true;
}

bool minTest (std::string& errorString) {
	double v1, v2, v3, v4, v5;
	v1 = min(0,1);
	v2 = min(1,0);
	v3 = min(1,1);
	v4 = min(-2,-3);
	v5 = min(-1.00000001,-1.00000002);

	if (v1 != 0) {
		errorString = "\tmin(0,1): expected 0\n";
		return false;
	}
	if (v2 != 0) {
		errorString = "\tmin(1,0): expected 0\n";
		return false;
	}
	if (v3 != 1) {
		errorString = "\tmin(1,1): expected 1\n";
		return false;
	}
	if (v4 != -3) {
		errorString = "\tmin(-2,-3): expected -3\n";
		return false;
	}
	if (v5 != -1.00000002) {
		errorString = "\tmin(-1.00000001,-1.00000002): expected -1.00000002\n";
		return false;
	}
	return true;
}

bool clampMaxTest (std::string& errorString) {
	double value = 0, oldVal = value;
	clampMax(-2,value);
	if (value != -2.0) {
		errorString = "\tclampMax(-2," + std::to_string(oldVal) + 
					  "): expected -2\n";
		return false;
	}

	oldVal = value;
	clampMax(0,value);
	if (value != -2.0) {
		errorString = "\tclampMax(-2," + std::to_string(oldVal) + 
					  "): expected -2\n";
		return false;
	}

	value = 5;
	oldVal = value;
	clampMax(10,value);
	if (value != 5.0) {
		errorString = "\tclampMax(-2," + std::to_string(oldVal) + 
					  "): expected -2\n";
		return false;
	}

	value = 0.0002;
	oldVal = value;
	clampMax(0.0001,value);
	if (value != 0.0001) {
		errorString = "\tclampMax(-2," + std::to_string(oldVal) + 
					  "): expected -2\n";
		return false;
	}
	return true;
}

bool clampMinTest (std::string& errorString) {
	double value = 0, oldVal = value;
	clampMin(-2,value);
	if (value != 0) {
		errorString = "\tclampmin(-2," + std::to_string(oldVal) + 
					  "): expected 0\n";
		return false;
	}

	oldVal = value;
	clampMin(0,value);
	if (value != 0) {
		errorString = "\tclampmin(-2," + std::to_string(oldVal) + 
					  "): expected 0\n";
		return false;
	}

	value = 5;
	oldVal = value;
	clampMin(10,value);
	if (value != 10.0) {
		errorString = "\tclampmin(-2," + std::to_string(oldVal) + 
					  "): expected 0\n";
		return false;
	}

	value = 0.0002;
	oldVal = value;
	clampMin(0.0001,value);
	if (value != 0.0002) {
		errorString = "\tclampmin(-2," + std::to_string(oldVal) + 
					  "): expected 0\n";
		return false;
	}
	return true;
}

bool clampRangeTest (std::string& errorString) {
	double max, min, value, oldVal, expResult;

	max = 10;
	min = 0;
	value = 5;
	oldVal = value;
	expResult = 5;
	clampRange(min,max,value);
	if (value != expResult) {
		errorString = "\tclampRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(oldVal) + 
					 "): expected " + std::to_string(expResult) +
					 " but received " + std::to_string(value) + "\n";
		return false;
	}

	max = -1;
	min = -2;
	value = 0;
	oldVal = value;
	expResult = -1;
	clampRange(min,max,value);
	if (value != expResult) {
		errorString = "\tclampRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(oldVal) + 
					 "): expected " + std::to_string(expResult) +
					 " but received " + std::to_string(value) + "\n";
		return false;
	}

	max = 10;
	min = 15;
	value = 1;
	oldVal = value;
	expResult = 10;
	clampRange(min,max,value);
	if (value != expResult) {
		errorString = "\tclampRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(oldVal) + 
					 "): expected " + std::to_string(expResult) +
					 " but received " + std::to_string(value) + "\n";
		return false;
	}

	max = -2.6;
	min = -2.6;
	value = -999;
	oldVal = value;
	expResult = -2.6;
	clampRange(min,max,value);
	if (value != expResult) {
		errorString = "\tclampRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(oldVal) + 
					 "): expected " + std::to_string(expResult) +
					 " but received " + std::to_string(value) + "\n";
		return false;
	}
	return true;
}

bool isWithinRangeTest (std::string& errorString) {
	double min, max, value;
	bool result, expResult;

	min = -5.1234;
	max = -6.2345;
	value = -5;
	expResult = false;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = -5.1234;
	max = -6.2345;
	value = -5.5;
	expResult = true;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = 5.987;
	max = 10;
	value = 7;
	expResult = true;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = 5.987;
	max = 10;
	value = 87.789;
	expResult = false;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = -25.25;
	max = -25.25;
	value = 2;
	expResult = false;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = -25.25;
	max = -25.25;
	value = -25.25;
	expResult = true;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = 5;
	max = 5;
	value = 2;
	expResult = false;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	min = 5;
	max = 5;
	value = 5;
	expResult = true;
	result = isWithinRange(min,max,value);
	if (result != expResult) {
		errorString = "\tisWithinRange(" + std::to_string(min) + "," +
					  std::to_string(max) + "," + std::to_string(value) + 
					  "): expected " + std::to_string(expResult) +
					  " but received " + std::to_string(result) + "\n";
		return false;
	}

	return true;
}

bool rotnTransformTest (std::string& errorString) {
	errorString = "\tNeed to write the unit test for this function\n";
	return false;
}

bool lineIntersectionTest (std::string& errorString) {
	errorString = "\tNeed to write the unit test for this function\n";
	return false;
}
