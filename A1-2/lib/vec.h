//
// Created by leo on 17.10.23.
//
#include <array>
#include <stdexcept>

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
        for (int i = 0; i < N; i++) {
            if (data[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    bool Vec<T, N>::operator!=(const Vec& rhs) const {
        return !(*this == rhs);
    }

    template<typename T, int N>
    requires std::is_arithmetic_v<T>
    Vec<T, N>& Vec<T, N>::operator+=(const Vec& rhs) {
        for (int i = 0; i < N; i++) {
            data[i] += rhs[i];
        }
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
        for (int i = 0; i < N; i++) {
            negData[i] = -data[i];
        }
        return Vec(negData);
    }

    // Dot product function
    template<typename T, int N>
    T dot(const Vec<T, N>& a, const Vec<T, N>& b) {
        T sum = 0;
        for (int i = 0; i < N; i++) {
            sum += a[i] * b[i];
        }
        return sum;
    }
}

#endif //A1_1_VEC3F_H
