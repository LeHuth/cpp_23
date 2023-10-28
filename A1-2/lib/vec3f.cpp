//
// Created by leo on 17.10.23.
//

#include "vec3f.h"
#include <stdexcept>


float my::Vec3f::operator[](int x) const {
    if(x < 0 || x >= 3) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[x];
}

float &my::Vec3f::operator[](int x) {
    if(x < 0 || x >= 3) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[x];
}

bool my::Vec3f::operator==(const my::Vec3f& rhs) const {
    return data[0] == rhs.data[0] && data[1] == rhs.data[1] && data[2] == rhs.data[2];
}

bool my::Vec3f::operator!=(const my::Vec3f& rhs) const {
    return !(*this == rhs);
}

my::Vec3f &my::Vec3f::operator+=(const my::Vec3f& rhs) {
    data[0] += rhs.data[0];
    data[1] += rhs.data[1];
    data[2] += rhs.data[2];
    return *this;
}

my::Vec3f my::Vec3f::operator+(const my::Vec3f& rhs) const {
    return Vec3f{data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2]};
}

my::Vec3f my::Vec3f::operator-() const {
    return Vec3f{-data[0], -data[1], -data[2]};
}

float my::dot(my::Vec3f a, my::Vec3f b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}



