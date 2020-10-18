#pragma once
#include<stdexcept>
template<typename T>
class LinkedList
{
public:
	LinkedList():size(0) { dummyHead = new Node(); }
	~LinkedList();
	void add(size_t index, T value);
	void addFirst(T value);
	void addLast(T value);
	void set(size_t index,T value);
	T get(size_t index);
	T remove(size_t index);
	T removeFirst();
	T removeLast();
	void removeElement(T element);
	size_t getSize() { return size; }
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
	void addRecur(Node* &head, size_t index, T value);
	T removeRecur(Node*& head, size_t index);
	void removeElementRecur(Node*& head, T element);
	Node* dummyHead;
	size_t size;
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node* curr = dummyHead;
	while (curr)
	{
		Node* next = curr->next;
		delete curr;
		curr = next;
	}
}

template<typename T>
void LinkedList<T>::add(size_t index, T value)
{
	if (index<0 || index>size)
		throw new std::runtime_error("索引超出有效范围！");
	/*Node* pre = dummyHead;
	for (size_t i = 0; i < index; ++i)
	{
		pre = pre->next;
	}
	pre->next = new Node(value, pre->next);*/
	++size;
	addRecur(dummyHead->next, index, value);
}

template<typename T>
void LinkedList<T>::addRecur(Node*& head, size_t index, T value)
{
	if (index == 0)
	{
		head = new Node(value, head);
		return;
	}
	addRecur(head->next, index - 1, value);
	
}

template<typename T>
void LinkedList<T>::addFirst(T value)
{
	add(0, value);
}

template<typename T>
void LinkedList<T>::addLast(T value)
{
	add(size, value);
}

template<typename T>
T LinkedList<T>::get(size_t index)
{
	if (index<0 || index>=size)
		throw new std::runtime_error("索引超出有效范围！");
	Node* curr = dummyHead->next;
	for (size_t i = 0; i < index; ++i)
	{
		curr = curr->next;
	}
	return curr->value;
}

template<typename T>
void LinkedList<T>::set(size_t index,T value)
{
	if (index < 0 || index >= size)
		throw new std::runtime_error("索引超出有效范围！");
	Node* curr = dummyHead->next;
	for (size_t i = 0; i < index; ++i)
	{
		curr = curr->next;
	}
	curr->value = value;
}

template<typename T>
T LinkedList<T>::remove(size_t index)
{
	if(size<=0)
		throw new std::runtime_error("链表为空！");
	if (index < 0 || index >= size)
		throw new std::runtime_error("索引超出有效范围！");
	/*Node* pre = dummyHead;
	for (size_t i = 0; i < index; ++i)
		pre = pre->next;
	Node* removeNode = pre->next;
	T removeValue = removeNode->value;
	pre->next = removeNode->next;
	--size;
	return removeValue;*/
	--size;
	return removeRecur(dummyHead->next, index);
}

template<typename T>
T LinkedList<T>::removeFirst()
{
	return remove(0);
}

template<typename T>
T LinkedList<T>::removeLast()
{
	return remove(size - 1);
}

template<typename T>
T LinkedList<T>::removeRecur(Node*& head, size_t index)
{
	T removeValue;
	if (index == 0) {
		removeValue = head->value;
		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;
		return removeValue;
	}
	return removeRecur(head->next, index - 1);
}

template<typename T>
void LinkedList<T>::removeElement(T element)
{
	removeElementRecur(dummyHead->next, element);
	--size;
}

template<typename T>
void LinkedList<T>::removeElementRecur(Node*& head, T element)
{
	if (head == nullptr)
		return;
	if (head->value == element)
	{
		Node* deleteNode = head;
		head = deleteNode->next;
		delete deleteNode;
		return;
	}
	removeElementRecur(head->next, element);
}

