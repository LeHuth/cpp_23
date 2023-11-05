#pragma once

#include <iostream>
#include <cassert>
#include <typeinfo>
using namespace std;
#include "../vec.h"

using namespace my;

template<typename T, int N>
void test_GeneericVec(){
    #ifndef NDEBUG
    cout << "=================" << endl;
    cout << "  Testing vec.h  " << endl;
    cout << "=================" << endl;

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
        
        for(int i = 0; i < N; i++)
        {
            b[i] = i+1;
        }

        for(int i = 0; i < N; i++)
        {
            assert(a[i]==0);
            assert(b[i]==i+1);
        }
        //assert( a[0] == 0 && a[1] == 0 && a[2] == 0 );
        //assert( b[0] == 1 && b[1] == 2 && b[2] == 3 );
        cout << "passed." << endl;

        

        cout << "  read-only access to const object: ";
        //assert( b[1] == 2 );
        for(int i = 0; i < N; i++)
        {
            assert(b[i]==i+1);
        }
        cout << "passed." << endl;

        cout << "  write access to a non-const object: ";
        for(int i = 0; i < N; i++)
        {
            if(i==0|| i == 1){
                b[i]=4;
            }
            else
            {
                b[i]=i+1;
            }
            
        }
        //cout << b[1] <<endl;

        for(int i = 0; i < N; i++)
        {
            if(i == 1|| i == 0)
            {
                assert(b[i]==4);
            }
            else
            {
                assert(b[i]==i+1);
            }
            
        }

        //assert( b[0] == 1 );//&& b[1] == 4 && b[2] == 3 );
        cout << "passed." << endl;
    }

    {
        cout << "  comparison: ";        
        Vec<T, N> a, b, c, d;

        for(int i = 0; i < N; i++)
        {
            a[i] = i;
            b[i] = i;
            c[i] = i+3;
            d[i] = i+7;
    
        }

        assert( a == b );//a and b same 
        assert( a == a );// c and d diffrent
        assert( a != c );
        assert( b != d );
        assert( !(a != b) );

        cout << "passed." << endl;
    }

    {
        cout << "  assignment: ";
        Vec<T, N> a;//({1,2,3});
        for(int i = 0; i < N; i++)
        {
            a[i] = i+1;
        }

        cout << a[0] << " "; // to make sure these values are not optimized away! 
        Vec<T,N> b;
        for(int i = 0; i < N; i++)
        {
            b[i] = i + 4;
        }
        a = b;
        for(int i = 0; i < N; i++)
        {
            assert(a[i]==i+4);
        }
        //assert( a[0] == 4 && a[1] == 5 && a[2] == 6 );
        cout << "passed." << endl;
    }
        
    {
        Vec<T, N> a,b,deffinetly_not_a_variable, only_ones_vector, one_plus_a_vec, only_fours_vector,x,y,z, only_threes_vec;
        for(int i = 0; i < N; i++)
        {
            a[i] = i+1;
            b[i] = i+3;
            deffinetly_not_a_variable[i] = a[i] + b[i];
            only_ones_vector[i] = 1;
            only_fours_vector[i] = 4;
            one_plus_a_vec[i] = a[i] + only_ones_vector[i];
            y[i] = 1;
            z[i] = 2;
            only_threes_vec[i] = 3;
        }

        cout << "  addition: ";
        //Vec<T, N> a({1,2,3}), b({4,5,6});

        //Vec<T, N> compilerDoof({5,7,9});

        auto c = a + only_ones_vector;
        //Vec<T, N> var1 ({6,8,10});
        assert( c ==  one_plus_a_vec);
        //Vec<T, N> only_ones_vector({1,1,1}), four({4,4,4});
        only_ones_vector += only_ones_vector+only_ones_vector+only_ones_vector;
        assert( only_ones_vector == only_fours_vector);
        //Vec<T, N> x({0,0,0}), y({1,1,1}), z({2,2,2});
        x += y += z;
        //Vec<T, N> whyNoWorking({3,3,3});
        assert( y ==  only_threes_vec);

        assert( x == y );
        a += b;
        assert( a ==  deffinetly_not_a_variable);
        cout << "passed." << endl;
    }

    {

        Vec<T, N> a;
        Vec<T, N> minusAh;
        for(int i = 0; i < N; i++)
        {
            a[i] = i+1;
            minusAh[i] = -(i+1);
        }
        cout << "  unary minus: ";

        assert( -a == minusAh);
        cout << "passed." << endl;
    }
        
    {
        cout << "  dot product: ";
        Vec<T, N> a;
        T num = 0;

        for(int i = 0; i < N; i++)
        {
            a[i] = i+1;
            T x = i + 1;  
            num = num + x*x; //bug
        }
        assert( (dot(a,a) == num) );
        
        cout << "passed." << endl;
    }

        
    {
        // these tests will not compile if you forgot to declare 
        // some methods const
        
        std::array<T,N> arr;
        Vec<T, N>ahplusah;
        Vec<T, N>minusAh;
        T num = 0;
        for(int i = 0; i < N; i++)
        {
            arr[i] = i+1;
            ahplusah[i]=((i+1)+(i+1));
            minusAh[i]= -(i+1);
            T x = i + 1;
            num += x*x;
            
        }
        const Vec<T, N> a(arr);
        cout << "  constness: ";
        if(N == 1){
            assert(a[0]==1);
        }
        else
        {
            assert( a[1] == 2 );
        }
        
        assert( a == a );
        assert( ! (a != a) );
        assert( a+a ==  ahplusah);
        assert( -a ==  minusAh);
        assert(( dot(a,a) == num ));
        cout << "passed." << endl;
    }




    #endif

}