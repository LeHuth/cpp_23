#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "lib/vec.h"
#include "lib/tests/test11.h"
#include "lib/tests/genericTest.h"

using vec3f = Vec<float, 3>;

int main() {
    std::cout << "Hello, World!" << std::endl;
    test_GeneericVec<int, 3>();
    test_GeneericVec<int, 50>();
    test_GeneericVec<float, 1>();
    test_GeneericVec<double, 23>();
    test_Vec3f();

    std::vector<vec3f> vecs;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for(int i = 0; i < 10; i++){
        std::array<float, 3> arr = {static_cast<float>(dis(gen)), static_cast<float>(dis(gen)), static_cast<float>(dis(gen))};
        vecs.emplace_back(arr);
    }


    return 0;
}
