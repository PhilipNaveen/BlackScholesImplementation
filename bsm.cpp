#include <iostream>
#include <cmath>
#include "bsm.h"

double blackScholesModel(const double S, const double K, const double T, const double r, const double sigma, std::string_view action){

	if (action == "d1"){

		return std::log(S / K) + (r + 0.5 * std::pow(sigma, 2) * T) / (sigma * std::sqrt(T));



	}

	return 1.0;

}