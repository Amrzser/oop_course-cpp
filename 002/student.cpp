// name: student.cpp
// author: Amrzs
// date: 2014/03/13

#include <iostream>
#include <string>

#include "student.h"

using namespace std;


Student::Student(string name):
    name(name){

}

Student::~Student(){

}

int Student::getSumScore(){
    
    int sum = 0, courseNum = courses.size();
    for(int i = 0; i < courseNum; i++)
        sum += courses[i].score;
    
    return sum;
}

void Student::setCourse(string name, int score){

    Course course;
    course.name = name;
    course.score = score;
    courses.push_back(course);        
}

void Student::printSummary(){

    cout << "Name: " << name << '\t' << endl;
    cout << "Courses: ";
    for(int i = 0; i < courses.size(); i++)    
        cout << courses[i].name << " " << courses[i].score << '\t';
    cout << "Sum: " << getSumScore() << '\t' << endl;
}
