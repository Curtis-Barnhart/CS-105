//
// Created by Curtis Barnhart on 2023-11-15.
//

#include "Hittable.h"

/**
 * set_face_normal takes a unit vector of the outwards pointing surface normal of an object at the point of intersection
 * with a ray and determines whether the ray intersected that object from the inside or the outside. It then sets the
 * "normal" member of the HitRecord so that it is on the same side of the object as where the ray came from.
 *
 * @param r ray which intersected an object.
 * @param outward_normal unit vector of the outwards pointing surface normal of an object at the point of intersection
 *        with the ray r.
 */
void HitRecord::set_face_normal(const Ray& r, const Vec3& outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}
