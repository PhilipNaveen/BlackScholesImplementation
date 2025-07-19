#include <iostream>

#include "bsm.h"


int main(){


    const double underlyingAssetPrice {100};
    const double strikePrice {100};
    const double expirationTimeYr {1};

    volatile double riskFreeInterestRate {0.05}, volatility {0.2};

	std::cout << d1(underlyingAssetPrice, strikePrice, expirationTimeYr, riskFreeInterestRate, volatility) << std::endl;
    std::cout << d2(underlyingAssetPrice, strikePrice, expirationTimeYr, riskFreeInterestRate, volatility) << std::endl;
}