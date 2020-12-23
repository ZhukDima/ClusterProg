#ifndef UNIVERSALCALCDELTA_H
#define UNIVERSALCALCDELTA_H

#include <cmath> // abs

struct UniversalCalcDelta
{
public:
    UniversalCalcDelta() = delete;

    template <typename Data>
    static double calc(const Data &a, const Data &b);
};

template <typename Data>
double UniversalCalcDelta::calc(const Data &a, const Data &b)
{
    return std::abs(a - b);
}

#endif
