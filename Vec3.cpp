//
// Created by Curtis Barnhart on 2023-11-06.
//

#include "Vec3.h"
#include "RTproject.h"

Vec3::Vec3() : e{0, 0, 0} {}

Vec3::Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double Vec3::x() const {
    return this->e[0];
}

double Vec3::y() const {
    return this->e[1];
}

double Vec3::z() const {
    return this->e[2];
}

Vec3 Vec3::operator-() const {
     return {-e[0],-e[1],-e[2]};
}

double Vec3::operator[](int i) const {
    return e[i];
}

double &Vec3::operator[](int i) {
    return e[i];
}

Vec3 &Vec3::operator+=(const Vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vec3 &Vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3 &Vec3::operator/=(double t) {
    return *this *= 1/t;
}

double Vec3::length() const {
    return sqrt(length_squared());
}

double Vec3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

Vec3 Vec3::random() {
    return Vec3(random_double(), random_double(), random_double());
}

Vec3 Vec3::random(double min, double max) {
    return Vec3(random_double(min,max), random_double(min,max), random_double(min,max));
}
