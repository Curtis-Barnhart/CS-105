//
// Created by Curtis Barnhart on 2023-11-06.
//

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include <iostream>

class Vec3 {
public:
    double e[3];

    Vec3();  // Default constructor sets all values to 0
    Vec3(double e0, double e1, double e2);  // double constructor sets all values

    [[nodiscard]] double x() const;  // standard getters for all three values
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    Vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    Vec3& operator+=(const Vec3 &v);
    Vec3& operator*=(double t);
    Vec3& operator/=(double t);

    [[nodiscard]] double length() const;
    [[nodiscard]] double length_squared() const;
};

// Point3 is just an alias for Vec3, but useful for geometric clarity in the code.
using Point3 = Vec3;

// Vector Utility Functions
// Because these are all inline, we leave them in the header file so that they can
// be accessed by the C++ compiler in other files
inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
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

#endif //RAYTRACER_VEC3_H
