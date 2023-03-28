#include <iostream>
#include <cstdlib>
#include "utilities.h"

using namespace std;

int randomWithLimits(int lower, int upper) {
	return lower + (rand() % (upper - lower + 1));
}
