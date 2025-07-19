#include <iostream>
#include <cmath>
#include "bsm.h"


int main(){

	std::cout << blackScholesModel(100, 100, 1, 0.05, 0.2, "d1") << std::endl;
}