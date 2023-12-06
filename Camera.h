#ifndef CAMERA_H
#define CAMERA_H


#include <iostream>

#include "RTproject.h"
#include "Color.h"
#include "Hittable.h"

class Camera {
public:
    double aspect_ratio = 1.0;  // Ratio of image width over height
    int image_width = 100;  // Rendered image width in pixel count
    int samples_per_pixel = 10;  // Count of random samples for each pixel
    int max_depth = 10;  // Maximum number of ray bounces into scene

    void render(const Hittable& world);

private:
    int image_height;  // Rendered image height
    Point3 center;  // Camera center
    Point3 pixel00_loc;  // Location of pixel 0, 0
    Vec3 pixel_delta_u;  // Offset to pixel to the right
    Vec3 pixel_delta_v;  // Offset to pixel below

    void initialize();

    /**
     * get_ray returns a ray that points from the origin of the camera to somewhere within the pixel (i, j) on the
     * projection of the world. "Somewhere within in the pixel" means within the rectangle whose height is equal to
     * pixel_delta_v and whose width is equal to pixel_delta_u and whose center is at the center of the pixel (i, j).
     *
     * @param i the x value of the pixel to get a ray to.
     * @param j the y value of the pixel to get a ray to.
     * @return A ray pointing to somewhere within the pixel (i, j).
     */
    [[nodiscard]] Ray get_ray(int i, int j) const;

    /**
     * pixel_sample_square returns a random Vec3 representing an x and y axes offset to a Vec3 such that the offset
     * is within plus or minus half the width and height of a pixel.
     *
     * @return Vec3 offset to x and y axes within half the width and height of a pixel.
     */
    [[nodiscard]] Vec3 pixel_sample_square() const;

    [[nodiscard]] Color ray_color(const Ray& r, int depth, const Hittable& world) const;
};


#endif
