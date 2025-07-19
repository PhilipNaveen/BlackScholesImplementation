#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include "bsm.h"

namespace BlackScholesModel{


    double d1(const double S, const double K, const double T, const double r, const double sigma){

        return std::log(S / K) + (r + 0.5 * std::pow(sigma, 2) * T) / (sigma * std::sqrt(T));

    }


    double d2(const double S, const double K, const double T, const double r, const double sigma){

        return d1(S, K, T, r, sigma) - sigma * std::sqrt(T);
    }
    

    double callOptionPrice(const double S, const double K, const double T, const double r, const double sigma){

        boost::math::normal_distribution<> standard_normal(0, 1.0);

        double d_1 {d1(S, K, T, r, sigma)};
        double d_2 {d2(S, K, T, r, sigma)};
        
        return S * boost::math::cdf(standard_normal, d_1) - K * std::exp(-r * T) * boost::math::cdf(standard_normal, d_2);
    }


    double putOptionPrice(const double S, const double K, const double T, const double r, const double sigma){

        boost::math::normal_distribution<> standard_normal(0, 1.0);
        
        double d_1 {d1(S, K, T, r, sigma)};
        double d_2 {d2(S, K, T, r, sigma)};

        return K * std::exp(-r * T) * boost::math::cdf(standard_normal, -d_2) - S * boost::math::cdf(standard_normal, -d_1);
    }



}