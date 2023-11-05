//
// Created by leona on 10/28/2023.
//

#ifndef A1_2_GENERICVECTEST_H
#define A1_2_GENERICVECTEST_H
#include <iostream>
#include <cassert>
#include <typeinfo>
using namespace std;

#include "../vec.h"  // Make sure the path to vec.h is correct
using namespace my;
template<typename T, int N>
void test_GenericVec1() {

    cout << "======================" << endl;
    cout << "  Testing Generic Vec " << endl;
    cout << "======================" << endl;

    {
        cout << "sizeof(Vec<T,N>) == " + to_string(N) + " bytes: ";
        Vec<T, N> a;
        assert( sizeof(a) == N*sizeof(T) );
        cout << "passed" << endl;
    }

    {
        cout << "  constructor & index operator: ";
        Vec<T, N> a;
        Vec<T, N> b;

        for (int i = 0; i < N; i++) {
            b[i] = i + 1;
        }

        for (int i = 0; i < N; i++) {
            assert(a[i] == 0);
            assert(b[i] == i + 1);
        }
        cout << "passed." << endl;
    }
    {
        cout << "  read-only access to const object: ";
        const Vec<T, N> a;
        // the next line will throw a compiler error if there is no proper "operator[] const"
        assert(a[1] == 0);
        cout << "passed." << endl;
    }
    {
        cout << "  write access to a non-const object: ";
        Vec<T, N> a;
        a[1] = 4;
        assert(a[0] == 0 && a[1] == 4);
        cout << "passed." << endl;
    }
    {
        cout << "  comparison: ";
        Vec<T, N> a;
        Vec<T, N> b;
        Vec<T, N> c;
        Vec<T, N> d;
        for (int i = 0; i < N; i++) {
            b[i] = i + 1;
            c[i] = i + 1;
            d[i] = i + 2;
        }
        assert(a == a);
        assert(a == b);
        assert(a != d);
        assert(b == c);
        assert(b != d);
        assert(!(a != b));
        cout << "passed." << endl;
    }
    {
        cout << "  assignment: ";
        Vec<T, N> a;
        Vec<T, N> b;
        Vec<T, N> c;
        Vec<T, N> d;
        for (int i = 0; i < N; i++) {
            b[i] = i + 1;
            c[i] = i + 1;
            d[i] = i + 2;
        }
        a = b;
        assert(a == b);
        assert(a == c);
        assert(a != d);
        assert(b == c);
        assert(b != d);
        assert(!(a != b));
        cout << "passed." << endl;
    }
    {
        cout << "  addition: ";
        Vec<T, N> a;
        Vec<T, N> b;
        Vec<T, N> c;
        Vec<T, N> d;
        for (int i = 0; i < N; i++) {
            b[i] = i + 1;
            c[i] = i + 1;
            d[i] = i + 2;
        }
        a = b + c;
        assert(a == d);
        cout << "passed." << endl;
    }
    {
        cout << "  unary minus: ";
        Vec<T, N> a;
        Vec<T, N> b;
        for (int i = 0; i < N; i++) {
            a[i] = i + 1;
            b[i] = -i - 1;
        }
        assert(-a == b);
        cout << "passed." << endl;
    }
    {
        cout << "  dot product: ";
        Vec<T, N> a;
        Vec<T, N> b;
        for (int i = 0; i < N; i++) {
            a[i] = i + 1;
            b[i] = i + 1;
        }
        assert(a.dot(b) == 14);
    }
}
#endif //A1_2_GENERICVECTEST_H
