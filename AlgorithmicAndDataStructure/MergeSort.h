#pragma once
#include<algorithm>
#include<math.h>
#include<fstream>
#include"InsertionSort.h"
template<typename T>
void copy(T* array,size_t i,size_t j,T* newArray)
{
	for (size_t k = i; k < j; ++k)
	{
		newArray[k] = array[k];
	}
}

template<typename T>
void merge(T array[], size_t i,size_t mid, size_t j,T tempArray[])
{
	copy(array, i, j, tempArray);
	size_t a = i, b = mid;
	for (size_t k = i; k < j; ++k)
	{
		if (a>= mid)
		{
			array[k] = tempArray[b];
			++b;
		}
		else if (b >= j)
		{
			array[k] = tempArray[a];
			++a;
		}
		else if (tempArray[a] <= tempArray[b])
		{
			array[k] = tempArray[a];
			++a;
		}
		else
		{
			array[k] = tempArray[b];
			++b;
		}
		
	}
}



template<typename T>
void mergeSort(T array[], size_t i, size_t j,T tempArray[])
{
	if (i >= j-1)
		return;
	size_t mid = i + (j - i-1) / 2;
	mergeSort(array, i, mid+1, tempArray);
	mergeSort(array, mid + 1, j, tempArray);
	merge(array, i, mid+1, j, tempArray);
}

template<typename T>
void mergeSort(T array[],size_t n)
{
	T* tempArray = new T[n];
	mergeSort(array, 0, n, tempArray);
	delete[] tempArray;
}
template<typename T>
void print(T array[], size_t length)
{
	std::string path = "C:\\Users\\wangt\\Desktop\\output.txt";
	std::ofstream outPut(path,std::ofstream::app);
	for (size_t i = 0; i < length; ++i)
		outPut << array[i] << ",";
	outPut << std::endl;
}

template<typename T>
void InsertionSort(T array[], size_t left,size_t right)
{
	for (int i = left+1; i <= right; ++i)
	{
		T currElement = array[i];
		int j ;
		for ( j= i; j > left; --j)
		{
			if (array[j - 1] > currElement)
				array[j] = array[j - 1];
			else
				break;
		}
		array[j] = currElement;
	}
}
template<typename T>
void mergeSort_downToUp(T array[], size_t length)
{
	//初始化当前处理的数据量n为1
	T* tempArray = new T[length];
	for (size_t i = 0; i  < length; i += 16)
	{
		InsertionSort(array, i, min(i +15, length - 1));
	}
	size_t n = 16;
	//依次遍历合并区间长度n，直到n大于等于数组长度length
	while (n<length)
	{
		//依次合并区间[i,i+n-1]及区间[i+n,min(i+2*n-1,length-1)]
		for (size_t i = 0; i+n<length; i+=2*n)
		{
			size_t midElementIndex = i + n - 1;
			size_t lastElementIndex = min(i + 2 * n - 1, length - 1);
			if(array[midElementIndex]>array[midElementIndex+1])
				merge(array, i, midElementIndex, lastElementIndex, tempArray);
		}
	//更新当前处理数据量。
		n = 2 * n;
	}
	delete[] tempArray;
}