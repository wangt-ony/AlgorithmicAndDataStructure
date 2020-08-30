#pragma once
#include<exception>
#include<iostream>
#include<Windows.h>
#include<string>
namespace UnitTest
{
	int* creatIntReverseArray(int size);
	int* creatRandomIntArray(int size);
}

template<typename T>
bool isSorted(T array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}

template<typename T>
void testSort(void sort(T[], int),T* array, int size)
{
	
	clock_t startTime = clock();
	sort(array, size);
	clock_t endTime = clock();
	double runTime = (endTime - startTime) / CLOCKS_PER_SEC;
	
	AllocConsole();
	std::cout << "数组长度:" << size<< ",运行时间：" << runTime<<std::endl;
	
}



