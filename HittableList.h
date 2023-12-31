//
// Created by Joshua Nielsen on 11/18/23.
//

#ifndef RAYTRACER_HITTABLELIST_H
#define RAYTRACER_HITTABLELIST_H


#include "Hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable {
public:
    std::vector<std::shared_ptr<Hittable>> objects;

    HittableList();
    HittableList(std::shared_ptr<Hittable> object);

    void clear();
    void add(std::shared_ptr<Hittable> object);

    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
};


#endif //RAYTRACER_HITTABLELIST_H
