//
// Created by leo on 13.04.23.
//

#ifndef HELLO_WORLD_VEC2_H
#define HELLO_WORLD_VEC2_H

#include <array>

namespace my {
    class Vec3f {
    public:
        Vec3f(float x = 0, float y = 0, float z = 0);

        float x() const { return data_[0]; };
        float y() const { return data_[1]; };
        float z() const { return data_[2]; };

        void setX(float x) { data_[0] = x; };
        void setY(float y) { data_[1] = y; };
        void setZ(float z) { data_[2] = z; };

        float operator[](int i) const;
        float& operator[](int i);
        bool operator==(const Vec3f& other) const;
        bool operator!=(const Vec3f& other) const;
        Vec3f operator+(const Vec3f& other) const;
        Vec3f operator-(const Vec3f& other) const;
        Vec3f operator-() const;
        Vec3f operator+=(const Vec3f& other);
        Vec3f operator-=(const Vec3f& other);


    private:
        std::array<float, 3> data_;
    };
    float dot(const Vec3f& lhs , const Vec3f& rhs);
};
#endif //HELLO_WORLD_VEC2_H
