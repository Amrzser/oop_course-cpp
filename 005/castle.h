// name:   castle.h
// author: Amrzs
// date:   2014/05/11

#ifndef CASTLE_H
#define CASTLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

#include "room.h"
#include "norroom.h"

typedef Room* pRoom; 
typedef vector<pRoom> pRoomCon;

class Castle {

public:
    // # locked, can't enter
    // - normal room 
    // $ princess room
    // * monster room
    // ^ lobbry room
    Castle(const string& name, const string& filename):
        name(name){

        int num = 0;
        string sLine;
        ifstream in(filename);
        in >> sLine;
        this->width = sLine.size();
        while(!in.eof()){
            for(int i = 0; i < sLine.size(); i++){
                string sType;
                switch(sLine[i]){
                    case '-':
                        sType = "normal";
                        break;
                    case '^':
                        sType = "lobbry";
                        break;
                    case '$':
                        sType = "princess";
                        break;
                    case '*':
                        sType = "monster";
                        break;
                    default:
                        sType = "locked";
                        break;
                }
                pRoom p = new NorRoom(to_string(num) + string("Room"), sType);
                rooms.push_back(p);

                if("lobbry" == sType)
                    pStRoom = p;

                num++;
            }

            this->height++;
            in >> sLine;
        }


        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++){
                num = i * width + j;

                pRoom p = rooms[num];
                if(p->isType("locked"))
                    continue;

                int num_re = num - width;
                if(num_re >= 0 && num_re < height*width){
                    pRoom q = rooms[num_re];
                    if(!q->isType("locked")){
                        p->setDoor("north", q);
                        q->setDoor("south", p);
                    }
                }

                num_re = num - 1;
                if(num_re >= 0 && num%width != 0){
                    pRoom q = rooms[num_re];
                    if(!q->isType("locked")){
                        p->setDoor("west", q);
                        q->setDoor("east", p);
                    }
                }
            }

        cout << "The castle came, game start." << endl;
    }

    virtual ~Castle(){

        for(pRoomCon::iterator i = rooms.begin(); i != rooms.end(); ++i){

            delete *i;
        }

        cout << "The castle disappered." << endl;
    }

private:
    string name;
    pRoomCon rooms;
    pRoom pStRoom;
    int height = 0, width = 0;

    static vector<string> DIR;

public:
    void run(){

        bool getPri; //get princess
        pRoom p = pStRoom;
        while(true){
            p->showInfo(DIR);

            if(p->isType("monster")){

                cout << "You die. Game over!" << endl;
                break;
            }else if(p->isType("princess")){

                if(!getPri){
                    getPri = true;
                    cout << "You get the princess. Come back" << endl;
                }
            }else if(p->isType("lobbry")){

                if(getPri){
                    cout << "You win!" << endl;
                    break;
                }
            }

            cout << ">>> ";
            string sCmd;
            cin >> sCmd;
            if(p->existDoor(sCmd))
                p = p->getDoor(sCmd);
            else
                cout << "You input a wrong direction." << endl;
        }
    }
};

vector<string> Castle::DIR = {
    "north", "south",
    "west", "east"
};

#endif //CASTLE_H