//
// Created by leo on 13.04.23.
//
#include "vec3f.h"

float my::Vec3f::operator[](int i) const {
    return data_[i];
}

float& my::Vec3f::operator[](int i) {
    return data_[i];
}

bool my::Vec3f::operator==(const Vec3f& other) const {
    return data_[0] == other.data_[0] && data_[1] == other.data_[1] && data_[2] == other.data_[2];
}

bool my::Vec3f::operator!=(const Vec3f& other) const {
    return !(*this == other);
}

