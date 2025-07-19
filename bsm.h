#pragma once
#include <iostream>


double d1(const double S, const double K, const double T, const double r, const double sigma);

double d2(const double S, const double K, const double T, const double r, const double sigma);

double callOptionPrice(const double S, const double K, const double T, const double r, const double sigma);

double putOptionPrice(const double S, const double K, const double T, const double r, const double sigma);