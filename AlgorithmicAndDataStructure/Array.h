#pragma once
#include<stdexcept>
#include<algorithm>
template<typename T>
class Array
{
public:
	Array(size_t capacity_input = 10);
	~Array();
	T getFirst() { return operator[](0); }
	T getLast() { return operator[](size - 1); }
	void addLast(T element);
	void add(size_t index, T element);
	T& operator[](size_t index);
	const T& operator[](size_t index)const;
	bool contain(T element);
	int find(T element);
	T remove(size_t i);
	T removeFirst();
	T removeLast();
	void removeElement(T element);
	size_t getCapacity() { return capacity; }
	size_t getSize() { return size; }
	bool isEmpty() { return size == 0; }
private:
	void checkIndex(size_t index);
	void resize(int newCapacity);
	size_t capacity;
	size_t size;
	T* data;
};

template<typename T>
Array<T>::Array(size_t capacity_input) :capacity(capacity_input)
{
	data = new T[capacity_input];
	size = 0;
}

template<typename T>
Array<T>::~Array()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
}

template<typename T>
void Array<T>::addLast(T element)
{
	add(size, element);
}

template<typename T>
void Array<T>::add(size_t index, T element)
{
	if (size == capacity)
		resize(2 * capacity);
	if (index >size || index < 0)
		throw std::out_of_range("索引超出数组有效范围");
	for (size_t i = size ; i > index; --i)
	{
		data[i] = data[i-1];
	}
	data[index] = element;
	++size;
}

template<typename T>
void Array<T>::resize(int newCapacity)
{
	T* newData = new T[newCapacity];
	if (!newData)
		throw std::runtime_error("内存空间不足");
	std::copy(data, data+size, newData);
	delete[]data;
	data = newData;
	capacity = newCapacity;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	checkIndex(index);
	return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index)const
{
	checkIndex(index);
	return data[index];
}

template<typename T>
bool Array<T>::contain(T element)
{
	for (int i=0; i < size; ++i)
		if (data[i] == element)
			return true;
	
	return false;
}

template<typename T>
int Array<T>::find(T element)
{
	for (size_t i=0; i < size; ++i)
		if (data[i] == element)
			return i;

	return -1;
}

template<typename T>
T Array<T>::remove(size_t index)
{
	checkIndex(index);
	T removeElement = data[index];
	for (size_t i = index; i < size-1; ++i)
	{
		data[i] = data[i + 1];
	}
	--size;
	if (size == capacity / 4&&capacity/2!=0)
		resize(capacity / 2);
	return removeElement;
}

template<typename T>
T Array<T>::removeFirst()
{
	return remove(0);
}

template<typename T>
T Array<T>::removeLast()
{
	return remove(size-1);
}

template<typename T>
void Array<T>::removeElement(T element)
{
	size_t index = find(element);
	if (index < 0)
		return;
	remove(index);
}

template<typename T>
void Array<T>::checkIndex(size_t index)
{
	if (index >= size || index < 0)
		throw std::out_of_range("索引超出数组有效范围");
}