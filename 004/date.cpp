// name: date.cpp
// author: amrzs
// date: 20140426

#include <iostream>
#include <cstdlib>

#include "date.h"

using namespace std;

Date::Date(string sDate){

    //int iDate = atoi(sDate.c_str());
    int iDate = stoi(sDate); // C++11
    
    day = iDate % 100;
    iDate /= 100;
    
    month = iDate % 100;
    iDate /= 100;

    year = iDate;
}

Date::Date(int year, int month, int day):
    year(year), month(month), day(day){

}

bool Date::operator<(const Date &x) const{

    if(year < x.year)
        return true;
    else if(year > x.year)
        return false;

    if(month < x.month)
        return true;
    else if(month > x.month)
        return false;

    if(day < x.day)
        return true;
    else 
        return false;
}

bool Date::operator==(const Date &x) const{

    return (year==x.year) && (month==x.month) && (day==x.day);
}

bool Date::operator>(const Date &x) const{

    return !((*this<x) || (*this==x));
}

