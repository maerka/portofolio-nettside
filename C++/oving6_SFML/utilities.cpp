#include "utilities.h"
#include <iostream>
#include <cstdlib>


int randomWithLimits(int lowerLimit, int upperLimit) {

	int ranNum = std::rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
	//std::cout << "ranNumTest % upperLimit + lowerLimit: " << ranNum << std::endl;
	return ranNum;
}	

