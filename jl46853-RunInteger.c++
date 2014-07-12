// -------------------------------
// projects/integer/RunInteger.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------------

/*
To compile the program:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Integer.c++ RunInteger.c++ -o RunInteger

To run the program:
    % valgrind RunInteger < RunInteger.in

To obtain coverage of the run:
    % gcov-4.7 -b Integer.c++ RunInteger.c++

To configure Doxygen:
    % doxygen -g
    That creates the file "Doxyfile".
    Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque>    // deque
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than  15  s with    valgrind
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;
 
    {
        const clock_t begin_time = clock();
        const Integer<int> n = Integer<int>(2).pow(4423) - 1;
        cout << "2^4423 - 1 = " << n << endl << endl;
        cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl<< endl;    
        cout << "run1 in ms "<< float( clock () - begin_time ) /  (CLOCKS_PER_SEC/1000) << endl<<endl;    

    }

    {
        const clock_t begin_time = clock();
        const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
        cout << "2^4423 - 1 = " << n << endl << endl;
        cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl<<endl;    
        cout << "run2 in ms "<< float( clock () - begin_time ) /  (CLOCKS_PER_SEC/1000) << endl<<endl;    
    }

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min without valgrind
    // don't run with valgrind
    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

    {
        const clock_t begin_time = clock();
        const Integer<int> n = Integer<int>(2).pow(132049) - 1;
        cout << "2^132049 - 1 = " << n << endl << endl;
        cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl<<endl;    
    }

    cout << "Done." << endl;

    return 0;}
