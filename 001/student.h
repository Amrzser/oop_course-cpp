/*
  Name: student.h
  Copyright: 
  Author: Amrzs
  Date: 27/02/14 08:11
  Description: the defination of student class 
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

const int COURSE_NUM = 3;

class Student {
	
private:
	
	string name;
	int score[COURSE_NUM];
	
public:
	Student(string name, int *score);
	
	string getName();
	int getScore(int k); //get the kth course's score
	double getAveScore(); 	
	
};

#endif //STUDENT_H
