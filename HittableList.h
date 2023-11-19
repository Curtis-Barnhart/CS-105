//
// Created by Joshua Nielsen on 11/18/23.
//

#ifndef RAYTRACER_HITTABLELIST_H
#define RAYTRACER_HITTABLELIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList {
public:
    std::vector<shared_ptr<Hittable>> objects;

    HittableList();
    HittableList(shared_ptr<Hittable> object);

    void clear();
    void add(shared_ptr<Hittable> object);

    bool hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const override;
};


#endif //RAYTRACER_HITTABLELIST_H
