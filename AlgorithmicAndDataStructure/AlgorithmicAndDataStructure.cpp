// AlgorithmicAndDataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"pch.h"
#include <iostream>
#include"MergeSort.h"
#include<random>
#include"BinarySearchTree.h"
int* createRandomIntArray(int size)
{
	int* array = new int[size];
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(0, size);
	for (int i = 0; i < size; ++i)
	{
		array[i] = u(e);
	}
	return array;
}


int main()
{
	
}

