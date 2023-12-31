//
// Created by Curtis Barnhart on 2023-11-15.
//

#include <cmath>

#include "Sphere.h"

Sphere::Sphere(Point3 _center, double _radius) : center(_center), radius(_radius) {}

bool Sphere::hit(const Ray &r, Interval ray_t, HitRecord &rec) const {
    Vec3 oc = r.origin() - this->center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;
    auto sqrtd = std::sqrt(discriminant);

    // Finding a root that both lies in the t range and is closest if there are two intersections
    auto root = (-half_b - sqrtd) / a;
    if (!ray_t.surrounds(root)) {
        root = (-half_b + sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            return false;
        }
    }

    // Calculate when and where the hit was and what the normal is at that point.
    rec.t = root;
    rec.p = r.at(rec.t);
    Vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
}
