// name: date.h
// author: amrzs
// date: 20140426

#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date{

public:
    Date(){}; // do nothing
    Date(string);
    Date(int year, int month, int day);
    ~Date(){}

private:
    int year, month, day;

public:
    bool operator<(const Date &) const;
    bool operator==(const Date &) const;
    bool operator>(const Date &) const;

    string getStr() const{
        
        return to_string(year*10000 + month*100 + day); // C++11
    }

};

#endif //DATE_H
