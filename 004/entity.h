// name: entity.h
// author: amrzs
// date: 20140426

#ifndef ENTITY_H
#define ENTITY_H

#include <fstream>
#include <string>
#include <vector>

#include "date.h"

using namespace std;

typedef vector<string> Text;
typedef Text::iterator TextIter;


class Entity{

public:
    Entity(){};
    ~Entity(){};

private:
    Date date;
    Text content;

public:
    bool operator<(const Entity &x) const{
        
        return this->date < x.date;
    }

    bool operator==(const Entity &x) const{

        return this->date == x.date;
    }

    bool operator>(const Entity &x) const{

        return this->date > x.date;
    }

    string getStr() const{

        return date.getStr();
    }

    void setDate(const string &sDate){
        
        date = Date(sDate);
    }
    
    void addLine(const string &sLine){

        content.push_back(string(sLine));
    }

    void clear(){
        
        content.clear();
    }

    //friend istream& operator>>(istream &in, Entity&);
    friend ostream& operator<<(ostream &out, Entity&);
};

#endif // ENTITY_H
