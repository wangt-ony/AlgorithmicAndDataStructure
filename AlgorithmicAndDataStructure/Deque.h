#pragma once
#pragma once
#include<stdexcept>
#include<ostream>

template<typename T>
class Deque
{
public:
	Deque(size_t capacity_input = 2);
	~Deque();
	void addFront(T element);
	void addLast(T element);
	T removeFront();
	T removeLast();
	size_t getSize();
	size_t getCapacity() { return capacity; };
	bool isEmpty() { return front == tail; };
private:
	T* data;
	size_t capacity;
	void resize(size_t capacity);
	size_t front;
	size_t tail;
};

template<typename T>
Deque<T>::Deque(size_t capacity_input)
{
	data = new T[capacity_input + 1];
	capacity = capacity_input;
	tail = 0;
	front = 0;
}

template<typename T>
Deque<T>::~Deque()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
}

template<typename T>
void Deque<T>::addLast(T element)
{
	//���data�����Ѿ��������ݣ���data������������Ϊԭ��������
	if (getSize() == capacity)
		resize(2 * capacity);
	//�ڶ�β���element����
	data[tail] = element;
	//���¶��ж�βλ��
	tail = (tail + 1) % (capacity + 1);
}

template<typename T>
void Deque<T>::addFront(T element)
{
	//���data�����Ѿ��������ݣ���data������������Ϊԭ��������
	if (getSize() == capacity)
		resize(2 * capacity);
	
	//���¶��ж���λ��
	if (front == 0)
		front = capacity;
	else
		--front;
	//�ڶ������element����
	data[front] = element;
}

template<typename T>
T Deque<T>::removeFront()
{
	//�ж϶����Ƿ�Ϊ��
	if (isEmpty())
		throw new std::runtime_error("�޷��ӿն���������Ԫ�س��ӣ�");
	//��¼����Ԫ��
	T element = data[front];
	//��������λ��
	front = (front + 1) % (capacity + 1);
	//���������1/4>0�Ҷ���Ԫ������С�ڵ���������1/4���򽫶����ݻ���Ϊԭ����һ��
	if (getSize() <= capacity / 4 && capacity / 2 > 0)
		resize(capacity / 2);
	//���س���Ԫ��
	return element;
}

template<typename T>
T Deque<T>::removeLast()
{
	//�ж϶����Ƿ�Ϊ��
	if (isEmpty())
		throw new std::runtime_error("�޷��ӿն���������Ԫ�س��ӣ�");
	//������βλ��
	
	if (tail == 0)
		tail = capacity;
	else
		--tail;
	T element = data[tail];
	
	
	//���������1/4>0�Ҷ���Ԫ������С�ڵ���������1/4���򽫶����ݻ���Ϊԭ����һ��
	if (getSize() <= capacity / 4 && capacity / 2 > 0)
		resize(capacity / 2);
	//���س���Ԫ��
	return element;
}



template<typename T>
size_t Deque<T>::getSize()
{
	if (front <= tail)
		return tail - front;
	else {
		size_t temp = front - tail;
		return capacity - temp + 1;
	}
}

template<typename T>
void Deque<T>::resize(size_t capacity_new)
{
	//����һ����СΪcapacity_input+1������newData��
	T* newData = new T[capacity_new + 1];
	//��front��tail-1Ϊֹ���α���data�����������η���newData��0��size-1��λ���С�
	size_t size = getSize();
	for (size_t i = 0; i < size; ++i)
	{
		newData[i] = data[(front + i) % (capacity + 1)];
	}
	//���data
	delete[] data;
	//��newData��Ϊ�µ�data����
	data = newData;
	//������������
	capacity = capacity_new;
	//���¶��׼���β��Ա����
	front = 0;
	tail = size;
}

