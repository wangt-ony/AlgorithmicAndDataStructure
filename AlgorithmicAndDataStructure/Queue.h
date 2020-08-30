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
		throw new std::runtime_error("����Ϊ�գ��޷��鿴����Ԫ�أ�");
	return data[front];
}

template<typename T>
void LoopQueue<T>::enqueue(T element)
{
	//���data�����Ѿ��������ݣ���data������������Ϊԭ��������
	if (getSize() == capacity)
		resize(2 * capacity);
	//�ڶ�β���element����
	data[tail] = element;
	//���¶��ж�βλ��
	tail = (tail + 1) % (capacity+1);
}

template<typename T>
T LoopQueue<T>::dequeue()
{
	//�ж϶����Ƿ�Ϊ��
	if (isEmpty())
		throw new std::runtime_error("�޷��ӿն���������Ԫ�س��ӣ�");
	//��¼����Ԫ��
	T element = getFront();
	//��������λ��
	front = (front + 1) % (capacity + 1);
	//���������1/4>0�Ҷ���Ԫ������С�ڵ���������1/4���򽫶����ݻ���Ϊԭ����һ��
	if ( getSize() <= capacity / 4&& capacity / 2 > 0 )
		resize(capacity / 2);
	//���س���Ԫ��
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
	//����һ����СΪcapacity_input+1������newData��
	T* newData = new T[capacity_new + 1];
	//��front��tail-1Ϊֹ���α���data�����������η���newData��0��size-1��λ���С�
	size_t size = getSize();
	for(size_t i=0;i<size;++i)
	{
		newData[i] = data[(front + i) % (capacity+1)];
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
		throw new std::runtime_error("����Ϊ��");
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
		throw new std::runtime_error("����Ϊ��");
	return head->value;
}