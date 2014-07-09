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
    int len_diff = length1 - length2;
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());
    int max_length = std::max(length1, length2);

    while(len_diff--){
        number2.push_back(0);
    }

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
            if(number1[i] > number2[i]){
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

    while(( number1.size() != 1) && result[(max_length-1)] == 0){
        // cout<< "run this shit!"<< endl;
        result.pop_back();
        max_length--;
    }

    int j = max_length - 1;
    while( max_length--){
        //cout << "hereeeeeeeeeeeeeeeeeee   "<< result[j]<<endl;  
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
                //*tempSum = (sum + carry) % 10;
                tempSum.push_back((sum + carry) % 10);
                carry = (sum+carry) /10;;
                //tempSum++;       
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
            int index2 = counter2-1; //3
            int index = counter-1;   //1
            int temp;
            int temp3 = counter2;     //4

            for(int i = 0; i < counter; i++){
                temp = counter - i -1;       //1
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
                //*tempSum = (sum + carry) % 10;
                tempSum.push_back((sum + carry) % 10);
                carry = (sum+carry) /10;;
                //tempSum++;       
            }
            int countX;
            if(carry > 0){
               countX = counter2 + temp2 ;
                //*tempSum = *tempSum % 10;
                tempSum.push_back(carry);
                //int carry2 = *tempSum / 10;
                //tempSum++;
                //*tempSum = carry2;
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
                //*tempSum = *tempSum % 10;
                tempSum.push_back(carry);
                //int carry2 = *tempSum / 10;
                //tempSum++;
                //*tempSum = carry2;
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
    return x;}
    if(counter < counter2){
        *x = 0;
    }
    else if(counter == counter2){
        if(){
            
        }
        else if(){ //counter value > couter2 value 

        }
    }
    else(){ // counter > counter2

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
