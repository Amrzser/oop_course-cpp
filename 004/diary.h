// name: diary.h
// author: amrzs
// date: 20140426

#ifndef DIARY_H
#define DIARY_H

#include <string>


#include "entity.h"

using namespace std;


typedef vector<Entity> Container;
typedef Container::iterator ConIter;

class Diary{

public:
    Diary(string filename);
    ~Diary();

private:
    string filename;
    Container entities;

    static const int LINE_MAX = 100;

    ConIter findEntity(string sDate);

public:
    void addEntity(string sDate); 
    void listEntities(string st, string en);    
    void showEntity(string sDate);    
    int removeEntity(string sDate);
};

#endif // DIARY_H
