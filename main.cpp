


#include <iostream>
#include <boost/math/distributions/normal.hpp>


int main(){


    boost::math::normal_distribution<> dist(0.0, 1.0);

    std::cout << boost::math::cdf(dist, 0.5) << std::endl;

    return 0;
}