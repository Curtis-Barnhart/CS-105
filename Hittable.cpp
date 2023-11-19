//
// Created by Curtis Barnhart on 2023-11-15.
//

#include "Hittable.h"

void HitRecord::set_face_normal(const Ray& r, const Vec3& outward_normal) {
    //Sets the normal vector for hit record
    //outward_normal is expected to have unit length

    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}