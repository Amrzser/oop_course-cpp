// name: diary.cpp
// author: 20140427
// date: 20140426

#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctype.h>

#include "diary.h"

using namespace std;


bool isDate(string sDate){

    if(8 != sDate.size())
        return false;
    
    for(string::iterator iter = sDate.begin(); iter != sDate.end(); iter++){

        if(!isdigit(*iter))
            return false;
    }

    //to do ... more checking

    return true;    
}

Diary::Diary(string filename):
    filename(filename){

    ifstream fin(filename, ios::in);
    
    if(fin.fail()){

        cout << filename << " dosen't exist, a new one will be created." << endl;
        return;
    }

    if(fin.bad()){  //a factal error
        
        cerr << "Reading diary error!" << endl;
        return; 
    }

    Entity entity;
    char buf[LINE_MAX+1];

    fin.getline(buf, LINE_MAX);
    string sLine(buf);
    entity.setDate(sLine);

    while(!fin.eof()){

        fin.getline(buf, LINE_MAX);
        sLine = string(buf);
        if("" == sLine)
            continue;
        if(isDate(sLine)){
            
            entities.push_back(entity);                    
            
            entity.clear();
            entity.setDate(sLine);
        }else{
            entity.addLine(sLine);
        }
    }
    entities.push_back(entity);

    fin.close();

    cout << "...Old diaries have loaded." << endl;
}


Diary::~Diary(){

    ofstream fout(filename, ios::out);
    
    if(fout.bad()){
        
        cerr << "Writing diary error!" << endl;
        return;
    }

    sort(entities.begin(), entities.end());

    for(ConIter iter = entities.begin(); iter != entities.end(); iter++){

        fout << (*iter);
    }

    cout << "...Diaries have been saved." << endl;
}


ConIter Diary::findEntity(string sDate){

    for(ConIter iter = entities.begin(); iter != entities.end(); iter++){

        if(sDate == iter->getStr())
            return iter;
    }

    return entities.end();
}

void Diary::addEntity(string sDate){

    ConIter iter = findEntity(sDate);
    if(entities.end() == iter){
        
        Entity entity;
        entity.setDate(sDate);
        entities.push_back(entity); 
        iter = entities.end() - 1;
    }
    iter->clear();
    // iter is the new entity iterator

    char buf[LINE_MAX+1];

    while(!cin.eof()){

        cout << ">>> ";
        cin.getline(buf, LINE_MAX);
        string sLine(buf);
        if("."==sLine)
            break;  //end of entity

        iter->addLine(sLine);
    }
}

void Diary::listEntities(string st, string en){

    Date stDate(st), enDate(en);
    //start and end date

    sort(entities.begin(), entities.end());

    for(ConIter iter = entities.begin(); iter != entities.end(); iter++){

        Date nDate(iter->getStr());
        if(((nDate>stDate) && (nDate<enDate)) || (nDate==stDate) || (nDate==enDate))
             cout << iter->getStr() << endl;
    }
}

void Diary::showEntity(string sDate){

    ConIter iter = findEntity(sDate);

    if(entities.end() == iter){

        cerr << "There isn't a " << sDate << " entity." << endl;
        return;
    }

    cout << (*iter);
}

int Diary::removeEntity(string sDate){

    ConIter iter = findEntity(sDate);

    if(entities.end() == iter){

        cerr << "There isn't a " << sDate << " entity." << endl;
        return -1;
    }

    *iter = *(entities.end() - 1);
    entities.pop_back();
    
    cout << "Entity removed." << endl;
    
    return 0;
}

