// name：  frac.h 
// author: Amrzs
// date:   2014/05/17

#include <cstdlib>
#include "frac.h"

using namespace std;

int gcd(int x, int y){

    int t = x % y;
    while(t != 0){
        x = y;
        y = t;
        t = x % y;
    }

    if(y < 0)
        y = -y;
    return y;
}

Frac::Frac(int numerator, int denominator):
    numerator(numerator),
    denominator(denominator){

    if(0 == denominator){
        cerr << "Denominator can't be zero." << endl;
        exit(1);
    }

    int t = gcd(numerator, denominator);
    this->numerator /= t;
    this->denominator /= t;
}


bool operator<(const Frac& lhs, const Frac& rhs){

    Frac hs = lhs - rhs;
    return (hs.numerator < 0);
}

bool operator>(const Frac& lhs, const Frac& rhs){

    return rhs < lhs;
}

bool operator==(const Frac& lhs, const Frac& rhs){

    return (lhs.numerator==rhs.numerator && lhs.denominator==lhs.denominator);
}

bool operator<=(const Frac& lhs, const Frac& rhs){

    return (lhs<rhs || lhs==rhs);
}

bool operator>=(const Frac& lhs, const Frac& rhs){

    return (lhs>rhs || lhs==rhs);
}

bool operator!=(const Frac& lhs, const Frac& rhs){

    return !(lhs == rhs);
}


const Frac operator+(const Frac& lhs, const Frac& rhs){

    int denominator = lhs.denominator * rhs.denominator;
    int numerator = lhs.denominator * rhs.numerator + rhs.denominator * lhs.numerator;

    return Frac(numerator, denominator);
}

const Frac operator-(const Frac& lhs, const Frac& rhs){

    return lhs + (-rhs);
}

const Frac operator*(const Frac& lhs, const Frac& rhs){

    int denominator = lhs.denominator * rhs.denominator;
    int numerator = lhs.numerator * rhs.numerator;

    return Frac(numerator, denominator);
}

const Frac operator/(const Frac& lhs, const Frac& rhs){

    return lhs * rhs.reciprocal();
}