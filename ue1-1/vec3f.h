
#pragma once
#include <array>

//Define a namespace - fct: prevent name conflict btw class, variable, function
namespace my
{
    class Vec3f{

    public:
    //Constructor + set default value
        Vec3f(float x=0.0f, float y=0.0f, float z=0.0f);


    // Declare an operation method
        float operator[](int position);

    private:
        std::array<float,3> myArray_;
    };
}

