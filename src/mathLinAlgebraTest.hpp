#ifndef MATHLINALGEBRATEST_HPP
#define MATHLINALGEBRATEST_HPP

#include <iostream>
#include <string>

#include "./mathLib/mathLinAlgebra.hpp"

void mathLinAlgebraTest (void);

bool maxTest (std::string& errorString);
bool minTest (std::string& errorString);
bool clampMaxTest (std::string& errorString);
bool clampMinTest (std::string& errorString);
bool clampRangeTest (std::string& errorString);
bool isWithinRangeTest (std::string& errorString);
bool rotnTransformTest (std::string& errorString);
bool lineIntersectionTest (std::string& errorString);

#endif
