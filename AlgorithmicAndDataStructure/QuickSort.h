#pragma once
#include"InsertionSort.h"
template<typename T>
void printCall(T array[], int i, int j, int retract)
{
	std::string path = "C:\\Users\\wangt\\Desktop\\output.txt";
	std::ofstream outPut(path, std::ofstream::app);

	for (int i = 0; i <= retract; ++i)
		outPut << "--";
	outPut << "Call:QuickSort sort:";
	for (int k = i; k <= j; ++k)
		outPut << array[k] << ",";
	outPut << std::endl;
}

template<typename T>
void printReturn(T array[], int i, int j, int retract)
{
	std::string path = "C:\\Users\\wangt\\Desktop\\output.txt";
	std::ofstream outPut(path, std::ofstream::app);
	for (int i = 0; i <= retract; ++i)
		outPut << "--";
	outPut << "After:QuickSort sort:";
	for (int k = i; k <= j; ++k)
		outPut << array[k] << ",";
	outPut << std::endl;
}

template<typename T>
void printPartition(T array[], int i, int j,int p, int retract)
{
	std::string path = "C:\\Users\\wangt\\Desktop\\output.txt";
	std::ofstream outPut(path, std::ofstream::app);
	for (int i = 0; i <= retract; ++i)
		outPut << "--";
	outPut << "partitionIndex:"<<p<<":";
	for (int k = i; k <= j; ++k)
	{
		if (k == p)
			outPut << "(";
		outPut << array[k];
		if (k == p)
			outPut << ")";
		outPut << ",";
	}
	outPut << std::endl;
}

template<typename T>
void printPartition2(T array[], int i, int j, int lt,int gt,T partitionValue, int retract)
{
	std::string path = "C:\\Users\\wangt\\Desktop\\output.txt";
	std::ofstream outPut(path, std::ofstream::app);
	for (int i = 0; i <= retract; ++i)
		outPut << "--";
	outPut << "partitionValue:"<<partitionValue<<":";
	for (int k = i; k <= j; ++k)
	{
		if (k == lt||k==gt)
			outPut << "(";
		outPut << array[k];
		if (k == lt || k == gt)
			outPut << ")";
		outPut << ",";
	}
	outPut << std::endl;
}



template<typename T>
int partition(T array[], int left, int right)
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(left, right);
	int p = u(e);
	std::swap(array[left], array[p]);
	//以第一个元素作为分界元素
	T partitionValue = array[left];
	//用i记录当前遍历元素的索引
	int i = left + 1;
	//用j记录[left+1,i-1]中第一个大于分界元素的元素索引
	int j = left + 1;
	//依次遍历left+1至right中的所有元素	
	for (; i <= right; ++i)
	{
		//如果当前元素i小于分界元素
		if (array[i] <= partitionValue)
		{
			//则将当前元素i与第j个元素互换
			std::swap(array[j], array[i]);
			//更新j的值
			++j;
		}
		//更新当前处理元素的索引值i
	}
	//将第一个元素与第第j-1个元素交换
	std::swap(array[left], array[j - 1]);
	return j - 1;
}





template<typename T>
int partition2(T array[], int left, int right,int retract)
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(left, right);
	int p = u(e);
	std::swap(array[left], array[p]);
	//以第一个元素作为分界元素
	T partitionValue = array[left];
	//[left+1,i-1]中的元素均小于等于分界元素，i初始为left-1
	int i = left + 1;
	//[j+1,right]中的元素均大于等于分界元素，j初始化为right
	int j = right;
	//依次同时从头和尾向中心遍历所有元素，直到i大于等于j为止
	while (i <= j)
	{
		//从i元素开始依次向后遍历直到找到第一个大于等于分界元素的元素
		while (i <= j&&array[i] < partitionValue)
			++i;

		//从j元素开始依次向后遍历直到找到第一个小于等于分界元素的元素
		while (i <= j && array[j] > partitionValue)
			--j;
		if (i > j)
			break;
		//交换元素i与元素j
		std::swap(array[i], array[j]);
		//i向后挪一个位置
		++i;
		//j向前挪一个位置
		--j;
	}

	//交换left元素与j元素
	std::swap(array[left], array[j]);

	printPartition(array, left, right, j, retract);
	//返回j元素索引
	return j;
}

template<typename T>
std::pair<int,int> partition3(T array[], int left, int right, int retract)
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(left, right);
	int p = u(e);
	std::swap(array[left], array[p]);
	//以第一个元素作为分界元素
	T partitionValue = array[left];
	//[left+1,lt]中的元素均小于分界元素，lt初始为left
	int lt = left;
	//[gt,right]中的元素均大于分界元素，j初始化为right+1
	int gt = right+1;
	//[lt+1,i-1]中的元素均等于分界元素，i初始为left+1
	int i = left + 1;
	//依次同时从头和尾向中心遍历所有元素，直到i大于等于gt为止
	while (i<gt)
	{
		//如果array[i]<分界元素
		if (array[i] < partitionValue) {
			//将array[i]与array[lt+1]交换
			std::swap(array[i], array[lt + 1]);
			//更新lt位置，指向lt的后一个位置
			++lt;
			//更新i的位置，指向下一个元素
			++i;
		}
		//如果array[i]>分界元素
		else if (array[i] > partitionValue) {
			//将array[i]与array[gt]交换
			std::swap(array[i], array[gt-1]);
			//更新gt的位置，指向gt的前一个位置
			--gt;
		}
		//如果array[i]等于分界元素
		else {
			//i指向下一个未处理元素
			++i;
		}
	}
	//将left元素与lt+1元素或尾元素交换
	int swapIndex = min(lt, right);
	std::swap(array[left], array[swapIndex]);

	printPartition2(array, left, right, swapIndex-1,gt,partitionValue, retract);
	//返回lt元素及gt元素索引
	return std::pair<int,int>(swapIndex - 1,gt);
}


template<typename T>
void quickSort(T array[], int left, int right,int layer)
{
	printCall(array, left, right, layer);
	if (left >= right)
		return;
	/*if (right - left + 1 < 16)
	{
		InsertionSort(array, left, right);
		return;
	}*/
	std::pair<int,int>pair = partition3(array, left, right,layer);
	quickSort(array,left, pair.first,layer+1);
	quickSort(array, pair.second, right, layer + 1);

	printReturn(array, left, right, layer);
	
}

template<typename T>
void quickSort(T array[], int length)
{
	quickSort(array, 0, length - 1,1);
}



