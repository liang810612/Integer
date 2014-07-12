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
        return copy_n(b, l - n, x);
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
    int length1 = e1 - b1;
    int length2 = e2 - b2;
    OI l = x;
    II1 m = b1;
    II2 n = b2;
    int temp = 0;
    int carry = 0;
    vector<int> out;

    bool number1IsLarger = true;
    if(length1 > length2)
        number1IsLarger = true;
    else if( length2 > length1)
        number1IsLarger = false;
    else{
        while(e1 != m){
            if(*m > *n){
                number1IsLarger = true;
                break;
            }
            else if(*m < *n){
                number1IsLarger = false;
                break;
            }
            ++m;
            ++n;
        }
    }
    if(number1IsLarger){
        carry = 0;
        e1--;
        e2--;
        while(b2-1 != e2){
            temp = *e1 - *e2 - carry;
            if (temp < 0){
                temp += 10;
                carry = 1;
                *x = temp;
            }
            else{
                carry = 0;
                *x = temp;
            }
            --e1;
            --e2;
            ++x;
        }
        while(e1 != b1-1){
            if(carry > 0){
                temp = *e1 - 1;
                *x = temp;
                
                carry = 0;
            }
            else{
                *x = *e1;
            }
            ++x;
            --e1;
        }
    }else{// number2 is larger>>>>>>>>>>>>>>>>>>>>>>>>>>>>ignore wont be run
        carry = 0;
        e1--;
        e2--;
        while(b1-1 != e1){
            temp = *e2 - *e1 - carry;
            if(temp < 0){
                temp += 10;
                carry = 1;
                *x = temp;
            }
            else{
                *x = temp;
                carry = 0;
            }
            ++x;
            --e1;
            --e2;
        }
        while(e2 != b2-1){
            if(carry > 0){
                temp = *e2 -carry;
                carry = 0;
                //cout<<"temp: "<<temp<<endl;
                if(temp < 0){
                    carry = 1;
                    temp+=10;
                }
                *x = temp;
                --e2;
            }
            else{
                *x = *e2;
                --e2;
            }
            ++x;
        }
    }
    for(OI i = l; i < x; i++)
        out.push_back(*i);
 
    // if(out[0] > 0){
    //     for(int i = out.size()-1; i >= 0; i--){
    //         if(out[i] == 0)
    //             out.pop_back();
    //     }        
    // }
    // else{
    //     for(int i = out.size()-1; i > 0; i--){
    //         if(out[i] == 0)
    //             out.pop_back();  
    //     }      
    // }
    reverse(out.begin(), out.end());// 0 0 0 1
    for(unsigned int i = 0; i < out.size(); i++){
        *l = out[i];
        l++;
    }
    x = l;
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

    if(b1+1 == e1 && *b1 == 0){
        *x = 0;
        x++;
        return x;
    }
    if(b2+1 == e2 && *b2 == 0){
        *x = 0;
        x++;
        return x;
    }
    int counter = 0;

    int i = e1 - b1 + (e2 - b2) ;
    vector<int> result (10 * i);
    int carry = 0;
    II1 anotherE1 = e1;
    int rounds2 = 0;
    int rounds1 = 0;
    --e2;
    --e1;
    while(b2-1 != e2){
        //cout << "e2   " << *e2<< endl;
        e1 = anotherE1 - 1;
        rounds1 = 0;
        while (b1-1 != e1){
            //cout << "e1   "<< *e1<< endl;
            if(rounds2 == 0 || e1 == b1 - 1){
                result[rounds1 + rounds2] = *e1 * *e2;
                //cout <<"a "<< result[rounds2 + rounds1]<< endl;
                if(rounds2 + rounds1 > counter)
                    counter = (rounds2 + rounds1);
            }
            else{
                //cout <<"b1 " << result[rounds2 + rounds1] << endl;
                result[rounds1 + rounds2] += *e1 * *e2;
                // cout <<"b2 " << result[rounds2 + rounds1] << endl;
                if((rounds2 + rounds1) > counter)
                    counter = (rounds2 + rounds1);
            }
            ++rounds1;
            --e1;
        }
        rounds2 ++;
        e2 --;
        //cout << endl;
    }
    vector<int> out;
    //cout<< "rounds1  " << rounds1 << endl;
    //cout<< "rounds2  " << rounds2 << endl;
    for(int i = 0; i < counter+1; i++){
        int temp = carry + result[i];
        //cout << "result "<< result[i]<< endl;
        //cout << "temp " << temp << endl;
        if (result[i] >= 10){

            carry = temp / 10;
            out.push_back(temp % 10);
        }
        else{
             out.push_back(temp);
            carry = 0;
        }
    }
    while(carry != 0){
        //cout << "qwe"<< endl;
        out.push_back(carry % 10);
        carry = carry / 10;        
    }
    reverse(out.begin(), out.end());
    for(unsigned int i =0; i < out.size(); i++ ){
        *x = out[i];
        x++;
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
        //cout<< "=="<< endl;
        if(lhs.negative != rhs.negative)
            return false;

        int length_l = lhs.end - lhs.begin;
        int length_r = rhs.end - rhs.begin;
        if(length_r != length_l){
            return false;
        }
        bool isEqual = equal(lhs.begin, lhs.end, rhs.begin);
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
        int length_l = lhs.end - rhs.begin;
        int length_r = rhs.end - rhs.begin;
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
            else{
                    while (lhs.begin!=rhs.end)
                    {
                        if (lhs.begin == rhs.end || *rhs.begin<*rhs.begin) return false;
                        else if (rhs.begin<rhs.begin) return true;
                    }
                    return (rhs.begin!=lhs.end);   
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
                  while (rhs.begin!=lhs.end)
                  {
                    if (rhs.begin == lhs.end || *rhs.begin<*rhs.begin) return false;
                    else if (rhs.begin<rhs.begin) return true;
                  }
                  return (rhs.begin!=lhs.end);                
                }
                return !(rhs.begin != rhs.end);
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
        typename C ::iterator begin;
        typename C ::iterator end;
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


    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        // default constructor
        Integer(){
            Integer(0);
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

            value = ::abs(value);

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
            //here
            reverse(digits.begin(), digits.end());
            begin = digits.begin();
            end = digits.end();
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
            begin = digits.begin();
            end = digits.end();
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
            //cout << "- "<< endl;
            Integer res = *this;
            if(*res.begin != 0)
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
            cout<<"+="<<endl;

            // <your code>
            bool flag;
            Integer l = *this;
            Integer s = rhs;
            C result (l.digits.size()+rhs.digits.size() + 1, 0);
            typename C::iterator p;
            if(rhs.negative == this->negative)
                flag = true;
            else
                flag = false;

            if(flag == true){
                p = plus_digits(    (*this).digits.begin(),
                                    (*this).digits.end(),
                                    rhs.digits.begin(),
                                    rhs.digits.end(),
                                    result.begin()  );
                this->negative = rhs.negative;
            }
            else{
                p = minus_digits(   (*this).digits.begin(),
                                    (*this).digits.end(),
                                    rhs.digits.begin(),
                                    rhs.digits.end(),
                                    result.begin());
                if(l > rhs)
                    this->negative = l.negative;
                else
                    this->negative = rhs.negative;
            }
            C newc = C(result.begin(),p);
            this->digits = newc;

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
            //cout<<"-="<<endl;

            bool flag;
            C result ((*this).digits.size() + rhs.digits.size()+1, 0);
            typename C::iterator p;
            if(rhs.negative == this->negative)
                flag = false;
            else
                flag = true;

            if(flag == true){
                p = plus_digits((*this).digits.begin(),
                                (*this).digits.end(),
                                rhs.digits.begin(),
                                rhs.digits.end(),
                                result.begin());
                this->negative = (*this).negative;
            }
            else{
                p = minus_digits(   (*this).digits.begin(),
                                    (*this).digits.end(),
                                    rhs.digits.begin(),
                                    rhs.digits.end(),
                                    result.begin()  );
                if((*this) > rhs && (*this).negative == false){
                    this->negative = false; 
                }
                else if((*this) < rhs && (*this).negative == false){
                    this->negative = true;}
                else{
                    this->negative = false;}
            }
            C newc = C(result.begin(),p);
            this->digits = newc;
            return *this;
        }

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
           if(this->negative ==  rhs.negative)
                this->negative = false;
            else
                this->negative = true;
            Integer l = *this;
            Integer s = rhs;  
            C result (l.digits.size() + s.digits.size()+1, 0);
            typename C::iterator p = multiplies_digits( (*this).digits.begin(),
                                                        (*this).digits.end(),
                                                        rhs.digits.begin(),
                                                        rhs.digits.end(),
                                                        result.begin());//right
            C newc = C(result.begin(),p);
            this->digits = newc;

            return *this;
        }

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            if(*rhs.begin == 0)
                throw invalid_argument("Integer::operator /= (const Integer&)");

            //special case: result is 0
            if(*begin == 0){
                negative = false;
                *begin = 0;
                end = next(begin);
                return *this;
            }
            if(negative == rhs.negative)
                negative = false;
            else
                negative = true;
            end = divides_digits(begin, end, rhs.begin, rhs.end, begin);
            return *this;
        }

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            if(*rhs.begin <= 0)
            {
                throw invalid_argument("Integer::operator %= (const Integer&)");
            }
            *this = *this - ((*this / rhs) * rhs);
            return *this;

        }

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
            end = shift_left_digits(begin,end,n,begin);
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
            end = shift_right_digits(begin,end,n,begin);
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
            if(*this == 0)
                throw::invalid_argument("Integer::Integer()");
            if(e < 0)
                throw::invalid_argument("Integer::Integer()");
            if (e == 0){
                *this = 1;
                return *this;
            }

            Integer n = *this;
            Integer result = 1;

            if(e > 1)
                result = n.pow(e/2); 

            if(!(e & 1) )       // even
                result *= result;
            else{       // odd
                result *= result;
                result *= *this;
            }
            *this = result;
            return *this;
    }
};

#endif // Integer_h
