#include"pch.h"
#include"Student.h"
bool operator==(const Student& student_1, const Student& student_2)
{
	if (&student_1 == &student_2)
		return true;
	return student_1.Score == student_2.Score;
}

bool operator!=(const Student& student_1, const Student& student_2)
{
	return !(student_1 == student_2);
}

bool operator< (const Student& student_1, const Student& student_2)
{
	return student_1.Score < student_2.Score;
}

bool operator> (const Student& student_1, const Student& student_2)
{
	return student_1.Score > student_2.Score;
}