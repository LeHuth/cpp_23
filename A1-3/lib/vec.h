//
// Created by leo on 17.10.23.
//
#include <array>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <valarray>
#include <vector>

#ifndef A1_1_VEC3F_H
#define A1_1_VEC3F_H

namespace my {
    template <typename T, int N>
    requires std::is_arithmetic_v<T>
    class Vec {
        std::array<T, N> data;

    public:
        // Constructor
        Vec(std::array<T, N> const& data);

        // Default constructor initializes all elements to zero
        Vec();

        // Accessor methods
        T operator[](const int x) const;
        T& operator[](const int x);

        // Comparison operators
        bool operator==(const Vec& rhs) const;
        bool operator!=(const Vec& rhs) const;

        // Arithmetic operators
        Vec& operator+=(const Vec& rhs);
        Vec operator+(const Vec& rhs) const;
        Vec operator-() const;

        //1-3
        T const* begin() const { return data.begin(); }
        T const* end() const { return data.end(); }
        T length() const;

    };

    // Deduction guide to help compiler deduce type and size
    template <typename T, std::size_t N>
    Vec(std::array<T, N>) -> Vec<T, N>;

    // Default constructor implementation
    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    Vec<T, N>::Vec() : data({}) {}

    // Constructor implementation
    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    Vec<T, N>::Vec(std::array<T, N> const& data) : data(data) {}

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    T Vec<T, N>::length() const {
        return std::sqrt(dot(*this, *this));
    }

    // Overloaded operators implementation
    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    T& Vec<T, N>::operator[](const int x) {
        if (x < 0 || x >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[x];
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    T Vec<T, N>::operator[](const int x) const {
        if (x < 0 || x >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[x];
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    bool Vec<T, N>::operator==(const Vec& rhs) const {
        return data == rhs.data;
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    bool Vec<T, N>::operator!=(const Vec& rhs) const {
        return !(*this == rhs);
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    Vec<T, N>& Vec<T, N>::operator+=(const Vec& rhs) {
        std::transform(data.begin(), data.end(), rhs.begin(), data.begin(),
                       [](T a, T b) { return a + b; });
        return *this;
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    Vec<T, N> Vec<T, N>::operator+(const Vec& rhs) const {
        Vec result = *this;
        result += rhs;
        return result;
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    Vec<T, N> Vec<T, N>::operator-() const {
        std::array<T, N> negData;
        std::transform(data.begin(), data.end(), negData.begin(),
                       [](T a) { return -a; });
        return Vec(negData);
    }

    // Dot product function
    template<typename T, int N>
    T dot(const Vec<T, N>& a, const Vec<T, N>& b) {
        return std::inner_product(a.begin(), a.end(), b.begin(), static_cast<T>(0));
    }

    template<typename T, int N>
    void printVec(const Vec<T, N>& vec){
        std::for_each(vec.begin(), vec.end(), [](T& val) {
            std::cout << val << " ";
        });
        std::cout << "Length: " << vec.length() << std::endl;
    }

    template<typename T, int N>
    void printContainerAndLength(const std::vector<Vec<T,N>>& container){
        std::for_each(container.begin(), container.end(), [](Vec<T,N>& vec) {
            printVec(vec);
        });
    }
}

#endif //A1_1_VEC3F_H
