#pragma once

template<typename T>
int linearSearch(T array[], int size, T aimObject)
{
	if (array == nullptr || size <= 0)
		return -1;

	for (int i = 0; i < size; ++i)
	{
		if (array[i] == aimObject)
			return i;
	}
	return -1;
}

