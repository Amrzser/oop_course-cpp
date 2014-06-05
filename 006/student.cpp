// name: student.cpp
// author: Amrzs
// date: 2014/03/13

#include <iostream>
#include <vector>
#include <string>

#include "student.h"

using namespace std;


Student::Student(string name):
    name(name){
}

Student::~Student(){
}

int Student::getSumScore(){
    
    // int sum = 0, courseNum = courses.size();
    // for(int i = 0; i < courseNum; i++)
    //     sum += courses[i].score;

    int sum = 0;
    for(vector<Course>::iterator i = courses.begin(); i != courses.end(); ++i){
        sum += i->score;
    }
    
    return sum;
}

void Student::setCourse(string name, int score){

    Course course = {name, score};
    courses.push_back(course);
}

void Student::printSummary(){

    cout << "Name: " << name << '\t' << endl;
    cout << "Courses: ";

    // for(int i = 0; i < courses.size(); i++)    
    //     cout << courses[i].name << " " << courses[i].score << '\t';

    for(vector<Course>::iterator i = courses.begin(); i != courses.end(); ++i){
        cout << i->name << " " << i->score << '\t';
    }
    cout << "Sum: " << getSumScore() << '\t' << endl;
}
