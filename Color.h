//
// Created by Joshua Nielsen on 11/8/23.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "Vec3.h"
#include "iostream"

/**
 * Color is a wrapper over Vec3. Color simply uses the (x, y, z) values of Vec3 to store
 * RGB values, where 0 is the minimum of a single color and 1 is the maximum.
 */
using Color = Vec3;

/**
 * write_color writes the value of a Color instance to a std::ostream in the format "c c c\n",
 * where "c" is a value from 0 to 255 inclusive representing a level of red, blue, or green respectively.
 * @param out location to write the color values to
 * @param pixel_color the color instance whose values are written
 */
void write_color(std::ostream &out, Color pixel_color);

#endif //RAYTRACER_COLOR_H
