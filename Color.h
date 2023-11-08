//
// Created by Joshua Nielsen on 11/8/23.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "Vec3.h"
#include "iostream"

using Color = Vec3;

void write_color(std::ostream &out, Color pixel_color);

#endif //RAYTRACER_COLOR_H
