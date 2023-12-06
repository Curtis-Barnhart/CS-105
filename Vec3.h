//
// Created by Curtis Barnhart on 2023-11-06.
//

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include <iostream>

/**
 * Vec3 stores a tuple of three doubles and provides a few utility methods for them.
 * This can be useful for storing any sort of three dimensional data, like a color,
 * a position in 3D space, or anything that can be built with these like a vector in 3D space.
 */
class Vec3 {
public:
    double e[3];

    Vec3();  // Default constructor sets all three values in Vec3 to 0
    Vec3(double e0, double e1, double e2);  // double constructor sets all three values in Vec3

    [[nodiscard]] double x() const;  // getter for x component of Vec3
    [[nodiscard]] double y() const;  // getter for y component of Vec3
    [[nodiscard]] double z() const;  // getter for z component of Vec3

    Vec3 operator-() const;
    double operator[](int i) const; // indexing by 0 produces the x component, by 1 the y, and by 2 the z
    double &operator[](int i); // indexing by 0 produces the x component, by 1 the y, and by 2 the z

    Vec3 &operator+=(const Vec3 &v);  // Component-wise addition of two Vec3
    Vec3 &operator*=(double t);  // Component-wise multiplication of two Vec3
    Vec3 &operator/=(double t);  // Component-wise division of two Vec3

    [[nodiscard]] double length() const;  // Returns the square root of the sum of the squares of a Vec3's components
    [[nodiscard]] double length_squared() const;  // Returns the sum of the squares of the components of a Vec3

    static Vec3 random();
    static Vec3 random(double min, double max);
};

// Point3 is just an alias for Vec3, but useful for geometric clarity in the code.
using Point3 = Vec3;

// Vector Utility Functions
// Because these are all inline, we leave them in the header file so that they can
// be accessed by the C++ compiler in other files
inline std::ostream &operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}
inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
}
inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
}
inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]};
}
inline Vec3 operator*(double t, const Vec3 &v) {
    return {t*v.e[0], t*v.e[1], t*v.e[2]};
}
inline Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}
inline Vec3 operator/(Vec3 v, double t) {
    return (1/t) * v;
}
inline double dot(const Vec3 &u, const Vec3 &v) {
    return u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}
inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]};
}
inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

inline Vec3 random_in_unit_sphere() {
    while (true) {
        auto p = Vec3::random(-1,1);
        if (p.length_squared() < 1)
        return p;
    }
}

inline Vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

inline Vec3 random_on_hemisphere(const Vec3& normal) {
    Vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}
#endif //RAYTRACER_VEC3_H
