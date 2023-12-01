#ifndef RTPROJECT_H
#define RTPROJECT_H

#include <cmath>
#include <limits>
#include <memory>

//#include "Interval.h"
//#include "Ray.h"
//#include "Vec3.h"

// usings

//using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utility functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// common headers

//#include "Ray.h"
//#include "Vec3.h"

#endif