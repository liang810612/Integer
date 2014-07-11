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
#include <algorithm> // equal
#include <stdexcept> // invalid_argument
#include <iterator>  //predefined iterator, iterator categories, iterator functions


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
    // OI y = std::copy(b,e,x);
    // OI z = y;
    // std::advance(z,n);
    // std::fill(y, z, 0);
    // return z;

        x = copy(b, e, x);
    return fill_n(x, n, 0);
}

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
    int l = e - b;
    if(n > l){
        *x = 0;
        x++;
        return x;
    }
    else
    {
        return copy_n(b, l - n, x);
    }
}

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
    std::vector<int> number1;
    std::vector<int> number2;
    std::vector<int> tempSum;
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

    if(length1 == 1 && length2 == 1 && number1[0] == 0 && number2[0] == 0){
        *x = 0;
        x++;
    }
    else{
        int sum1 = 0;
        int unit1 =1;
        for(int i = length1-1; i>=0 ; i--){
            sum1 += number1[i] * unit1;
            unit1 *= 10;
        }

        int sum2 = 0;
        int unit2 =1;
        
        for(int i = length2-1; i>=0 ; i--){
        sum2 += number2[i] *unit2;
        unit2 *= 10;
        }
        
        long long sumTotal;
        if (sum1 >= sum2){
           sumTotal = (long long)sum1 - (long long)sum2; 
        }
        else{
            sumTotal =(long long)sum2 - (long long)sum1;
        }
       //cout << sumTotal <<endl;
        if(sumTotal == 0){
            tempSum.push_back(0);
        }
        else{
            while(sumTotal != 0){
                long long answer = sumTotal % 10;
                tempSum.push_back(answer);
                sumTotal = sumTotal / 10;
            }            
        }
        for(std::vector<int>::iterator it = tempSum.end()-1; it >= tempSum.begin(); it--){
            *x = *it;
            x++;            
        }         
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
    std::vector<int> tempSum;
    int counter = 0;
    int counter2 = 0;
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
    if((counter == 1 && number1[0]== 0) ||(counter2 == 1 && number2[0]== 0)){
        *x = 0;
        x++;
    }
    else{
        int sum1 = 0;
        int unit1 =1;
        for(int i = counter-1; i>=0 ; i--){
            sum1 += number1[i] * unit1;
            unit1 *= 10;
        }

        int sum2 = 0;
        int unit2 =1;
        
        for(int i = counter2-1; i>=0 ; i--){
        sum2 += number2[i] *unit2;
        unit2 *= 10;
        }
        
        long long sumTotal;
  
        sumTotal = (long)sum1 * (long)sum2; 

       //cout << sumTotal <<endl;
        if(sumTotal == 0){
            tempSum.push_back(0);
        }
        else{
            while(sumTotal != 0){
                int answer = sumTotal % 10;
                tempSum.push_back(answer);
                sumTotal = sumTotal / 10;
            }            
        }

        for(std::vector<int>::iterator it = tempSum.end()-1; it >= tempSum.begin(); it--){
            *x = *it;
            x++;            
        }         
    } return x;
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
    std::vector<int> number1;
    std::vector<int> number2;
    std::vector<int> tempSum;
    int counter = 0;
    int counter2 = 0;
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

    if(counter < counter2){
        *x = 0;
        x++;
    }
    else if(counter == counter2){
        int divisor =0;
        int unit = 1;

        for(int i = counter2-1; i >= 0 ; i--){
            divisor += number2[i] * unit;
            unit *= 10;  
        }

        int dividend =0;
        int unit2 = 1;

        for(int i = counter -1 ; i >=0; i--){
            dividend += number1[i] * unit2;
            unit2 *= 10;
        }

        if(divisor > dividend || dividend == 0){
            *x = 0;
            x++;
        }
        else{ //counter value > couter2 value 
            int answer = dividend / divisor;

            while(answer != 0){
                int num = answer%10;
               // cout << "answer: " << num << endl;
                tempSum.push_back(num);
                answer = answer / 10;
            }
            for(std::vector<int>::iterator it = tempSum.end()-1; it >= tempSum.begin(); it--){
                *x = *it;
                x++;            
            }
        }
    }
    else{ // counter > counter2
        int divisor =0;
        int unit = 1;

        for(int i = counter2-1; i >= 0 ; i--){
            divisor += number2[i] * unit;
            unit *= 10;  
        }

        int dividend =0;
        int unit2 = 1;

        for(int i = counter -1 ; i >=0; i--){
            dividend += number1[i] * unit2;
            unit2 *= 10;
        }

        int answer = dividend / divisor;

        while(answer != 0){
            int num = answer%10;
            tempSum.push_back(num);
            answer = answer / 10;
        }
        for(std::vector<int>::iterator it = tempSum.end()-1; it >= tempSum.begin(); it--){
            *x = *it;
            x++;            
        }        
    }

    return x;
}




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
        //<your code>
        if(lhs.negative != rhs.negative)
            return false;

        int length_l = lhs.e_pos - lhs.b_pos;
        int length_r = rhs.e_pos - rhs.b_pos;
        if(length_r != length_l)
            return false;

        bool isEqual = equal(lhs.b_pos, lhs.e_pos, rhs.b_pos);
        if (!isEqual)
            return  false;

         return true;


    }

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
        int length_l = lhs.e_pos - rhs.b_pos;
        int length_r = rhs.e_pos - rhs.b_pos;
        
        if(lhs.negative && !rhs.negative){// - < +
            return true;
        }
        else if(!lhs.negative && rhs.negative){// + < -
            return false;
        }
        else if(!lhs.negative && !rhs.negative){// + < +
            if(length_l < length_r){// +s < +l
                return true;
            }
            else if(length_l >length_r){// +l < +s
                return false;
            }
            else{// same sign(+), same length
                while(lhs.b_pos != lhs.e_pos){
                    if(rhs.b_pos == rhs.e_pos || *rhs.b_pos < *lhs.b_pos)
                        return false;
                    else if(*lhs.b_pos < *rhs.b_pos)
                        return true;
                    lhs.b_pos++;
                    rhs.b_pos++;
                }
                return (rhs.b_pos != rhs.e_pos);
            }
        }
        else{//- < -
            if(length_l < length_r){//-s < -l
                return false;
            }
            else if(length_l > length_r){//-l < -s
                return true;
            }
            else{// same sign(-), same length
                while(lhs.b_pos != lhs.e_pos){
                    if(rhs.b_pos == rhs.e_pos || *rhs.b_pos < *lhs.b_pos)
                        return true;
                    else if(*lhs.b_pos < *rhs.b_pos)
                        return false;
                    lhs.b_pos++;
                    rhs.b_pos++;
                }
                return !(rhs.b_pos != rhs.e_pos);
            }

        }
    }

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
        if(rhs.negative)
            lhs << '-';

        for (int i = 0; i < (int)rhs.digits.size(); i++)
            lhs << rhs.digits[i];
        return lhs;
    }

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

        C digits; // the backing container
        // <your data>
        typename C ::iterator b_pos;
        typename C ::iterator e_pos;
        bool negative;
        //int size;

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            //<your code>
            if(digits.size() < 1)
                return false;
            
            if(digits.size() > 1 && digits[0] == 0)
                return false;

            if(digits.size() == 1 && digits[0] == 0 && negative)
                return false;

            for(int i = 0; (unsigned)i < digits.size(); i++){
                if(digits[i] > 9 || digits[i] <0)
                    return false;
            }
            return true;
        }

        void expand_capacity(int increase_size){
            int current_size = distance(b_pos, e_pos);

            digits.resize((digits.size() + increase_size) * 3);

            //reset the iterator as rellocation invalidates them
            b_pos = digits.begin();
            e_pos = next(b_pos, current_size);
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        // default constructor
        Integer(){
            digits.push_back(0);
            b_pos = digits.begin();
            e_pos = digits.end();
            negative = false;
            //size = 1;
        }
        Integer (int value) {
            // <your code>
            //size = 0;
            if(value < 0){
                negative = true;
                value = -value;
            }
            else{
                negative = false;
            }


            if(value == 0){
                digits.push_back(0);
                negative = false;
            }
            else{
                while(value != 0){
                    digits.push_back(value % 10);
                    value = value / 10;
                }
            }
            reverse(digits.begin(), digits.end());
            b_pos = digits.begin();
            e_pos = digits.end();
            assert(valid());
        }

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            // <your code>
            int i = 0;
            negative = false;
            if(value[0] == '-'){
                negative = true;
                ++i;;
            }
            //int c = 0;
            int t = value.length();
            if (t == 1){
                while(t--){
                    digits.push_back(value[i] - 48);
                    ++i;
                }
                if (!valid())
                    throw std::invalid_argument("Integer::Integer(const string&)");
            }

            else{
                --t;
                while(t--){
                    digits.push_back(value[i] - 48);
                    ++i;
                }
                if (!valid())
                    throw std::invalid_argument("Integer::Integer(const string&)");

            }
            b_pos = digits.begin();
            e_pos = digits.end();


        }

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
            Integer res = *this;
            if(*res.b_pos != 0)
                res.negative = !res.negative;
            return res;
        }

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
              if(digits.size() < (unsigned int)(max(distance(b_pos, e_pos), distance(rhs.b_pos, rhs.e_pos)) + 1))
            {   
                expand_capacity(max(distance(b_pos, e_pos), distance(rhs.b_pos, rhs.e_pos)) + 1);
            }

            if(negative != rhs.negative)
            {
                if(*this >= rhs)
                {
                    if(-rhs > *this)
                    {
                        negative = true;
                        e_pos = minus_digits(rhs.b_pos, rhs.e_pos, b_pos, e_pos, b_pos);
                    }
                    else
                    {
                        e_pos = minus_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
                    }
                }
                else
                {
                    if(-(*this) <= rhs)
                    {
                        negative = false;
                        e_pos = minus_digits(rhs.b_pos, rhs.e_pos, b_pos, e_pos, b_pos);
                    }
                    else
                    {
                        e_pos = minus_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
                    }
                }
                
            }
            else
            {
                e_pos = plus_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
            }
            return *this;
        }

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
 
            if(digits.size() < (unsigned int)(max(distance(b_pos, e_pos), distance(rhs.b_pos, rhs.e_pos)) + 1))
            {
                expand_capacity(max(digits.size(), rhs.digits.size()) + 1);
            }

            if(negative == rhs.negative)
            {
                if(negative)
                {
                    if(*this >= rhs)
                    {
                        negative = false;
                        e_pos = minus_digits(rhs.b_pos, rhs.e_pos, b_pos, e_pos, b_pos);
                    }
                    else
                    {
                        e_pos = minus_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
                    }
                }
                else
                {
                    if(*this >= rhs)
                    {
                        e_pos = minus_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
                    }
                    else
                    {
                        negative = true;
                        e_pos = minus_digits(rhs.b_pos, rhs.e_pos, b_pos, e_pos, b_pos);
                    }
                }
            }
            else
            {
                e_pos = plus_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
            }
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
                   //special case: result is 0
            if((*rhs.b_pos == 0) || (*b_pos == 0))
            {
                negative = false;
                *b_pos = 0;
                e_pos = next(b_pos);
                return *this;
            }

            if(digits.size() < (unsigned int)(distance(b_pos, e_pos) + distance(rhs.b_pos, rhs.e_pos)))
            {   
                expand_capacity(digits.size() + rhs.digits.size());
            }

            if(negative == rhs.negative)
            {
                negative = false;
            }
            else
            {
                negative = true;
            }
            e_pos = multiplies_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);
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
               if(*rhs.b_pos == 0)
            {
                throw invalid_argument("Integer::operator /= (const Integer&)");
            }

            //special case: result is 0
            if(*b_pos == 0)
            {
                negative = false;
                *b_pos = 0;
                e_pos = next(b_pos);
                return *this;
            }

            if(negative == rhs.negative)
            {
                negative = false;
            }
            else
            {
                negative = true;
            }

            e_pos = divides_digits(b_pos, e_pos, rhs.b_pos, rhs.e_pos, b_pos);

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

            if(*rhs.b_pos <= 0)
            {
                throw invalid_argument("Integer::operator %= (const Integer&)");
            }
            *this = *this - ((*this / rhs) * rhs);
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
             if(n < 0)
            {
                throw invalid_argument("Integer::operator <<= (int)");
            }
            e_pos = shift_left_digits(b_pos,e_pos,n,b_pos);
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
              if(n < 0)
            {
                throw invalid_argument("Integer::operator >>= (int)");
            }
            e_pos = shift_right_digits(b_pos,e_pos,n,b_pos);
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
            negative = false;
            return *this;
        }

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
            // if((*b_pos == 0) || e <= 0)
            // {
            //     throw invalid_argument("Integer::pow(int)");
            // }
            // Integer temp = *this;

            // while(e-- != 1)
            // {  
            //     *this *= temp;
            // }
            return *this;
    }
};

#endif // Integer_h
