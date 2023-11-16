#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

#include <iostream>
#include <cmath>

/**
 * hit_sphere calculates if a ray will intersect with a sphere, and if so, returns the first parametric t value
 * at which the ray intersects the sphere.
 * @param center center of the sphere
 * @param radius radius of the sphere
 * @param r ray to calculate intersection with
 * @return -1 if the ray never intersects the sphere, otherwise the parametric t at which
 */
double hit_sphere(const Point3& center, double radius, const Ray& r) {
    Vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant < 0) ? -1.0 : (-b - std::sqrt(discriminant)) / (2.0*a);
}

/**
 * ray_color returns the color that a ray should "be".
 * If the ray intersects a hard coded in sphere, a color will be returned as a function of the surface normal of the
 * sphere at the point that the ray intersected it.
 * If the ray never hits the sphere, a background gradient formula is followed.
 * @param r ray to color in
 * @return Color value which should be seen from that ray
 */
Color ray_color(const Ray& r) {
    auto intersect = hit_sphere(Point3(0, 0, -1), 0.5, r);
    // If it intersects the sphere, use a formula which determines color based on normal at intersection
    if (intersect > 0.0) {
        Vec3 norm = unit_vector(r.at(intersect) - Vec3(0, 0, -1));
        return 0.5 * Color(norm.x() + 1, norm.y() + 1, norm.z() + 1);
    }

    // If it misses the sphere, use a formula for background color
    Vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - a)*Color(1.0, 1.0, 1.0) + a*Color(0.5, 0.7, 1.0);
}

int main() {
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // ensure image height >= 1
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;  // Length of vector from camera_center to viewport
    auto viewport_height = 2.0;  // Size of viewport
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = Point3(0, 0, 0);  // Place where rays originate from

    // vector from the left the right side of the viewport
    auto viewport_u = Vec3(viewport_width, 0, 0);
    // vector from the top to the bottom side of the viewport
    auto viewport_v = Vec3(0, -viewport_height, 0);

    // calculate horizontal and vertical delta vectors from pixel to pixel
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // calculate location of upper left pixel
    auto viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++)
    {
        std::clog <<"\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++)
        {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            Color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                       \n";
}
