// --------------------------
// projects/integer/Integer.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
<<<<<<< HEAD
#include <algorithm>
=======
    #include <algorithm> // equal
>>>>>>> c0d6f543b2896360b9058946bb07cc442a9179cf
using namespace std;
// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename OI>
OI shift_left_digits (II b, II e, int n, OI x) {
    // <your code>
    OI y = std::copy(b,e,x);
    OI z = y;
    std::advance(z,n);
    std::fill(y, z, 0);
    return z;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename OI>
OI shift_right_digits (II b, II e, int n, OI x) {
    // <your code>
    II temp = e - n;
    while(b != temp){
        *x = *b;
        b++;
        x++;
    }
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
   // <your code>
// <<<<<<< Updated upstream
    std::vector<int> number1;
    std::vector<int> number2;
    int length1 = 0;
    int length2 = 0;


    while(b1 != e1){
        number1.push_back(*b1);
        b1++;
        length1++;
    }
    while(b2 != e2){
        number2.push_back(*b2);
        b2++;
        length2++;
    }

    std::reverse(number1.begin(), number1.end());
    std::reverse(number2.begin(), number2.end());
    int max_length = std::max(length1, length2);

    std::vector<int> result(max_length);
    int carry = 0;
    int temp = 0;
    for (int i = 0; i < max_length; i++){
        // number1 and number2has the same length
        if (i <= length1 && i <= length2){
            temp = number1[i] + number2[i] + carry;
            if (temp > 9){
                carry = 1;
                temp -= 10;
                result[i] = temp;
            }
            else{
                result[i] = temp;
                carry = 0;
            }
        }
        //number1 is longer
        else if(i < length1 && i >= length2){
            temp = number1[i] + carry;
            if(temp > 9){
                carry = 1;
                temp -= 10;
                result[i] = temp;
            }
            else{
                result[i] = temp;
                carry = 0;
            }
        }
        //number2 is longer
        else{
            temp = number2[i] + carry;
            if(temp > 9){
                carry = 1;
                temp -= 10;
                result[i] = temp;
            }
            else{
                carry = 0;
                result[i] = temp;
            }
        }
    }
    if (carry == 1){
        result.push_back(1);
        max_length ++;
    }
    int j = max_length - 1;
    while(max_length--){
        *x = result[j];
        j--;
        x++;
    }
    return x;
}
// =======
 
//     int counter = 1;
//     int temp = 0;
//     OI y = x;

//     while(b1 != e1){
//         counter++;
//         b1++;
//     }
//     for(int i = 1; i <= counter ; i++)
//         b1--;
//     // //int arr[counter]; 
//     for(int i = 1; i <= counter ; i++){
//         *x = (*b1 + *b2);
//         *y = (*b1 + *b2);
//         b1++;
//         b2++;
//         x++;
//         y++;
//     }
//     for(int i = 1; i <= counter; i++){
//         y--;
//         if(*y >= 10){
//             counter++;
//             break;
//         } 
//     }

//     for(int i = 1 ; i <= counter; i++){  
//         if(*x >= 10){
//             *x = (*x % 10) + temp;
//             temp = 1;
//         }       
//         else{
//             *x = *x % 10 + temp;
//             if(*x >=10){
//                 temp = 1;
//                 *x = (*x % 10);
//             }
//         }   
//         x--;
//     }
     // while(counter != 1){
     //     x++;
     //     counter--;
     // }
    // return x;}
// >>>>>>> Stashed changes

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    std::vector<int> number1;
    std::vector<int> number2;
    int length1 = 0;
    int length2 = 0;

    while(b1 != e1){
        number1.push_back(*b1);
        b1++;
        length1++;
    }
    while(b2 != e2){
        number2.push_back(*b2);
        b2++;
        length2++;
    }

    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());
    int max_length = std::max(length1, length2);


    int temp = 0;
    bool borrow = false;
    std::vector<int> result(max_length);

    for(int i = 0; i < max_length; i++){
        
        if (borrow == false){
            if(number1[i] >= number2[i]){
                temp =  number1[i] - number2[i];
                borrow = false;
                result[i] = temp;
            }
            else{
                temp = 10 + number1[i] - number2[i];
                borrow = true;
                result[i] = temp;
            }
        }
        else{// borrow == true
            if(number1[i] >= number2[i]){
                temp = number1[i] - 1 - number2[i];
                borrow = false;
                result[i] = temp;
            }
            else{
                temp = 10 + number1[i] -1 - number2[i];
                borrow = true;
                result[i] = temp;
            }
        }
    }

    if(borrow == true){
        result.pop_back();
        max_length--;
    }


    int j = max_length - 1;
    while(max_length--){
        *x = result[j];
        j--;
        x++;
    }


    return x;
}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    std::vector<int> number1;
    std::vector<int> number2;
    std::vector<int> vectorSum;
    int counter = 0;
    int counter2 = 0;
    OI tempSum = x;
    while(b1!= e1){
        number1.push_back(*b1);
        b1++;
        counter++;
    }
    while(b2 != e2){
        number2.push_back(*b2);
        b2++;
        counter2++;
    }
    for(vector<int>::iterator i = number1.begin();i != number1.end(); i++){
        for(vector<int>::iterator i = number2.begin();i != number2.end(); i++){

        }
    }


//---------------------------------------------------    
    // std::vector<int> number1;
    // std::vector<int> number2;
    // int length1 = 0;
    // int length2 = 0;

    // while(b1 != e1){
    //     number1.push_back(*b1);
    //     b1++;
    //     length1++;
    // }
    // while(b2 != e2){
    //     number2.push_back(*b2);
    //     b2++;
    //     length2++;
    // }

    // reverse(number1.begin(), number1.end());
    // reverse(number2.begin(), number2.end());
    // int max_length = std::max(length1, length2);

    // int m[length2][length1]; // [row] [col]

    // for(int i = 0; i < length2; i++){
    //     for(int j = 0; j < length1; j++){
    //         m[i][j] = number2[b] * number1[a];
    //     }
    // }
//--------------------------------------------------
return x;


}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code>
        return false;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
        return false;}

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        // <your code>
        return lhs << "0";}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
        // <your data>

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Integer (int value) {
            // <your code>
            assert(valid());}

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");}

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            // <your code>
            return Integer(0);}

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            // <your code>
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            return *this;}};

#endif // Integer_h
