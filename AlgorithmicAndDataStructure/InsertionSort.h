#pragma once
//template<typename T>
//void InsertionSort(T array[], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		T currElement = array[i];
//		int j ;
//		for ( j= i; j > 0; --j)
//		{
//			if (array[j - 1] > currElement)
//				array[j] = array[j - 1];
//			else
//				break;
//		}
//		array[j] = currElement;
//	}
//}

template<typename T>
void InsertionSort(T array[], int size)
{
	for (int i = size-1; i>=0 ; --i)
	{
		T currElement = array[i];
		int j;
		for (j = i; j <size-1; ++j)
		{
			if (array[j + 1] < currElement)
				array[j] = array[j+ 1];
			else
				break;
		}
		array[j] = currElement;
	}
}