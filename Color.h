//
// Created by Joshua Nielsen on 11/8/23.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


#include "Vec3.h"
#include "iostream"
#include "Interval.h"

/**
 * Color is a wrapper over Vec3. Color simply uses the (x, y, z) values of Vec3 to store
 * RGB values, where 0 is the minimum of a single color and 1 is the maximum.
 */
using Color = Vec3;

/**
 * write_color writes the color value of a Color instance to a std::ostream in the format "c c c\n",
 * where "c" is a value from 0 to 255 inclusive representing a level of red, blue or green respectively.
 * It treats pixel_color as though it were the sum of several Color instances, and writes their average.
 * It uses the int samples_per_pixel as the amount of Color instances added together to create pixel_color.
 *
 * @param out location to write the color values to
 * @param pixel_color the color instance whose values are written
 * @param samples_per_pixel the number of color samples taken for this pixel
 */
void write_color(std::ostream &out, Color pixel_color, int samples_per_pixel);


#endif //RAYTRACER_COLOR_H
