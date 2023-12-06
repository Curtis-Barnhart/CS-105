#ifndef CAMERA_H
#define CAMERA_H


#include <iostream>

#include "RTproject.h"
#include "Color.h"
#include "Hittable.h"

class Camera {
public:
    double aspect_ratio = 1.0; // Ratio of image width over height
    int image_width = 100; // Rendered image width in pixel count
    int samples_per_pixel = 10; //Count of random samples for each pixel
    int max_depth = 10; // Maximum number of ray bounces into scene

    void render(const Hittable& world);

private:
    int image_height; // Rendered image height
    Point3 center; // Camera center
    Point3 pixel00_loc; // Location of pixel 0, 0
    Vec3 pixel_delta_u; // Offset to pixel to the right
    Vec3 pixel_delta_v; // Offset to pixel below

    void initialize();

    [[nodiscard]] Ray get_ray(int i, int j) const;

    [[nodiscard]] Vec3 pixel_sample_square() const;

    [[nodiscard]] Color ray_color(const Ray& r, int depth, const Hittable& world) const;
};


#endif
