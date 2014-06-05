/*
  Name: student.cpp
  Copyright: 
  Author: Amrzs
  Date: 27/02/14 08:17
  Description: the function of student class
*/

#include "student.h"
#include <iostream>

using namespace std;

Student::Student(string name, int *score){

	this->name = name;
	for(int i=0; i<COURSE_NUM; i++)
		this->score[i] = score[i];	
}

string Student::getName(){
	
	return this->name;	
}

int Student::getScore(int k){
	
	if(k >= COURSE_NUM || k < 0){
		cout << "Dosen't exist this course!" << endl;
		return -1;
	}
	
	return this->score[k];
}

double Student::getAveScore(){

	double sum = 0;
	
	for(int i=0; i<COURSE_NUM; i++)
		sum += this->score[i];
		
	return sum/COURSE_NUM;	
}
