// name：  frac.h 
// author: Amrzs
// date:   2014/05/16 

#ifndef FRAC_H
#define FRAC_H

#include <iostream>
#include <string>

using namespace std;

class Frac {

public:
    Frac(){}
    Frac(int numerator, int denominator);
    Frac(const Frac& src){
        *this = src;
    }
    ~Frac(){
    }

private:
    int numerator = 0, denominator = 1;

public:

    operator double() const{

        return numerator / (double)denominator;
    }

    string toString() const{

        return to_string(numerator) + '/' + to_string(denominator);
    }


    friend istream& operator>>(istream& ins, Frac& obj){

        ins >> obj.numerator >> obj.denominator;
        return ins;
    }

    friend ostream& operator<<(ostream& outs, const Frac& obj){

        outs << obj.toString();
        return outs;
    }


    const Frac reciprocal() const{

        return Frac(denominator, numerator);
    }

    const Frac operator-() const{

        return Frac(-this->numerator, this->denominator);
    }

    friend const Frac operator+(const Frac& lhs, const Frac& rhs);
    friend const Frac operator-(const Frac& lhs, const Frac& rhs);
    friend const Frac operator*(const Frac& lhs, const Frac& rhs);
    friend const Frac operator/(const Frac& lhs, const Frac& rhs);

    friend bool operator<(const Frac& lhs, const Frac& rhs);
    friend bool operator>(const Frac& lhs, const Frac& rhs);
    friend bool operator==(const Frac& lhs, const Frac& rhs);
    friend bool operator!=(const Frac& lhs, const Frac& rhs);
    friend bool operator<=(const Frac& lhs, const Frac& rhs);
    friend bool operator>=(const Frac& lhs, const Frac& rhs);

};






#endif //FRAC_H