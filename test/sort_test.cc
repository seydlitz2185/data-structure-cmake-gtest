#include <gtest/gtest.h>
#include "../sort/sort.h"
#include <algorithm>
#include <random>

int randBetween() {
  const int minValue = -100;
  const int maxValue = 100;

  // The keyword static is required now so that the PRNG and distribution
  // are not re-instantiated every time the function is called. This is
  // important for them both to work as intended. Re-instantiating resets
  // their state, and they constantly start from scratch. They must be allowed
  // to persist their state for better results.
  static std::mt19937 prng(std::random_device{}());  // Note the static
  static std::uniform_int_distribution<int> dist(minValue, maxValue);

  return dist(prng);
}



namespace{

    TEST(sort_test,InsertionSort){
        const int size = 10;
        int a[size],b[size];
        for (int i = 0; i<size;i++){
            int t = randBetween();
            a[i] = t,b[i] = t;
        } 
        std::sort(std::begin(a), std::end(a));
        InsertionSort(b,size);
        EXPECT_TRUE( 0 == std::memcmp( a, b, size ) );
    }

    TEST(sort_test,BinarySearchInsertionSort){
        const int size = 10;
        int a[size],b[size];
        for (int i = 0; i<size;i++){
            int t = randBetween();
            a[i] = t,b[i] = t;
        }   
        std::sort(std::begin(a), std::end(a));
        BinarySearchInsertionSort(b,size);
        EXPECT_TRUE( 0 == std::memcmp( a, b, size ) );
    }


    TEST(sort_test,ShellSort){
        const int size = 10;
        int a[size],b[size];
        for (int i = 0; i<size;i++){
            int t = randBetween();
            a[i] = t,b[i] = t;
        }   
        std::sort(std::begin(a), std::end(a));
        shellsort(b,size);
        EXPECT_TRUE( 0 == std::memcmp( a, b, size ) );
    }

    TEST(sort_test,bubbleSort){
        const int size = 10;
        int a[size],b[size];
        for (int i = 0; i<size;i++){
            int t = randBetween();
            a[i] = t,b[i] = t;
        }   
        std::sort(std::begin(a), std::end(a));
        bubblesort(b,size);
        EXPECT_TRUE( 0 == std::memcmp( a, b, size ) );
    }
}

