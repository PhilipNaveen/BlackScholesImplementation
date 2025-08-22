#include <iostream>
#include <cmath>
#include <algorithm>
#include "bsm.h"


// Constructor (no copy constructor or move constructor needed)

BlackScholesModel::BlackScholesModel(double stockPrice, 
                        double strikePrice, double expirationTime, 
                        double riskFreeRate, double volatility)
                        
    : S(stockPrice), K(strikePrice), T(expirationTime), r(riskFreeRate), sigma(volatility), dist(0.0, 1.0){

    if (S <= 0 || K <= 0){

        throw std::invalid_argument("Negative stock price or strike price not allowed.");
    }

    if (T < 0 || r < 0 || sigma < 0){

        throw std::invalid_argument("Non-positive time, rate, volatility not allowed.");
    }
}

// Destructor
BlackScholesModel::~BlackScholesModel() {
    // No dynamic memory to clean up
}

// Copy constructor
BlackScholesModel::BlackScholesModel(const BlackScholesModel& other)
    : S(other.S), K(other.K), T(other.T), r(other.r), sigma(other.sigma), dist(0.0, 1.0) {
}

// D1 and D2 terms

double BlackScholesModel::calculateD1() const{

    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));    
}

double BlackScholesModel::calculateD2() const{

    return calculateD1() - sigma * std::sqrt(T);
}


// Getters

double BlackScholesModel::getStockPrice() const { return S; }
double BlackScholesModel::getStrikePrice() const { return K; }
double BlackScholesModel::getExpirationTime() const { return T; }
double BlackScholesModel::getRiskFreeRate() const { return r; }
double BlackScholesModel::getVolatility() const { return sigma; }
                        

// Setters

void BlackScholesModel::setStockPrice(double stockPrice) {
    if (stockPrice <= 0) throw std::invalid_argument("Stock price must be positive");
    S = stockPrice;
}

void BlackScholesModel::setStrikePrice(double strikePrice) {
    if (strikePrice <= 0) throw std::invalid_argument("Strike price must be positive");
    K = strikePrice;
}

void BlackScholesModel::setExpirationTime(double expirationTime) {
    if (expirationTime < 0) throw std::invalid_argument("Time to expiry cannot be negative");
    T = expirationTime;
}

void BlackScholesModel::setRiskFreeRate(double riskFreeRate) {
    r = riskFreeRate;
}

void BlackScholesModel::setVolatility(double volatility) {
    if (volatility < 0) throw std::invalid_argument("Volatility cannot be negative");
    sigma = volatility;
}


// call price 

double BlackScholesModel::callPrice() const{

    // handle edge case

    if (T == 0){

        return std::max(S - K, 0.0);
    }

    return S * boost::math::cdf(dist, calculateD1()) - K * std::exp(-r * T) * boost::math::cdf(dist, calculateD2());
}

// put price

double BlackScholesModel::putPrice() const{

    // handle edge case

    if (T == 0){

        return std::max(K - S, 0.0);
    }

    return K * std::exp(-r * T) * boost::math::cdf(dist, -calculateD2()) - S * boost::math::cdf(dist, -calculateD1());
}


// Greeks Implementation

// Delta - sensitivity to underlying price change

double BlackScholesModel::callDelta() const {

    if (T == 0) {

        return (S > K) ? 1.0 : 0.0;
    }

    return boost::math::cdf(dist, calculateD1());
}

double BlackScholesModel::putDelta() const {

    if (T == 0) {

        return (S < K) ? -1.0 : 0.0;
    }

    return boost::math::cdf(dist, calculateD1()) - 1.0;
}

double BlackScholesModel::gamma() const {

    if (T == 0) {

        return 0.0;
    }

    double d1 = calculateD1();
    return boost::math::pdf(dist, d1) / (S * sigma * std::sqrt(T));
}

double BlackScholesModel::callTheta() const {

    if (T == 0) {

        return 0.0;
    }

    double d1 = calculateD1();
    double d2 = calculateD2();

    double term1 = -(S * boost::math::pdf(dist, d1) * sigma) / (2.0 * std::sqrt(T));
    double term2 = -r * K * std::exp(-r * T) * boost::math::cdf(dist, d2);

    return (term1 + term2) / 365.0;  // Convert to per day
}

double BlackScholesModel::putTheta() const {

    if (T == 0) {

        return 0.0;
    }

    double d1 = calculateD1();
    double d2 = calculateD2();

    double term1 = -(S * boost::math::pdf(dist, d1) * sigma) / (2.0 * std::sqrt(T));
    double term2 = r * K * std::exp(-r * T) * boost::math::cdf(dist, -d2);

    return (term1 + term2) / 365.0;  // Convert to per day
}

double BlackScholesModel::vega() const {

    if (T == 0) {

        return 0.0;
    }

    double d1 = calculateD1();
    return S * boost::math::pdf(dist, d1) * std::sqrt(T) / 100.0;  // Per 1% change
}

double BlackScholesModel::callRho() const {

    if (T == 0) {

        return 0.0;
    }

    double d2 = calculateD2();
    return K * T * std::exp(-r * T) * boost::math::cdf(dist, d2) / 100.0;  // Per 1% change
}

double BlackScholesModel::putRho() const {

    if (T == 0) {

        return 0.0;
    }

    double d2 = calculateD2();
    return -K * T * std::exp(-r * T) * boost::math::cdf(dist, -d2) / 100.0;  // Per 1% change
}

