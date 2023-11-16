//
// Created by Joshua Nielsen on 11/8/23.
//

#include "Color.h"

void write_color(std::ostream &out, Color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
