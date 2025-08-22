#pragma once

#include <stdexcept>
#include <iostream>
#include <boost/math/distributions/normal.hpp>

class BlackScholesModel{

private:


    // Private member variables
    double S, K, T, r, sigma;

    




    // Const method declarations
    // Internal methods
    const double calculateD1();
    const double calculateD2();

public:


    // Constructor
    BlackScholesModel(double stockPrice, double strikePrice, double expirationTime, double riskFreeRate, double volatility);

    // Destructor
    ~BlackScholesModel();

    // Copy constructor
    BlackScholesModel(const BlackScholesModel& other);

    // Getters
    const double getStockPrice();
    const double getStrikePrice();
    const double getExpirationTime();
    const double getRiskFreeRate();
    const double getVolatility();

    // Setters
    double getStockPrice(double stockPrice);
    double getStrikePrice(double strikePrice);
    double getExpirationTime(double expirationTime);
    double getRiskFreeRate(double riskFreeRate);
    double getVolatility(double volatility);

    // Relevant functions
    double impliedVolatility(double marketVolatility, bool isCall = true, double tolerance = 1e-6, int maxIterations = 100);

    const void displayOptionInfo();


};