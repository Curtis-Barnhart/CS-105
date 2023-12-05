#ifndef INTERVAL_H
#define INTERVAL_H

#include "RTproject.h"

class Interval {
public:
    double min, max;
    Interval() : min(-infinity), max(+infinity) {} // Default interval is empty
    Interval(double _min, double _max) : min(_min), max(_max) {}

    [[nodiscard]] bool contains(double x) const {
        return min <= x && x <= max;
    }
    [[nodiscard]] bool surrounds(double x) const {
        return min < x && x < max;
    }

    [[nodiscard]] double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const Interval empty, universe;
};
const static Interval empty (-infinity, +infinity);
const static Interval universe(-infinity, +infinity);

#endif