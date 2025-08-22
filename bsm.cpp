#include <iostream>
#include <cmath>
#include <algorithm>
#include <"bsm.h">

bsm::BlackScholesModel(double stockPrice, 
                        double strikePrice, double expirationTime, 
                        double riskFreeRate, double volatility)
                        
    : S(stockPrice), K(strikePrice), T(expirationTime), r(riskFreeRate), sigma(volatility){

    if (S <= 0 || K <= 0){

        throw std::invalid_argument("Negative stock price or strike price not allowed.");
    }

    if (T < 0 || r < 0 || sigma < 0){

        throw std::invalid_argument("Non-positive time, rate, volatility not allowed.");
    }
}



                        
