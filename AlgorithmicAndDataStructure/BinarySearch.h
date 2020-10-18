#pragma once

template<typename T>
int BinarySearch(T array[],int size ,T targe)
{
	return BinarySearch(array, 0, size - 1, targe);
}

template<typename T>
int BinarySearch(T array[],int left,int right, T target)
{
	if (left > right)
		return -1;
	int mid = left + (right - left) / 2;

	if (target > array[mid])
		BinarySearch(array, mid + 1, right, target);
	else if (target < array[mid])
		BinarySearch(array, left, mid - 1, target);
	else
		return array[mid];
}

template<typename T>
int BinarySearch_iteration(T array[], int size, T target)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (target < array[mid])
			right = mid - 1;
		else if (target > array[mid])
			left = mid + 1;
		else
			return array[mid];
	}
	return -1;
}