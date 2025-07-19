#include <iostream>
#include <boost/math/distributions/normal.hpp>

#include "bsm.h"


int main(){


    const double underlyingAssetPrice {100};
    const double strikePrice {100};
    const double expirationTimeYr {1};

    volatile double riskFreeInterestRate {0.05}, volatility {0.2};

	std::cout << BlackScholesModel::d1(underlyingAssetPrice, strikePrice, expirationTimeYr, riskFreeInterestRate, volatility) << std::endl;
    std::cout << BlackScholesModel::d2(underlyingAssetPrice, strikePrice, expirationTimeYr, riskFreeInterestRate, volatility) << std::endl;
    std::cout << BlackScholesModel::callOptionPrice(underlyingAssetPrice, strikePrice, expirationTimeYr, riskFreeInterestRate, volatility) << std::endl;
    std::cout << BlackScholesModel::putOptionPrice(underlyingAssetPrice, strikePrice, expirationTimeYr, riskFreeInterestRate, volatility) << std::endl;


    // boost::math::normal_distribution<> standard_normal(0, 1.0);

    // std::cout << 100 * boost::math::cdf(standard_normal, 0.15) - 100 * std::exp(-0.05 * 1) * boost::math::cdf(standard_normal, 0.35);

}