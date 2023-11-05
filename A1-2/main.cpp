#include <iostream>
#include "lib/vec.h"
#include "lib/tests/genericVecTest.h"
#include "lib/tests/test11.h"
#include "lib/tests/genericTest.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    test_GeneericVec<int, 3>();
    test_GeneericVec<int, 50>();
    test_GeneericVec<float, 1>();
    test_GeneericVec<double, 23>();
    test_Vec3f();
    return 0;
}
