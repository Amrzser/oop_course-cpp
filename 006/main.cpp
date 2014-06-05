// name: main.cpp
// author: Amrzs
// date: 2014/03/13

#include <iostream>
#include <string>
#include <vector>

#include "student.h"

using namespace std;

int main(){

    vector<Student*> stuVec;
    Student *pStu = NULL;

    string name;
    int score;

    while(true){
        cout << "Please input a student name, " 
            << "if you want to quit, input quit" << endl;
        
        cin >> name;
        if("quit" == name)
            break;
        pStu = new Student(name);
        
        cout << "Please input courses' name and score, "
            << "if end then input 0 0" << endl;

        cin >> name >> score;
        while(name != "0"){
            pStu->setCourse(name, score);
            cin >> name >> score;
        }

        stuVec.push_back(pStu);
    }

    for(int i = 0; i < stuVec.size(); i++){
        stuVec[i]->printSummary();
        delete stuVec[i];
    }
    
    return 0;
}
