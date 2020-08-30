#include "pch.h"
#include <CppUnitTest.h>
#include<random>
#include<time.h>
#include"unitTest.h"
#include"LinearSearch.h"
#include"SelectionSort.h"
#include"InsertionSort.h"
#include"Student.h"
#include"Array.h"
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"LinkedList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(LinearSearchTest)
	{
	public:

		TEST_METHOD(NormalLinearSearchTest)
		{
			int array[] = { 24,18,12,9,16,66,32,4 };
			int aimNumber = 16;
			int aimIndex = 4;
			int sizeOfArray = 8;

			int index = linearSearch(array, sizeOfArray, aimNumber);

			Assert::AreEqual(aimIndex, index);
			

		}

		TEST_METHOD(FaliLinearSearchTest)
		{
			int array[] = { 24,18,12,9,16,66,32,4 };
			int aimNumber = 666;
			int aimIndex = -1;
			int sizeOfArray = 8;

			int index = linearSearch(array, sizeOfArray, aimNumber);

			Assert::AreEqual(aimIndex, index);

		}

		TEST_METHOD(studentLinearTest)
		{
			Student array[] = { Student(1,98),Student(2,60),Student(3,70) };
			Student aimStudent(3, 70);
			int aimIndex = 2;
			int sizeOfArray = 3;

			int index = linearSearch(array, sizeOfArray, aimStudent);

			Assert::AreEqual(aimIndex, index);

		}

		TEST_METHOD(runTimeTest)
		{
			int array[] = { 24,18,12,9,16,66,32,4 };
			int aimNumber = 666;
			int aimIndex = -1;
			int sizeOfArray = 8;

			int index = linearSearch(array, sizeOfArray, aimNumber);

			Assert::AreEqual(aimIndex, index);

		}
	};

	TEST_CLASS(selectSortTest)
	{
		TEST_METHOD(randamIntTest)
		{
			int size =10000;
			int* array = creatRandomIntArray(size);
			
			testSort(SelectionSort, array, size);
			
			for (int i = 0; i < size-1; ++i)
			{
				Assert::IsTrue(array[i]<=array[i+1]);
			}

			delete[] array;
		}

		TEST_METHOD(StudentSortTest)
		{
			int size = 3;
			Student array[] = {Student(1,66),Student(2,100),Student(3,98)};

			Student aimArray[] = { Student(1,66),Student(3,98),Student(2,100) };

			SelectionSort(array, size);


			for (int i = 0; i < size-1; ++i)
			{
				Assert::IsTrue(array[i].Score<=array[i+1].Score);
			}
		}
	};

	TEST_CLASS(insertSortTest)
	{
		TEST_METHOD(randamIntTest)
		{
			int size = 10000;
			int* array = creatRandomIntArray(size);

			testSort(InsertionSort, array, size);

			for (int i = 0; i < size - 1; ++i)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}

			delete[] array;
		}

		TEST_METHOD(StudentSortTest)
		{
			int size = 3;
			Student array[] = { Student(1,66),Student(2,100),Student(3,98) };

			Student aimArray[] = { Student(1,66),Student(3,98),Student(2,100) };

			InsertionSort(array, size);


			for (int i = 0; i < size - 1; ++i)
			{
				Assert::IsTrue(array[i].Score <= array[i + 1].Score);
			}
		}
	};

	TEST_CLASS(ArrayTest)
	{
		TEST_METHOD(addLastTest)
		{
			Array<int> array(2);
			for (int i = 0; i < 10; ++i)
				array.addLast(i);

			for (int i = 0; i < 10; ++i)
				Assert::AreEqual(i, array[i]);
		}

		TEST_METHOD(addTest)
		{
			Array<int> array(2);
			for (int i = 0; i < 10; ++i)
				array.addLast(i);

			array.add(3, 10);

			Assert::AreEqual(10, array[3]);
		}

		TEST_METHOD(findTest)
		{
			Array<int> array(2);
			for (int i = 0; i < 10; ++i)
				array.addLast(i);

			int i = array.find(5);

			Assert::AreEqual(5, i);
		}

		TEST_METHOD(removeTest)
		{
			Array<int> array(2);
			for (size_t i = 0; i < 10; ++i)
				array.addLast(i);

			for(size_t index=9;index>3;--index)
				int removeElement = array.remove(index);

			for (size_t i = 0; i < 4; ++i)
			{
				Assert::AreEqual((int)i, array[i]);
			}
			Assert::AreEqual((size_t)8, array.getCapacity());
		}

		TEST_METHOD(removeExceptionTest)
		{
			
			auto f = [] {
				Array<int> array(2);
				for (size_t i = 0; i < 10; ++i)
					array.addLast(i);
				array.remove(-1);
			};

			Assert::ExpectException<std::out_of_range>(f);
		}
	};

	TEST_CLASS(ArrayStackTest)
	{
		TEST_METHOD(stackTest)
		{
			ArrayStack<int> stack;
			for (int i = 0; i < 10; ++i)
				stack.push(i);
			Assert::AreEqual(9, stack.peek());
			Assert::AreEqual(10, stack.getSize());
			for (int i = 9; i >= 0; --i)
			{
				Assert::AreEqual(i, stack.pop());
			}
			Assert::IsTrue(stack.isEmpty());
		}
	};

	TEST_CLASS(LinkedListStackTest)
	{
		TEST_METHOD(stackTest)
		{
			LinkedListStack<int> stack;
			for (int i = 0; i < 10; ++i)
				stack.push(i);
			Assert::AreEqual(9, stack.peek());
			Assert::AreEqual(10, stack.getSize());
			for (int i = 9; i >= 0; --i)
			{
				Assert::AreEqual(i, stack.pop());
			}
			Assert::IsTrue(stack.isEmpty());
		}
	};


	TEST_CLASS(QueueTest)
	{
		TEST_METHOD(loopQueueTest)
		{
			LoopQueue<int>queue;
			for (int i = 0; i < 10; ++i)
				queue.enqueue(i);

			for (int i = 0; i < 5; ++i)
				Assert::AreEqual(i, queue.dequeue());

			Assert::AreEqual((size_t)5, queue.getSize());

			Assert::AreEqual((size_t)16, queue.getCapacity());

			for (int i = 10; i <= 20; ++i)
				queue.enqueue(i);
			Assert::AreEqual((size_t)16, queue.getSize());
			Assert::AreEqual((size_t)16, queue.getCapacity());

			for (int i = 5; i <= 20; ++i)
				Assert::AreEqual(i, queue.dequeue());
		}

		TEST_METHOD(LinedListQueueTest)
		{
			LinkedListQueue<int>queue;
			for (int i = 0; i < 10; ++i)
				queue.enqueue(i);

			for (int i = 0; i < 5; ++i)
				Assert::AreEqual(i, queue.dequeue());

			Assert::AreEqual((size_t)5, queue.getSize());

			for (int i = 10; i <= 20; ++i)
				queue.enqueue(i);
			Assert::AreEqual((size_t)16, queue.getSize());

			for (int i = 5; i <= 20; ++i)
				Assert::AreEqual(i, queue.dequeue());
		}
	};


	TEST_CLASS(DequeTest)
	{
		TEST_METHOD(addFrontTest)
		{
			Deque<int>deque;
			for (int i = 0; i < 10; ++i)
				deque.addFront(i);
			Assert::AreEqual((size_t)10, deque.getSize());
			Assert::AreEqual((size_t)16, deque.getCapacity());

			for (int i = 9; i >= 0; --i)
				Assert::AreEqual(i, deque.removeFront());

			Assert::AreEqual((size_t)0, deque.getSize());
			Assert::AreEqual((size_t)1, deque.getCapacity());
		}

		TEST_METHOD(addLastTest)
		{
			Deque<int>deque;
			for (int i = 0; i < 10; ++i)
				deque.addLast(i);
			Assert::AreEqual((size_t)10, deque.getSize());
			Assert::AreEqual((size_t)16, deque.getCapacity());

			for (int i = 9; i >= 0; --i)
				Assert::AreEqual(i, deque.removeLast());

			Assert::AreEqual((size_t)0, deque.getSize());
			Assert::AreEqual((size_t)1, deque.getCapacity());
		}

		TEST_METHOD(MixTest)
		{
			Deque<int>deque;
			for (int i = 5; i <10; ++i)
				deque.addLast(i);
			Assert::AreEqual((size_t)5, deque.getSize());
			Assert::AreEqual((size_t)8, deque.getCapacity());
			for (int i = 4; i >=0; --i)
				deque.addFront(i);
			Assert::AreEqual((size_t)10, deque.getSize());
			Assert::AreEqual((size_t)16, deque.getCapacity());

			for (int i = 0; i <5; ++i)
				Assert::AreEqual(i, deque.removeFront());
			Assert::AreEqual((size_t)5, deque.getSize());
			Assert::AreEqual((size_t)16, deque.getCapacity());

			for (int i = 10; i < 15; ++i)
				deque.addLast(i);
			Assert::AreEqual((size_t)10, deque.getSize());
			Assert::AreEqual((size_t)16, deque.getCapacity());

			for (int i = 14; i >= 5; --i)
				Assert::AreEqual(i, deque.removeLast());
			Assert::AreEqual((size_t)0, deque.getSize());
			Assert::AreEqual((size_t)1, deque.getCapacity());
		}
	};



	TEST_CLASS(LinkedListTest)
	{
		TEST_METHOD(AddTest)
		{
			LinkedList<int>list;
			for (int i = 0; i < 10; ++i)
				list.add(i, i);

			for (int i = 0; i < 10; ++i)
				Assert::AreEqual(i, list.get(i));
		}

		TEST_METHOD(RemoveTest)
		{
			LinkedList<int>list;
			for (int i = 0; i < 10; ++i)
				list.add(i, i);

			list.remove(5);

			for (int i = 0; i < 5; ++i)
				Assert::AreEqual(i, list.get(i));
			for (int i = 5; i < 9; ++i)
				Assert::AreEqual(i+1, list.get(i));
		}

		TEST_METHOD(SetTest)
		{
			LinkedList<int>list;
			for (int i = 0; i < 10; ++i)
				list.add(i, i);

			list.set(5,20);

			Assert::AreEqual(20, list.get(5));
		}
	};


	int* creatIntReverseArray(int size)
	{
		int* array = new int[size];

		for (int i = 0; i<size; ++i)
		{
			array[i] = size - i;
		}
		return array;
	}

	int* creatRandomIntArray(int size)
	{
		int* array = new int[size];
		std::default_random_engine e;
		std::uniform_int_distribution<int> u(0,size);
		for (int i = 0; i < size; ++i)
		{
			array[i] = u(e);
		}
		return array;
	}


}


