#pragma once
#include<iostream>
#include<stack>
#include<utility>
#include<queue>
#include<exception>


template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree():root(nullptr),Size(0) {}
	~BinarySearchTree();
	int size() { return Size; }
	bool isEmpty() { return Size == 0; }
	void add(const T& element);
	bool contains(const T& element);
	std::vector<T> preOrder();
	std::vector<T> preOrderNR();
	std::vector<T> levelOrder();
	T maximum();
	T minimum();
	T removeMin();
	T removeMax();
	void remove(T element);
private:
	class Node;
	Node* removeMin(Node* node);
	Node* removeMax(Node* node);
	Node* maximum(Node* root);
	Node* minimum(Node* root);
	Node* remove(Node* root,T element);
	Node* add(const T& element, Node* root);
	bool contains(Node* root, const T& element);
	void preOrder(Node* root, std::vector<T>& outPut);
	void freeTree(Node* root);
	Node* root;
	int Size; 
};

template<typename T>
void BinarySearchTree<T>::freeTree(Node* root)
{
	if (root == nullptr)
		return;
	if (root->left!=nullptr) {
		freeTree(root->left);
		root->left = nullptr;
	}
	if (root->right != nullptr) {
		freeTree(root->right);
		root->right = nullptr;
	}
	delete root;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	HANDLE hLogFile;//声明日志文件句柄
	hLogFile = CreateFile(L"C:\\Users\\wangt\\Desktop\\output.log", GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);//创建日志文件
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);//将warn级别的内容都输出到文件（注意dump的
	//报告级别即为warning）
	_CrtSetReportFile(_CRT_WARN, hLogFile);//将日志文件设置为告警的输出文件
	
	
	freeTree(root);
	_CrtDumpMemoryLeaks();
}

template<typename T>
class BinarySearchTree<T>::Node
{
public:
	T element;
	Node* left;
	Node* right;
	Node(T e) :element(e), left(nullptr), right(nullptr) {}
};

template<typename T>
void BinarySearchTree<T>::add(const T& element)
{
	root = add(element, root);
	++Size;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::add(const T& element, Node* root)
{
	if (root == nullptr)
	{
		Node* nodePtr = new Node(element);
		return nodePtr;
	}
	else if (root->element > element)
		root->left = add(element, root->left);
	else if (root->element < element)
		root->right = add(element, root->right);
	return root;
}

template<typename T>
bool BinarySearchTree<T>::contains(const T& element)
{
	return contains(root, element);
}

template<typename T>
bool BinarySearchTree<T>::contains(Node* root, const T& element)
{
	if (root == nullptr)
		return false;
	if (root->element == element)
		return true;
	else if (root->element < element)
		return contains(root->right, element);
	else
		return contains(root->left, element);
}

template<typename T>
std::vector<T>  BinarySearchTree<T>::preOrder()
{
	std::vector<T>output;
	preOrder(root, output);
	return output;
}

template<typename T>
void BinarySearchTree<T>::preOrder(Node* root,std::vector<T>& outPut)
{
	if (root == nullptr)
		return;
	outPut.push_back(root->element);
	preOrder(root->left, outPut);
	preOrder(root->right, outPut);
}

template<typename T>
std::vector<T> BinarySearchTree<T>::preOrderNR()
{
	std::vector<T>outputs;
	std::stack<std::pair<Node*,int>>stack;
	stack.push(std::make_pair(root, 1));

	while (!stack.empty())
	{
		std::pair<Node*, int>pair=	stack.top();
		stack.pop();
		if (pair.first == nullptr)
			continue;
		switch (pair.second)
		{
		case 1:
			outputs.push_back(pair.first->element);
			++pair.second;
			stack.push(pair);
			if(pair.first->left!=nullptr)
				stack.push(std::make_pair(pair.first->left, 1));
			break;
		case 2:
			++pair.second;
			stack.push(pair);
			if (pair.first->right != nullptr)
				stack.push(std::make_pair(pair.first->right, 1));
			break;
		default:
			break;
		}
	}
	return outputs;
}

template<typename T>
std::vector<T> BinarySearchTree<T>::levelOrder()
{
	std::vector<T>outPuts;
	std::queue<Node*>queue;
	queue.push(root);
	while (!queue.empty())
	{
		Node* currentNode = queue.front();
		queue.pop();
		outPuts.push_back(currentNode->element);
		if (currentNode->left != nullptr)
			queue.push(currentNode->left);
		if(currentNode->right!=nullptr)
			queue.push(currentNode->right);
	}
	return outPuts;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::maximum(Node* root)
{
	if (root->right == nullptr)
		return root;
	return maximum(root->right);
}


template<typename T>
T BinarySearchTree<T>::maximum()
{
	if (root == nullptr)
		throw std::runtime_error("");
	Node* node= maximum(root);
	if(node==nullptr)
		throw std::runtime_error("");
	return node->element;
}

template<typename T>
T BinarySearchTree<T>::minimum()
{
	if (root == nullptr)
		throw std::runtime_error("");
	Node* node = minimum(root);
	if (node == nullptr)
		throw std::runtime_error("");
	return node->element;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::minimum(Node* root)
{
	if (root->left == nullptr)
		return root;
	return minimum(root->left);
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::removeMin(Node* node)
{
	if (node->left == nullptr) {
		Node* newRoot = node->right;
		delete node;
		node = newRoot;
		--Size;
	}
	else
		node->left = removeMin(node->left);
	return node;
}

template<typename T>
T BinarySearchTree<T>::removeMin()
{
	T element = minimum();
	if (root == nullptr)
		throw std::runtime_error("");
	root= removeMin(root);
	return element;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::removeMax(Node* node)
{
	if (node->right == nullptr)
	{
		Node* newRoot = node->left;
		delete node;
		node = newRoot;
		--Size;
	}
	else
		node->right = removeMax(node->right);
	return node;
}

template<typename T>
T BinarySearchTree<T>::removeMax()
{
	T element = maximum();
	if (root == nullptr)
		throw std::runtime_error("");
	root=removeMax(root);
	return element;
}

template<typename T>
void BinarySearchTree<T>::remove(T element)
{
	
	if (root == nullptr)
		throw std::runtime_error("");
	root=remove(root, element);
	
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove(Node* root, T element)
{
	if (root == nullptr)
		return nullptr;
	if (root->element == element)
	{
		Node* oldRoot = root;
		if (root->left == nullptr)
			root = root->right;
		else if (root->right == nullptr)
			root = root->left;
		else
		{
			root = new Node(minimum(root->right)->element);
			root->right = removeMin(oldRoot->right);
			root->left = oldRoot->left;
		}
		delete oldRoot;
	}
	else if (root->element < element)
		root->left = remove(root->left, element);
	else if(root->element > element)
		root->right = remove(root->right, element);

	return root;
}