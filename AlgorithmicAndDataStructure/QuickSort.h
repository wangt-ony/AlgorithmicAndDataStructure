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
	//�Ե�һ��Ԫ����Ϊ�ֽ�Ԫ��
	T partitionValue = array[left];
	//��i��¼��ǰ����Ԫ�ص�����
	int i = left + 1;
	//��j��¼[left+1,i-1]�е�һ�����ڷֽ�Ԫ�ص�Ԫ������
	int j = left + 1;
	//���α���left+1��right�е�����Ԫ��	
	for (; i <= right; ++i)
	{
		//�����ǰԪ��iС�ڷֽ�Ԫ��
		if (array[i] <= partitionValue)
		{
			//�򽫵�ǰԪ��i���j��Ԫ�ػ���
			std::swap(array[j], array[i]);
			//����j��ֵ
			++j;
		}
		//���µ�ǰ����Ԫ�ص�����ֵi
	}
	//����һ��Ԫ����ڵ�j-1��Ԫ�ؽ���
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
	//�Ե�һ��Ԫ����Ϊ�ֽ�Ԫ��
	T partitionValue = array[left];
	//[left+1,i-1]�е�Ԫ�ؾ�С�ڵ��ڷֽ�Ԫ�أ�i��ʼΪleft-1
	int i = left + 1;
	//[j+1,right]�е�Ԫ�ؾ����ڵ��ڷֽ�Ԫ�أ�j��ʼ��Ϊright
	int j = right;
	//����ͬʱ��ͷ��β�����ı�������Ԫ�أ�ֱ��i���ڵ���jΪֹ
	while (i <= j)
	{
		//��iԪ�ؿ�ʼ����������ֱ���ҵ���һ�����ڵ��ڷֽ�Ԫ�ص�Ԫ��
		while (i <= j&&array[i] < partitionValue)
			++i;

		//��jԪ�ؿ�ʼ����������ֱ���ҵ���һ��С�ڵ��ڷֽ�Ԫ�ص�Ԫ��
		while (i <= j && array[j] > partitionValue)
			--j;
		if (i > j)
			break;
		//����Ԫ��i��Ԫ��j
		std::swap(array[i], array[j]);
		//i���Ųһ��λ��
		++i;
		//j��ǰŲһ��λ��
		--j;
	}

	//����leftԪ����jԪ��
	std::swap(array[left], array[j]);

	printPartition(array, left, right, j, retract);
	//����jԪ������
	return j;
}

template<typename T>
std::pair<int,int> partition3(T array[], int left, int right, int retract)
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(left, right);
	int p = u(e);
	std::swap(array[left], array[p]);
	//�Ե�һ��Ԫ����Ϊ�ֽ�Ԫ��
	T partitionValue = array[left];
	//[left+1,lt]�е�Ԫ�ؾ�С�ڷֽ�Ԫ�أ�lt��ʼΪleft
	int lt = left;
	//[gt,right]�е�Ԫ�ؾ����ڷֽ�Ԫ�أ�j��ʼ��Ϊright+1
	int gt = right+1;
	//[lt+1,i-1]�е�Ԫ�ؾ����ڷֽ�Ԫ�أ�i��ʼΪleft+1
	int i = left + 1;
	//����ͬʱ��ͷ��β�����ı�������Ԫ�أ�ֱ��i���ڵ���gtΪֹ
	while (i<gt)
	{
		//���array[i]<�ֽ�Ԫ��
		if (array[i] < partitionValue) {
			//��array[i]��array[lt+1]����
			std::swap(array[i], array[lt + 1]);
			//����ltλ�ã�ָ��lt�ĺ�һ��λ��
			++lt;
			//����i��λ�ã�ָ����һ��Ԫ��
			++i;
		}
		//���array[i]>�ֽ�Ԫ��
		else if (array[i] > partitionValue) {
			//��array[i]��array[gt]����
			std::swap(array[i], array[gt-1]);
			//����gt��λ�ã�ָ��gt��ǰһ��λ��
			--gt;
		}
		//���array[i]���ڷֽ�Ԫ��
		else {
			//iָ����һ��δ����Ԫ��
			++i;
		}
	}
	//��leftԪ����lt+1Ԫ�ػ�βԪ�ؽ���
	int swapIndex = min(lt, right);
	std::swap(array[left], array[swapIndex]);

	printPartition2(array, left, right, swapIndex-1,gt,partitionValue, retract);
	//����ltԪ�ؼ�gtԪ������
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



