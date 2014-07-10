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
    std::vector<int> number1;
    std::vector<int> number2;
    int length1 = 0;
    int length2 = 0;
    std::vector<int> tempSum;

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
            sum1 += number1[i] *unit1;
            unit1 *= 10;
        }
        int sum2 = 0;
        int unit2 =1;
        
        for(int i = length2-1; i>=0 ; i--){
        sum2 += number2[i] *unit2;
        unit2 *= 10;
        }
        
        int sumTotal = sum1 + sum2;
        //cout << sumTotal <<endl;
        
        while(sumTotal != 0){
            int answer = sumTotal % 10;
            tempSum.push_back(answer);
            sumTotal = sumTotal / 10;
        }
        for(std::vector<int>::iterator it = tempSum.end()-1; it >= tempSum.begin(); it--){
            *x = *it;
            x++;            
        }         
    }
     
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

    // std::reverse(number1.begin(), number1.end());
    // std::reverse(number2.begin(), number2.end());
    // int max_length = std::max(length1, length2);

    // std::vector<int> result(max_length);
    // int carry = 0;
    // int temp = 0;
    // for (int i = 0; i < max_length; i++){
    //     // number1 and number2has the same length
    //     if (i <= length1 && i <= length2){
    //         temp = number1[i] + number2[i] + carry;
    //         if (temp > 9){
    //             carry = 1;
    //             temp -= 10;
    //             result[i] = temp;
    //         }
    //         else{
    //             result[i] = temp;
    //             carry = 0;
    //         }
    //     }
    //     //number1 is longer
    //     else if(i < length1 && i >= length2){
    //         temp = number1[i] + carry;
    //         if(temp > 9){
    //             carry = 1;
    //             temp -= 10;
    //             result[i] = temp;
    //         }
    //         else{
    //             result[i] = temp;
    //             carry = 0;
    //         }
    //     }
    //     //number2 is longer
    //     else{
    //         temp = number2[i] + carry;
    //         if(temp > 9){
    //             carry = 1;
    //             temp -= 10;
    //             result[i] = temp;
    //         }
    //         else{
    //             carry = 0;
    //             result[i] = temp;
    //         }
    //     }
    // }
    // if (carry == 1){
    //     result.push_back(1);
    //     max_length ++;
    // }
    // int j = max_length - 1;
    // while(max_length--){
    //     *x = result[j];
    //     j--;
    //     x++;
    // }
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
    // <your code>
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
        
        int sumTotal;
        if (sum1 >= sum2){
           sumTotal = sum1 - sum2; 
        }
        else{
            sumTotal = sum2 - sum1;
        }
        
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
    }    
    // int len_diff = length1 - length2;
    // reverse(number1.begin(), number1.end());
    // reverse(number2.begin(), number2.end());
    // int max_length = std::max(length1, length2);

    // while(len_diff--){
    //     number2.push_back(0);
    // }

    // int temp = 0;
    // bool borrow = false;
    // std::vector<int> result(max_length);

    // for(int i = 0; i < max_length; i++){
    //     if (borrow == false){
    //         if(number1[i] >= number2[i]){
    //             temp =  number1[i] - number2[i];
    //             borrow = false;
    //             result[i] = temp;
    //         }
    //         else{
    //             temp = 10 + number1[i] - number2[i];
    //             borrow = true;
    //             result[i] = temp;
    //         }
    //     }
    //     else{// borrow == true
    //         if(number1[i] > number2[i]){
    //             temp = number1[i] - 1 - number2[i];
    //             borrow = false;
    //             result[i] = temp;
    //         }
    //         else{
    //             temp = 10 + number1[i] -1 - number2[i];
    //             borrow = true;
    //             result[i] = temp;
    //         }
    //     }
    // }

    // while(( number1.size() != 1) && result[(max_length-1)] == 0){
    //     result.pop_back();
    //     max_length--;
    // }

    // int j = max_length - 1;
    // while( max_length--){
    //     *x = result[j];
    //     j--;
    //     x++;
    // }
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

    // Specia case if one of the array has only one element and it is zero or both are one
    if((number1[0] == 0|| number2[0] == 0) && (counter == 1 || counter2 ==1)){
        *x = 0;
        x++;
    }
    else if ((number2[0] == 1 && number1[0] == 1) && (counter == 1 || counter2 ==1)){
        *x = 1;
        x++;
    } 
    //array 1 has only one element with value 1
    else if ( number1[0] == 1 && counter == 1 ){
        for(std::vector<int>::iterator it = number2.begin(); it != number2.end(); it++){
            *x = *it;
            x++;            
        }
    }
    //array 2 has only one element with value 1
    else if ((number2[0] == 1 && counter2 ==1)){
        for(std::vector<int>::iterator it = number1.begin(); it != number1.end(); it++){
            *x = *it;
            x++;            
        }
    }                      
    else{
        if(counter2 < counter){
            std::vector< vector<int> >vectorSum (counter2, vector<int>(counter+counter2-1, 0));
        // store values of two arrays into vectorSum
            int index2 = counter2-1; 
            int index = counter-1;
            int temp;
            int temp3 = counter;
            for(int i = 0; i < counter2; i++){
                temp = counter2 - i -1;
                for(int j = counter; j > 0; j--){
                    vectorSum[i][temp3+ temp -1] = (number1[index] * number2[index2]);
                    index--;
                    temp--;
                }
                index2--;
                index = counter-1;
            }
            // calculate and store in digit form
            int temp2 = counter2-1;
            int carry = 0;
            int sum;
            for(int j = counter + temp2 ; j > 0; j--){ //longer elements array
                sum = 0;
                for(int i = 0; i < counter2 ; i++){  // shorter
                    sum += vectorSum[i][j-1];
                }
                tempSum.push_back((sum + carry) % 10);
                carry = (sum+carry) /10;;    
            }
            int countX;
            if(carry > 0){
               countX = counter + temp2 ;    //longer elements array
                tempSum.push_back(carry);
            }
            for(int i = countX; i >= 0; i--){
                *x = tempSum[i];
                x++;
            }
        }
        else if(counter2 > counter){ //counter 2 > counter
            std::vector< vector<int> >vectorSum (counter, vector<int>(counter+counter2-1, 0));
        // store values of two arrays into vectorSum
            int index2 = counter2-1; 
            int index = counter-1;   
            int temp;
            int temp3 = counter2;     

            for(int i = 0; i < counter; i++){
                temp = counter - i -1;       
                for(int j = counter2; j > 0; j--){
                    vectorSum[i][temp3+ temp -1] = (number1[index] * number2[index2]);
                    index2--;
                    temp--;
                }
                index--;
                index2 = counter2-1;
            }
            // calculate and store in digit form
            int temp2 = counter-1;
            int carry = 0;
            int sum;
            for(int j = counter2 + temp2 ; j > 0; j--){
                sum = 0;
                for(int i = 0; i < counter ; i++){
                    sum += vectorSum[i][j-1];
                }
                tempSum.push_back((sum + carry) % 10);
                carry = (sum+carry) /10;;   
            }
            int countX;
            if(carry > 0){
               countX = counter2 + temp2 ;
                tempSum.push_back(carry);
            }
            for(int i = countX; i >= 0; i--){
                *x = tempSum[i];
                x++;
            }             
        }
        else{ // same size in both array
            std::vector< vector<int> >vectorSum (counter, vector<int>(counter2+counter2-1, 0));
            // store values of two arrays into vectorSum
            int index2 = counter2-1; 
            int index = counter-1;
            int temp;
            int temp3 = counter2;
            for(int i = 0; i < counter; i++){
                temp = counter - i -1;
                for(int j = counter2; j > 0; j--){
                    vectorSum[i][temp3+ temp -1] = (number2[index2]*number1[index]);
                    index--;
                    temp--;
                }
                index2--;
                index = counter-1;
            }
            // calculate and store in digit form
            int temp2 = counter-1;
            int carry = 0;
            int sum;
            for(int j = counter + temp2 ; j > 0; j--){
                sum = 0;
                for(int i = 0; i < counter ; i++){
                    sum += vectorSum[i][j-1];
                }
                //*tempSum = (sum + carry) % 10;
                tempSum.push_back((sum + carry) % 10);
                carry = (sum+carry) /10;;
                //tempSum++;       
            }
            int countX;
            if(carry > 0){
               countX = counter2 + temp2 ;
                tempSum.push_back(carry);
            }
            for(int i = countX; i >= 0; i--){
                *x = tempSum[i];
                x++;
            } 
        }     
    }   
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
        if(lhs.negative != rhs.negative)
            return false;

        int length_l = lhs.e_pos - rhs.b_pos;
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
        copy(rhs.b_pos, rhs.e_pos, ostream_iterator<int>(lhs));

        // while(rhs.b_pos != rhs.e_pos){
        //     *lhs = *rhs.b_pos;
        //     lhs++;
        //     rhs.b_pos++:
        // }

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
        int size;

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
        // default constructor
        Integer(){
            digits.push_back(0);
            b_pos = digits.begin();
            e_pos = digits.end();
            negative = false;
            size = 1;
        }
        Integer (int value) {
            // <your code>
            size = 0;
            if(value < 0){
                negative = true;
                value = -value;
            }
            else{
                negative = false;
            }

            if(value == 0){
                digits.push_back(0);
                size ++;
            }
            else{
                while(value != 0){
                    digits.push_back(value % 10);
                    value = value / 10;
                    size ++;
                }
            }
            digits.resize(size);
            b_pos = digits.begin();
            e_pos = digits.end();
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
            Integer res = *this;
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

            return *this;

        }
};

#endif // Integer_h
