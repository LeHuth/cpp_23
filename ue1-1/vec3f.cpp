#include "vec3f.h"

using namespace std;
using namespace my;

Vec3f::Vec3f(float x, float y, float z)
    : myArray_{x,y,z}{
    }

float
Vec3f::operator[](int positon){
    return myArray_.at(positon);
}