//
// Created by leo on 17.10.23.
//
#include <array>
#ifndef A1_1_VEC3F_H
#define A1_1_VEC3F_H
namespace my {
    class Vec3f{

        std::array<float, 3> data;

    public:
        Vec3f(float x =0.0f, float y=0.0f, float z=0.0f)
        : data{x,y,z}
        {}


        float operator[](const int x) const;
        float& operator[](const int x);
        bool operator==(const Vec3f& rhs) const;
        bool operator!=(const Vec3f& rhs) const;
        Vec3f& operator+=(const Vec3f& rhs);
        Vec3f operator+(const Vec3f& rhs) const;
        Vec3f operator-() const;


    };

    float dot(Vec3f a, Vec3f b);
}
#endif //A1_1_VEC3F_H
