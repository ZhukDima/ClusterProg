#ifndef UNIVERSALCALCDELTA_H
#define UNIVERSALCALCDELTA_H

struct UniversalCalcDelta
{
public:
    UniversalCalcDelta() = delete;

    template <typename Data>
    static double calc(const Data &a, const Data &b);
};

#endif