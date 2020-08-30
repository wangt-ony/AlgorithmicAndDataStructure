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
	//如果data数组已经填满数据，则将data数组容量库容为原来的两倍
	if (getSize() == capacity)
		resize(2 * capacity);
	//在队尾添加element数据
	data[tail] = element;
	//更新队列队尾位置
	tail = (tail + 1) % (capacity + 1);
}

template<typename T>
void Deque<T>::addFront(T element)
{
	//如果data数组已经填满数据，则将data数组容量库容为原来的两倍
	if (getSize() == capacity)
		resize(2 * capacity);
	
	//更新队列队首位置
	if (front == 0)
		front = capacity;
	else
		--front;
	//在队首添加element数据
	data[front] = element;
}

template<typename T>
T Deque<T>::removeFront()
{
	//判断队列是否为空
	if (isEmpty())
		throw new std::runtime_error("无法从空队列中请求元素出队！");
	//记录出队元素
	T element = data[front];
	//调整队首位置
	front = (front + 1) % (capacity + 1);
	//如果容量的1/4>0且队列元素数量小于等于容量的1/4，则将队列容积改为原来的一半
	if (getSize() <= capacity / 4 && capacity / 2 > 0)
		resize(capacity / 2);
	//返回出队元素
	return element;
}

template<typename T>
T Deque<T>::removeLast()
{
	//判断队列是否为空
	if (isEmpty())
		throw new std::runtime_error("无法从空队列中请求元素出队！");
	//调整队尾位置
	
	if (tail == 0)
		tail = capacity;
	else
		--tail;
	T element = data[tail];
	
	
	//如果容量的1/4>0且队列元素数量小于等于容量的1/4，则将队列容积改为原来的一半
	if (getSize() <= capacity / 4 && capacity / 2 > 0)
		resize(capacity / 2);
	//返回出队元素
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
	//分配一个大小为capacity_input+1的数组newData；
	T* newData = new T[capacity_new + 1];
	//从front起到tail-1为止依次遍历data，将数据依次放入newData的0至size-1的位置中。
	size_t size = getSize();
	for (size_t i = 0; i < size; ++i)
	{
		newData[i] = data[(front + i) % (capacity + 1)];
	}
	//清空data
	delete[] data;
	//将newData作为新的data数组
	data = newData;
	//更新容量属性
	capacity = capacity_new;
	//更新队首及队尾成员变量
	front = 0;
	tail = size;
}

