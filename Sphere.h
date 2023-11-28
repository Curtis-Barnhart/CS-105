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

    /**
     * Implements the hit method from Hittable.
     * If the Ray intersects the sphere twice, the closer of the two intersections to the origin
     * of the ray is recorded.
     */
    bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const override;

private:
    Point3 center;
    double radius;
};


#endif //RAYTRACER_SPHERE_H
