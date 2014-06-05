// name: student.h
// author: Amrzs
// date: 2014/03/13

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student{

private:
    string name;
    struct Course{
        string name;
        int score;
    };
    vector<Course> courses;

public:
    Student(string name);
    ~Student();
    
    int getSumScore();
    
    void setCourse(string name, int score);

    void printSummary();
};


#endif //STUDENT_H
