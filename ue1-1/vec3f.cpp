//
// Created by leo on 13.04.23.
//
#include "vec3f.h"

my::Vec3f::Vec3f(float x, float y, float z) : data_{x, y, z} {};

float my::Vec3f::operator[](int i) const
{
    return data_[i];
};

float& my::Vec3f::operator[](int i) {
    return data_[i];
}

bool my::Vec3f::operator==(const Vec3f& other) const {
    return data_[0] == other.data_[0] && data_[1] == other.data_[1] && data_[2] == other.data_[2];
}

bool my::Vec3f::operator!=(const Vec3f& other) const {
    return !(*this == other);
}

my::Vec3f my::Vec3f::operator+(const Vec3f& other) const {
    return Vec3f{x() + other.x(), y() + other.y(), z() + other.z()};
}

my::Vec3f my::Vec3f::operator-(const Vec3f& other) const {
    return Vec3f{x() - other.x(), y() - other.y(), z() - other.z()};
}

my::Vec3f my::Vec3f::operator-() const {
    return Vec3f{-x(), -y(), -z()};
}

my::Vec3f my::Vec3f::operator+=(const Vec3f& other) {
    setX(x() + other.x());
    setY(y() + other.y());
    setZ(z() + other.z());

    return *this;
}

my::Vec3f my::Vec3f::operator-=(const Vec3f& other) {
    setX(x() - other.x());
    setY(y() - other.y());
    setZ(z() - other.z());

    return *this;
}

float my::dot(const Vec3f& lhs, const Vec3f& rhs) {
    return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

