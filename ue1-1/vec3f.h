//
// Created by leo on 13.04.23.
//

#ifndef HELLO_WORLD_VEC2_H
#define HELLO_WORLD_VEC2_H

#include <array>

namespace my {
    class Vec3f {
        Vec3f(float x = 0, float y = 0, float z = 0) : data_{x,y,z} {}
    public:
    private:
        std::array<float, 3> data_;
    };
};
#endif //HELLO_WORLD_VEC2_H
