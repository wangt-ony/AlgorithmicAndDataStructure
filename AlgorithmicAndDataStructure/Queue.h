#pragma once
#include<stdexcept>

template<typename T>
class Queue
{
public:
	virtual void enqueue(T element)=0;
	virtual T dequeue()=0;
	virtual T getFront()=0;
	virtual size_t getSize()=0;
	virtual bool isEmpty() =0;
};


template<typename T>
class LoopQueue:public Queue<T>
{
public:
 	LoopQueue(size_t capacity_input=2);
	~LoopQueue();
	virtual void enqueue(T element) override;;
	virtual T dequeue() override;;
	virtual T getFront() override;;
	virtual size_t getSize() override;;
	size_t getCapacity(); 
	virtual bool isEmpty() override { return front == tail; };
private:
	T* data;
	size_t capacity;
	void resize(size_t capacity);
	size_t front;
	size_t tail;
};

template<typename T>
size_t LoopQueue<T>::getCapacity()
{ return capacity; }

template<typename T>
LoopQueue<T>::LoopQueue(size_t capacity_input)
{
	data = new T[capacity_input + 1];
	capacity = capacity_input;
	tail = 0;
	front = 0;
}

template<typename T>
LoopQueue<T>::~LoopQueue()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
}


template<typename T>
T LoopQueue<T>::getFront()
{
	if(isEmpty())
		throw new std::runtime_error("队列为空，无法查看队首元素！");
	return data[front];
}

template<typename T>
void LoopQueue<T>::enqueue(T element)
{
	//如果data数组已经填满数据，则将data数组容量库容为原来的两倍
	if (getSize() == capacity)
		resize(2 * capacity);
	//在队尾添加element数据
	data[tail] = element;
	//更新队列队尾位置
	tail = (tail + 1) % (capacity+1);
}

template<typename T>
T LoopQueue<T>::dequeue()
{
	//判断队列是否为空
	if (isEmpty())
		throw new std::runtime_error("无法从空队列中请求元素出队！");
	//记录出队元素
	T element = getFront();
	//调整队首位置
	front = (front + 1) % (capacity + 1);
	//如果容量的1/4>0且队列元素数量小于等于容量的1/4，则将队列容积改为原来的一半
	if ( getSize() <= capacity / 4&& capacity / 2 > 0 )
		resize(capacity / 2);
	//返回出队元素
	return element;
}




template<typename T>
size_t LoopQueue<T>::getSize()
{
	if (front <= tail)
		return tail - front;
	else {
		size_t temp = front - tail;
		return capacity - temp+1;
	}
}

template<typename T>
void LoopQueue<T>::resize(size_t capacity_new)
{
	//分配一个大小为capacity_input+1的数组newData；
	T* newData = new T[capacity_new + 1];
	//从front起到tail-1为止依次遍历data，将数据依次放入newData的0至size-1的位置中。
	size_t size = getSize();
	for(size_t i=0;i<size;++i)
	{
		newData[i] = data[(front + i) % (capacity+1)];
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


template<typename T>
class LinkedListQueue :public Queue<T>
{
public:
	LinkedListQueue();
	~LinkedListQueue();
	void enqueue(T element) ;
	T dequeue();
	T getFront();
	size_t getSize() { return size; };
	bool isEmpty() { return head == nullptr; };
private:
	class Node
	{
	public:
		T value;
		Node* next;
		Node() :next(nullptr) {};
		Node(T value_input) :value(value_input), next(nullptr) {};
		Node(T value_input, Node* next_input) :value(value_input), next(next_input) {};
	};
	Node* head;
	Node* front;
	Node* tail;
	size_t size;
};

template<typename T>
LinkedListQueue<T>::LinkedListQueue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
LinkedListQueue<T>::~LinkedListQueue()
{
	Node* curr = head;
	while (curr)
	{
		Node* next = curr->next;
		delete curr;
		curr = next;
	}
}

template<typename T>
void LinkedListQueue<T>::enqueue(T element)
{
	if (tail == nullptr)
	{
		tail = new Node(element);
		head = tail;
	}
	else
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++size;

}

template<typename T>
T LinkedListQueue<T>::dequeue()
{
	if (!head)
		throw new std::runtime_error("队列为空");
	Node* next = head->next;
	T value = head->value;
	head = next;
	--size;
	return value;
}

template<typename T>
T LinkedListQueue<T>::getFront()
{
	if (!head)
		throw new std::runtime_error("队列为空");
	return head->value;
}