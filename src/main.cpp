#include <iostream>

#include "mathLinAlgebraTest.hpp"
#include "mathMatrixTest.hpp"

int main (void) {
	std::cout << "Executing mathMatrix Test\n";
	mathMatrixTest();
	std::cout << "Finished testing mathMatrix test\n";

	std::cout << "Executing mathLinAlgebra Test\n";
	mathLinAlgebraTest();
	std::cout << "Finished testing mathLinAlgebra Test\n";
	return 0;
}
