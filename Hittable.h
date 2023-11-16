//
// Created by Curtis Barnhart on 2023-11-15.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H


#include "Ray.h"
#include "Vec3.h"

class HitRecord {
public:
    Point3 p;
    Vec3 normal;
    double t{};
};

class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray &r, double ray_tmin, double ray_tmax, HitRecord &rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
