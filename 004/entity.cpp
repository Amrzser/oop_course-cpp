// name: entity.cpp
// author: amrzs
// date: 20140426

#include <iostream>
#include <fstream>

#include "entity.h"

using namespace std;

/* it seems doesn't need
istream& operator>>(istream &in, Entity &x){

    string sDate;
    in >> sDate;
    date = Date(sDate);

    string sLine;
    in >> sLine
}*/

ostream& operator<<(ostream &out, Entity &obj){

    out << obj.date.getStr() << endl;
    
    for(TextIter iter = obj.content.begin(); iter != obj.content.end(); iter++){

        out << (*iter) << endl; 
    }
    
    return out;
}


