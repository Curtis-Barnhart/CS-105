//
// Created by Joshua Nielsen on 11/8/23.
//

#include "Ray.h"

Ray::Ray(){}
Ray::Ray(const Point3& origin, const Vec3& direction) : orig(origin), dir(direction) {}

Point3 Ray::origin() const {
    return orig;
}
Vec3 Ray::direction() const {
    return dir;
}

Point3 Ray::at(double t) const {
    return orig + t*dir;
}
