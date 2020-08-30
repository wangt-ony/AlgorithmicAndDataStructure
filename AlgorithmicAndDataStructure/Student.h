#pragma once
#include<string>
#include<CppUnitTest.h>
class Student
{	
public:
	Student(__int64 id,int score) :Id(id),Score(score)
	{

	}
	
	__int64 Id;
	int Score;
};




bool operator==(const Student& student_1, const Student& student_2);
bool operator!=(const Student& student_1, const Student& student_2);
bool operator< (const Student& student_1, const Student& stduent_2);
bool operator> (const Student& student_1, const Student& stduent_2);