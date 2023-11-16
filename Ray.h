//
// Created by Joshua Nielsen on 11/8/23.
//
#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vec3.h"

/**
 * A Ray stores data about a ray in 3D space as a parametric equation (origin + t(direction)).
 */
class Ray {
public:
    Ray();  // Empty constructor creates origin and direction as both the origin (0, 0, 0)
    Ray(const Point3 &origin, const Vec3 &direction);  // Instantiates a ray by copying the given Point3 and Vec3

    [[nodiscard]] Point3 origin() const;  // Returns a copy of the origin of the ray
    [[nodiscard]] Vec3 direction() const;  // Returns a copy of the direction of the ray

    [[nodiscard]] Point3 at(double t) const;  // Returns a Point3 giving the ray's position at time t

private:
    Point3 orig;
    Vec3 dir;
};


#endif //RAYTRACER_RAY_H
