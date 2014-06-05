// name: pdlist.cpp
// author: amrzs
// date: 20140427

#include <iostream>

#include "diary.h"

using namespace std;

int main(int argc, char* argv[]){

    if(argc < 3){

        cerr << "Please give the start date and end date." << endl;
        return 1;
    }

    Diary diary("diary.txt");
    string stDate(argv[1]), enDate(argv[2]);

    diary.listEntities(stDate, enDate);
    
    return 0;
}
