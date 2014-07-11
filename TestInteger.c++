// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall TestInteger.c++ -o TestInteger -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestInteger

To obtain coverage of the test:
    % gcov-4.7 -b Integer.c++ TestInteger.c++
*/

// --------
// includes
// --------


#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==
#include <algorithm> // equal

#include "gtest/gtest.h"

#include "Integer.h"

// -----------
// TestInteger
// -----------

// -----------------
// shift_left_digits
// -----------------

TEST(Integer, shift_left_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4, 0, 0};
          int x[10];
    const int* p = shift_left_digits(a, a + 3, 2, x);
    ASSERT_EQ(5, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}
    
TEST(Integer, shift_left_digits_2) {
    const int a[] = {1};
    const int b[] = {1, 0, 0, 0, 0};
          int x[10];
    const int* p = shift_left_digits(a, a + 1, 4, x);
    ASSERT_EQ(5, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_left_digits_3) {
    const int a[] = {2, 3, 4, 5};
    const int b[] = {2, 3, 4, 5, 0, 0};
          int x[10];
    const int* p = shift_left_digits(a, a + 4, 2, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_left_digits_4) {
    const int a[] = {0};
    const int b[] = {0,0,0,0};
          int x[10];
    const int* p = shift_left_digits(a, a + 1, 3, x);
    ASSERT_EQ(4, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}        
// ------------------
// shift_right_digits
// ------------------

TEST(Integer, shift_right_digits_1) {
    const int a[] = {2, 3, 4};
    const int b[] = {2};
          int x[10];
    const int* p = shift_right_digits(a, a + 3, 2, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_right_digits_2) {
    const int a[] = {2, 3, 4};
    const int b[] = {2};
          int x[10];
    const int* p = shift_right_digits(a, a + 3, 2, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_right_digits_3) {
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4};
          int x[10];
    const int* p = shift_right_digits(a, a + 3, 0, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_right_digits_4) {
    const int a[] = {2, 3, 4, 5, 6, 7, 8};
    const int b[] = {2};
          int x[10];
    const int* p = shift_right_digits(a, a + 7, 6, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}        
// -----------
// plus_digits
// -----------

TEST(Integer, plus_digits_1) {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    const int c[] = {8, 0, 1};
          int x[10];
    const int* p = plus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, plus_digits_2){
        const int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
              int x[20];
        const int* p = plus_digits(a, a + 10, b, b + 1, x);
        ASSERT_EQ(11, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
}

TEST(Integer, plus_digits_3){
        const int a[] = {0};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        ASSERT_EQ(1, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
}

TEST(Integer, plus_digits_4){
        const int a[] = {6, 4};
        const int b[] = {7, 2};
        const int c[] = {1, 3, 6};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 2, x);
        ASSERT_EQ(3, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
}

TEST(Integer, plus_digits_5){
        const int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
              int x[20];
        const int* p = plus_digits(a, a + 12, b, b + 1, x);
        ASSERT_EQ(13, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
}
// ------------
// minus_digits
// ------------

TEST(Integer, minus_digits_1) {
    const int a[] = {8, 0, 1};
    const int b[] = {5, 6, 7};
    const int c[] = {2, 3, 4};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, minus_digits_2) {
        const int b[] = {1, 0, 0, 0};
        const int a[] = {3, 3};
        const int c[] = {9, 6, 7};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 4, x);
        ASSERT_EQ(3, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
    }

TEST(Integer, minus_digits_3) {
        const int a[] = {1, 0, 0, 0};
        const int b[] = {9, 9, 9};
        const int c[] = {1};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 3, x);

        ASSERT_EQ(1, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
    }

TEST(Integer, minus_digits_4){
        const int a[] = {3, 6};
        const int b[] = {6};
        const int c[] = {3, 0};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 1, x);
        ASSERT_EQ(2, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
}

TEST(Integer, minus_digits_5){
        const int a[] = {1, 0};
        const int b[] = {0};
        const int c[] = {1, 0};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 1, x);
        ASSERT_EQ(2, p - x );
        ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));
}

// -----------------
// multiplies_digits
// -----------------

TEST(Integer, multiplies_digits_1) {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    const int c[] = {1, 3, 2, 6, 7, 8};
          int x[10];
    const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, multiplies_digits_2) {
    const int a[] = {0};
    const int b[] = {5, 6, 7};
    const int c[] = {0};
          int x[10];
    const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, multiplies_digits_3) {
    const int a[] = {1};
    const int b[] = {1};
    const int c[] = {1};
          int x[10];
    const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}    
TEST(Integer, multiplies_digits_4) {
    const int a[] = {9,9,9,9};
    const int b[] = {9,9};
    const int c[] = {9, 8, 9, 9, 0, 1};
          int x[10];
    const int* p = multiplies_digits(a, a + 4, b, b + 2, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, multiplies_digits_5) {
    const int a[] = {9,9};
    const int b[] = {9,9,9,9};
    const int c[] = {9, 8, 9, 9, 0, 1};
          int x[10];
    const int* p = multiplies_digits(a, a + 2, b, b + 4, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, multiplies_digits_6) {
    const int a[] = {2, 3, 4};
    const int b[] = {1};
    const int c[] = {2, 3, 4};
          int x[10];
    const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, multiplies_digits_7777777777777777) {
    const int a[] = {1, 2, 3, 4, 5, 6};
    const int b[] = {6, 5, 4, 3, 2, 1};
    const int c[] = {8,0,7,7,9,8,5,3,3,7,6};
          int x[100];
    const int* p = multiplies_digits(a, a + 6, b, b + 6, x);
    for(int i = 0; i < 11; i++)
        cout <<"c[]"<< c[i]<<endl;

    cout << "size of c "<< sizeof(c)/sizeof(*c)<< endl;
    cout << "p "<< p<< endl;
    cout << "x "<< x<< endl;
    cout << "p - x" << p-x<<endl;
    ASSERT_EQ(11, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}   

// --------------
// divides_digits
// --------------

TEST(Integer, divides_digits_1) {
    const int a[] = {1, 3, 2, 6, 7, 8};
    const int b[] = {5, 6, 7};
    const int c[] = {2, 3, 4};
          int x[10];
    const int* p = divides_digits(a, a + 6, b, b + 3, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, divides_digits_2) {
    const int a[] = {1, 3};
    const int b[] = {5, 6, 7};
    const int c[] = {0};
          int x[10];
    const int* p = divides_digits(a, a + 2, b, b + 3, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, divides_digits_3) {
    const int a[] = {0};
    const int b[] = {5, 6, 7};
    const int c[] = {0};
          int x[10];
    const int* p = divides_digits(a, a + 1, b, b + 3, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, divides_digits_4) {
    const int a[] = {5, 6, 7};
    const int b[] = {5, 6, 7};
    const int c[] = {1};
          int x[10];
    const int* p = divides_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, divides_digits_5) {
    const int a[] = {1, 1, 0, 9, 8, 8, 9};
    const int b[] = {3, 3, 3};
    const int c[] = {3, 3, 3, 3};
          int x[10];
    const int* p = divides_digits(a, a + 7, b, b + 3, x);
    ASSERT_EQ(4, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


// -----------
// constructor
// -----------

TEST(Integer, constructor_1) {
    try {
        const Integer<int> x("abc");
        ASSERT_TRUE(false);}
    catch (std::invalid_argument& e) {
        ASSERT_STREQ("Integer::Integer(const string&)", e.what());}}

TEST(Integer, constructor_2) {
    try {
        const Integer<int> x("77a77");
        ASSERT_TRUE(false);}
    catch (std::invalid_argument& e) {
        ASSERT_STREQ("Integer::Integer(const string&)", e.what());}}

TEST(Integer, constructor_3) {
    try {
        const Integer<int> x("6.6");
        ASSERT_TRUE(false);}
    catch (std::invalid_argument& e) {
        ASSERT_STREQ("Integer::Integer(const string&)", e.what());}}


TEST(Integer, constructor_4) {
    try {
        const Integer<int> x(-9911);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_5) {
    try {
        const Integer<int> x(2222);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_6) {
    try {
        const Integer<int> x("0");}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_7) {
    try {
        const Integer<int> x("-77777");}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}




// ---
// abs
// ---

TEST(Integer, abs_1) {
    try {
        Integer<int>  x = -98765;
        Integer<int>& y = x.abs();
        ASSERT_EQ(98765, x);
        ASSERT_EQ(&x,    &y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, abs_2) {
    try {
        const Integer<int> x = -98765;
        const Integer<int> y = abs(x);
        ASSERT_EQ(-98765, x);
        ASSERT_EQ( 98765, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, abs_3) {
    try {
        const Integer<int> x = -7777;
        const Integer<int> y = abs(x);
        ASSERT_EQ(-7777, x);
        ASSERT_EQ( 7777, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, abs_4) {
    try {
        const Integer<int> x = -0;
        const Integer<int> y = abs(x);
        ASSERT_EQ(-0, x);
        ASSERT_EQ( 0, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

// --------
// equal_to
// --------

TEST(Integer, equal_to) {
    try {
        const Integer<int> x = 98765;
        const Integer<int> y = 98765;
        ASSERT_EQ(      x, y);
        ASSERT_EQ(      x, 98765);
        ASSERT_EQ(  98765, x);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

// --------
// negation
// --------

TEST(Integer, negation) {
    try {
        const Integer<int> x = 98765;
        const Integer<int> y = -x;
        ASSERT_EQ(-98765, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

// ------
// output
// ------

TEST(Integer, output) {
    try {
        const Integer<int> x = 98765;
        std::ostringstream out;
        out << x;
        ASSERT_EQ("98765", out.str());}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

// ---
// pow
// ---

TEST(Integer, pow_1) {
    try {
        Integer<int>       x = 2;
        const int          e = 4423;
        Integer<int>&      y = x.pow(e);
        ASSERT_EQ(4423,  e);
        //ASSERT_EQ(0,  x);
        ASSERT_EQ(  &x, &y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, pow_2) {
    try {
        Integer<int>       x = 2;
        const int          e = 2;
        Integer<int>&      y = x.pow(e);
        cout<<"pow2 x is "<< x<<endl; 
        ASSERT_EQ(2, e);
        ASSERT_EQ(4, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, pow_4) {
    try {
        const Integer<int> x = 2;
        const int          e = 2;
        const Integer<int> y = pow(x, e);
        cout<<"pow4  x is "<< x<<endl; 
        ASSERT_EQ(2, x);
        ASSERT_EQ(2, e);
        ASSERT_EQ(4, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, pow_3) {
    try {
        Integer<int>       x = 1;
        const int          e = 1;
        Integer<int>&      y = x.pow(e);
        //ASSERT_EQ(4, x);
        ASSERT_EQ(1, e);
        ASSERT_EQ(1, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, pow_5) {
    try {
        const Integer<int> x = 12;
        const int          e = 2;
        const Integer<int> y = pow(x, e);
        ASSERT_EQ(12, x);
        ASSERT_EQ(2, e);
        ASSERT_EQ(144, y);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}
