// name:   room.h : the abstract room for inheritance
// author: Amrzs
// date:   2014/05/11

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;


typedef class Room* pRoom;
typedef map<string, pRoom> Door;

class Room {

public:
    Room(const string& name):
        name(name){

    }
    virtual ~Room(){}

private:
    string name;
    Door door;

public:
    string getName() const {

        return name;
    }

    void setDoor(const string& sDir, pRoom pRoom){

        door[sDir] = pRoom;
    }

    pRoom getDoor(const string& sDir) { //can't make it to be const

        if(!existDoor(sDir))
            return NULL;
        return door[sDir];
    }

    bool existDoor(const string& sDir) const {

        if(door.end() == door.find(sDir))
            return false;
        return true;
    }

    virtual void showInfo(vector<string>) const = 0;

    virtual bool isType(const string&) const = 0; //check princess or monster or lobby

};

#endif //ROOM_H