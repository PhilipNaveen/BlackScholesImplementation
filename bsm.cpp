#include <iostream>
#include <cmath>
#include "bsm.h"

double d1(const double S, const double K, const double T, const double r, const double sigma){

	return std::log(S / K) + (r + 0.5 * std::pow(sigma, 2) * T) / (sigma * std::sqrt(T));

}



double d2(const double S, const double K, const double T, const double r, const double sigma){

    return d1(S, K, T, r, sigma) - sigma * std::sqrt(T);
}