//
// Created by Curtis Barnhart on 2023-11-15.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "Hittable.h"
#include "Vec3.h"

class Sphere : public Hittable {
public:
    Sphere(Point3 _center, double _radius);

    bool hit(const Ray &r, double ray_tmin, double ray_tmax, HitRecord &rec) const override;

private:
    Point3 center;
    double radius;
};


#endif //RAYTRACER_SPHERE_H
