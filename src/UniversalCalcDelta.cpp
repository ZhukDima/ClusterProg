#include "UniversalCalcDelta.h"
#include <cmath> // abs

template <typename Data>
double UniversalCalcDelta::calc(const Data &a, const Data &b)
{
    return std::abs(a - b);
}
