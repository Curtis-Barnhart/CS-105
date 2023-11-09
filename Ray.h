//
// Created by Joshua Nielsen on 11/8/23.
//
#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vec3.h"


class Ray {
public:
    Ray();
    Ray(const Point3& origin, const Vec3& direction);

    Point3 origin() const;
    Vec3 direction() const;

    Point3 at(double t) const;

private:
    Point3 orig;
    Vec3 dir;
};


#endif //RAYTRACER_RAY_H
