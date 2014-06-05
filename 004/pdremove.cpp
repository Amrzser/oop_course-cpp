// name: pdremove.cpp
// author: amrzs
// date: 20140427

#include <iostream>

#include "diary.h"

using namespace std;

int main(int argc, char* argv[]){

    if(1 == argc){

        cerr << "Please give the date." << endl;
        return -1;
    }

    Diary diary("diary.txt");
    string sDate(argv[1]);

    return diary.removeEntity(sDate); 
    
}
