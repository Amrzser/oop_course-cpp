/*
  Name: main.cpp
  Copyright: 
  Author: Amrzs
  Date: 27/02/14 08:23
  Description: the main program
*/

#include "student.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int STU_NUM = 10;	//the number of students

Student *stu[STU_NUM];

int main(){

	string name;
	int score[COURSE_NUM];
	int sumScore[COURSE_NUM], maxScore[COURSE_NUM], minScore[COURSE_NUM];

	//init arrays
	memset(sumScore, 0, COURSE_NUM * sizeof(sumScore[0]));
	memset(maxScore, 0, COURSE_NUM * sizeof(maxScore[0]));
	memset(minScore, 0xE, COURSE_NUM * sizeof(minScore[0]));

	//init the student array
	for(int i=0; i<STU_NUM; i++){
		cin >> name;
		for(int j=0; j<COURSE_NUM; j++)
			cin >> score[j];
		stu[i] = new Student(name, score);
	}
	
	//ouput the students' information
	cout << "no\t" << "name\t" << "score1\t" << "score2\t" << "score3\t" << "average\t" << endl;
	for(int i=0; i<STU_NUM; i++){
		cout << i+1 << "\t";
		cout << stu[i]->getName() << "\t";
		for(int j=0; j<COURSE_NUM; j++){
			score[j] = stu[i]->getScore(j);
			sumScore[j] += score[j];
			maxScore[j] = max(maxScore[j], score[j]);
			minScore[j] = min(minScore[j], score[j]);
			cout << score[j] << "\t";
		}
		cout << stu[i]->getAveScore() << endl;
		
		delete stu[i];	//free the memory
	}
	
	cout << "\t" << "average\t";
	for(int i=0; i<COURSE_NUM; i++){
		//printf("%.1f\t", (double)sumScore[i]/STU_NUM);	//can't make sure how to use cout
       cout << fixed << setprecision(1) << (double)sumScore[i]/STU_NUM << "\t"; 
   }
    cout << endl; 

	cout << "\t" << "min\t";
	for(int i=0; i<COURSE_NUM; i++)
		cout << minScore[i] << "\t";
	cout << endl;
	
	cout << "\t" << "max\t";
	for(int i=0; i<COURSE_NUM; i++)
		cout << maxScore[i] << "\t";
	cout << endl;

	return 0;
}
