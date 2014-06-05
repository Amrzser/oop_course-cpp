// name:   norroom : Normal Room
// author: Amrzs
// date:   2014/05/11

#ifndef NORROOM_H
#define NORROOM_H

#include <iostream>
#include <string>

using std::cout;
using std::string;

#include "room.h"

class NorRoom : public Room {

public:
    NorRoom(string name, string type):
        Room(name),type(type){}
    virtual ~NorRoom(){}

private:
    string type; 

public:
    virtual void showInfo(vector<string> DIR) const {

        cout << endl;
        cout << "This is a " << type << " room" << endl;
        cout << "And called " << getName() << endl;

        for(vector<string>::iterator iter = DIR.begin(); iter != DIR.end(); iter++)
            if(existDoor(*iter))
                cout << *iter << "  ";
        cout << endl;
    }

    virtual bool isType(const string& sType) const {

        if(type == sType)
            return true;
        return false;
    }

};

#endif //NORROOM_H