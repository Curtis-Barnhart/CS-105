//
// Created by Joshua Nielsen on 11/18/23.
//

#include "HittableList.h"

#include <utility>

HittableList::HittableList() = default;

HittableList::HittableList(shared_ptr<Hittable> object) {
    add(std::move(object));
}

void HittableList::clear() {
    objects.clear();
}

void HittableList::add(shared_ptr<Hittable> object) {
    objects.push_back(object);
}

bool HittableList::hit(const Ray &r, double ray_tmin, double ray_tmax, HitRecord &rec) const {
    HitRecord temp_rec;
    bool hit_anything = false;
    auto closest_so_far = ray_tmax;

    for (const auto& object : objects){
        if(object->hit(r, ray_tmin, closest_so_far, temp_rec)){
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}