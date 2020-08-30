#pragma once
#include"Array.h"
#include"LinkedList.h"
template<typename T>
class Stack
{
public:
	virtual void push(T element) = 0;
	virtual T pop() = 0;
	virtual T peek() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
};


template<typename T>
class ArrayStack :public Stack<T>
{
public:
	ArrayStack(size_t capacity) :array(capacity){}
	ArrayStack() {};
	void push(T element) override { array.addLast(element); }
	T pop() override { return array.removeLast(); }
	T peek()override { return array.getLast(); }
	int getSize()override { return array.getSize(); }
	bool isEmpty()override { return array.isEmpty(); }
private:
	Array<T> array;
};

template<typename T>
class LinkedListStack :public Stack<T>
{
public:
	LinkedListStack(){}
	void push(T element) override { list.addFirst(element); }
	T pop() override { return list.removeFirst(); }
	T peek()override { return list.get(0); }
	int getSize()override { return list.getSize(); }
	bool isEmpty()override { return list.getSize()==0; }
private:
	LinkedList<T> list;
};