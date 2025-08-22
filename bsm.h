#pragma once

#include <stdexcept>
#include <iostream>
#include <boost/math/distributions/normal.hpp>

class BlackScholesModel{

private:


    // Private member variables
    double S, K, T, r, sigma;

    boost::math::normal_distribution<> dist;

    // Const method declarations
    // Internal methods
    double calculateD1() const;
    double calculateD2() const;

public:

    // Constructor
    BlackScholesModel(double stockPrice, double strikePrice, double expirationTime, double riskFreeRate, double volatility);

    // Destructor
    ~BlackScholesModel();

    // Copy constructor
    BlackScholesModel(const BlackScholesModel& other);

    // Getters
    double getStockPrice() const;
    double getStrikePrice() const;
    double getExpirationTime() const;
    double getRiskFreeRate() const;
    double getVolatility() const;

    // Setters
    void setStockPrice(double stockPrice);
    void setStrikePrice(double strikePrice);
    void setExpirationTime(double expirationTime);
    void setRiskFreeRate(double riskFreeRate);
    void setVolatility(double volatility);

    // Relevant functions
    double callPrice() const;
    double putPrice() const;

    // Greeks
    double callDelta() const;
    double putDelta() const;
    double gamma() const;
    double callTheta() const;
    double putTheta() const;
    double vega() const;
    double callRho() const;
    double putRho() const;
    
    double impliedVolatility(double marketVolatility, bool isCall = true, double tolerance = 1e-6, int maxIterations = 100);

    void displayOptionInfo() const;

};