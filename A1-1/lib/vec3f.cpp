//
// Created by leo on 17.10.23.
//

#include "vec3f.h"
#include <stdexcept>
//maybe return reference?
float my::Vec3f::get_x() const {
    return data[0];
}

float my::Vec3f::get_y() const {
    return data[1];
}

float my::Vec3f::get_z() const {
    return data[2];
}

float my::Vec3f::operator[](int x) const {
    if(x < 0 || x >= 3) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[x];
}

float &my::Vec3f::operator[](int x) {
    return data[x];
}

bool my::Vec3f::operator==(const my::Vec3f& rhs) const {
    return get_x() == rhs.get_x() && get_y() == rhs.get_y() && get_z() == rhs.get_z();
}

bool my::Vec3f::operator!=(const my::Vec3f& rhs) const {
    return get_x() != rhs.get_x() || get_y() != rhs.get_y() || get_z() != rhs.get_z();
}

my::Vec3f &my::Vec3f::operator+=(const my::Vec3f& rhs) {
    data[0] += rhs.get_x();
    data[1] += rhs.get_y();
    data[2] += rhs.get_z();
    return *this;
}

my::Vec3f my::Vec3f::operator+(const my::Vec3f& rhs) const {
    return my::Vec3f{get_x()+rhs.get_x(), get_y()+rhs.get_y(), get_z()+rhs.get_z()};
}

my::Vec3f my::Vec3f::operator-() const {
    return Vec3f{-get_x(),-get_y(),-get_z()};
}

float my::dot(my::Vec3f a, my::Vec3f b) {
    return a.get_x()*b.get_x() + a.get_y()*b.get_y() + a.get_z()*b.get_z();
}



