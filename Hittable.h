//
// Created by Curtis Barnhart on 2023-11-15.
//

#ifndef RAYTRACER_HITTABLE_H
#define RAYTRACER_HITTABLE_H


#include "Ray.h"
#include "Vec3.h"
#include "Interval.h"

class HitRecord {
public:
    Point3 p;  // Point in space where the intersection occurred
    Vec3 normal;  // The normal vector at point p of an object that was intersected
    double t {};  // The t value of the ray at point p
    bool front_face;  //

    void set_face_normal(const Ray& r, const Vec3& outward_normal);  // Sets the normal vector for hit record
};

/**
 * Hittable is an abstract class which holds data about an object that can be intersected
 * by a Ray.
 */
class Hittable {
public:
    virtual ~Hittable() = default;

    /**
     * hit calculates whether or not a Ray intersected with the instance of Hittable it was called on.
     * If the object is hit and the parameter t of the Ray is between ray_tmin and ray_tmax,
     * then hit returns true and stores information about the intersection in rec.
     * The information stored is the Point3 where the intersection occurred,
     * the surface normal of the Hittable instance at the point of intersection,
     * and the value of the parameter t of the Ray at the point of intersection.
     *
     * If multiple hits occur, it is up to the subclass of Hittable to determine what hit to record.
     * @param r the ray to test for intersection
     * @param ray_tmin the minimum value t must have to consider that a hit occurred
     * @param ray_tmax the maximum value t must have to consider that a hit occurred
     * @param rec the HitRecord to store information about the intersection in
     * @return true if a hit occurred, else false
     */
    virtual bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const = 0;
};


#endif //RAYTRACER_HITTABLE_H
