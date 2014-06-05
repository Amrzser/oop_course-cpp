// name: dvd.h
// author: amrzs
// date: 20140427

#ifndef DVD_H
#define DVD_H

#include <iostream>

#include "media.h"

using namespace std;

class Dvd : public Media{

public:
    Dvd(string title, string director, int filmLen):
        Media(title),
        director(director),
        filmLen(filmLen){
    }
    ~Dvd(){}

private:
    string director;
    int filmLen;

public:
    virtual void showPros(){

        cout << "DVD" << endl;
        cout << "Titile:\t" << getTitle() << endl;
        cout << "Director:\t" << director << endl;
        cout << "Length of film:\t" << filmLen << endl; 
    }

};

#endif // DVD_H
