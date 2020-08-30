#pragma once
//template<typename T>
//void SelectionSort(T array[], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		for (int j = i; j < size-1; ++j)
//		{
//			if (array[i] > array[j + 1])
//				std::swap(array[i], array[j + 1]);
//		}
//	}
//}

template<typename T>
void SelectionSort(T array[], int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (array[j + 1] < array[j])
				std::swap(array[j + 1], array[j]);
		}
	}
}