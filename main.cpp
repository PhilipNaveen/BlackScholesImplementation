


#include <iostream>
#include <iomanip>
#include <boost/math/distributions/normal.hpp>
#include "bsm.h"

int main(){
    try {

        // Example option parameters
        double S = 100.0;    // Current stock price
        double K = 105.0;    // Strike price
        double T = 0.25;     // Time to expiration (3 months)
        double r = 0.05;     // Risk-free rate (5%)
        double sigma = 0.2;  // Volatility (20%)

        // Create Black-Scholes model
        BlackScholesModel bsm(S, K, T, r, sigma);

        std::cout << std::fixed << std::setprecision(4);
        std::cout << "=== Black-Scholes Option Pricing and Greeks ===" << std::endl;
        std::cout << "Stock Price: $" << S << std::endl;
        std::cout << "Strike Price: $" << K << std::endl;
        std::cout << "Time to Expiry: " << T << " years" << std::endl;
        std::cout << "Risk-free Rate: " << (r * 100) << "%" << std::endl;
        std::cout << "Volatility: " << (sigma * 100) << "%" << std::endl;
        std::cout << std::endl;

        // Option Prices
        std::cout << "=== Option Prices ===" << std::endl;
        std::cout << "Call Price: $" << bsm.callPrice() << std::endl;
        std::cout << "Put Price: $" << bsm.putPrice() << std::endl;
        std::cout << std::endl;

        // Greeks
        std::cout << "=== Greeks ===" << std::endl;
        std::cout << "Call Delta: " << bsm.callDelta() << std::endl;
        std::cout << "Put Delta: " << bsm.putDelta() << std::endl;
        std::cout << "Gamma: " << bsm.gamma() << std::endl;
        std::cout << "Call Theta: " << bsm.callTheta() << " (per day)" << std::endl;
        std::cout << "Put Theta: " << bsm.putTheta() << " (per day)" << std::endl;
        std::cout << "Vega: " << bsm.vega() << " (per 1% vol change)" << std::endl;
        std::cout << "Call Rho: " << bsm.callRho() << " (per 1% rate change)" << std::endl;
        std::cout << "Put Rho: " << bsm.putRho() << " (per 1% rate change)" << std::endl;

    } catch (const std::exception& e) {
        
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}