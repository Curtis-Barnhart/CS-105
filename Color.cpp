//
// Created by Joshua Nielsen on 11/8/23.
//

#include "Color.h"

void write_color(std::ostream &out, Color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    //Divide color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r*= scale;
    g*= scale;
    b*= scale;

    static const Interval intensity(0.000, 0.999);
    out << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}
