#include "pch.h"
#include <CppUnitTest.h>
#include<random>
#include<time.h>
#include"unitTest.h"
#include"LinearSearch.h"
#include"SelectionSort.h"
#include"InsertionSort.h"
#include"MergeSort.h"
#include"Student.h"
#include"Array.h"
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"LinkedList.h"
#include"QuickSort.h"
#include"BinarySearch.h"
#include"BinarySearchTree.h"
#define _CRTDBG_MAP_ALLOC
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace UnitTest
{
	void makeSpectialArray(int array[], int sourceArray[], int left, int right, int i);
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
			int* array = createRandomIntArray(size);
			
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
			int* array = createRandomIntArray(size);

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

		TEST_METHOD(RemoveElementTest)
		{
			LinkedList<int>list;
			for (int i = 0; i < 10; ++i)
				list.add(i, i);

			list.removeElement(5);

			for (int i = 0; i < 5; ++i)
				Assert::AreEqual(i, list.get(i));
			for (int i = 5; i < 9; ++i)
				Assert::AreEqual(i + 1, list.get(i));
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

	TEST_CLASS(mergeSortTest)
	{
		TEST_METHOD(MergeTest)
		{
			int* tempArray = new int[10];
			int array[10] = { 1,3,5,7,9,2,4,6,8,10 };
			merge(array,(size_t) 0, (size_t)5, (size_t)10, tempArray);

			for (size_t i = 0; i < 9; ++i)
			{
				Assert::IsTrue(array[i] < array[i + 1]);
			}
			delete[] tempArray;
		}
		TEST_METHOD(MergeSortTest)
		{
			int* array = createRandomIntArray(20);
			mergeSort(array, 20);

			for (size_t i = 0; i < 19; ++i)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
			delete[] array;
		}
	};

	TEST_CLASS(QuickSortTest)
	{
		TEST_METHOD(PartitionTest)
		{
			int* array = createRandomIntArray(20);
			size_t j= partition2(array, 0, 19,1);

			for (size_t i = 0; i < j; ++i)
				Assert::IsTrue(array[i] <= array[j]);
			for(size_t i=j+1;i<20;++i)
				Assert::IsTrue(array[i] >= array[j]);
			delete[] array;
		}
		TEST_METHOD(quickSortTest)
		{
			int* array = createRandomIntArray(100);
			quickSort(array, 100);

			for (size_t i = 0; i < 9; ++i)
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
			delete[] array;
		}

		TEST_METHOD(makeSpecialArrayTest)
		{
			
			int* sourceArray = new int[100];
			for (int i = 0; i < 100; ++i)
				sourceArray[i] = i;
			int* array = new int[100];
			makeSpectialArray(array, sourceArray, 0, 99, 0);
			int p = 0;
			for (int i = 0; i < 100; ++i)
			{
				Assert::AreEqual(i, array[(i + 99) / 2]);
				std::swap(array[i], array[(i + 99) / 2]);
			}
		}
	};

	TEST_CLASS(BinarySearchTest)
	{
		TEST_METHOD(searchTest)
		{
			int* tempArray = new int[10];
			int array[10] = {0,1,2,3,4,5,6,7,8,9 };
			int index = BinarySearch(array, 10, 3);
			Assert::AreEqual(3, index);

			index = BinarySearch(array, 10, 9);
			Assert::AreEqual(9, index);
		
			index = BinarySearch(array, 10, 10);
			Assert::AreEqual(-1, index);
			delete[] tempArray;

		}

		TEST_METHOD(iterator_searchTest)
		{
			int* tempArray = new int[10];
			int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
			int index = BinarySearch_iteration(array, 10, 3);
			Assert::AreEqual(3, index);

			index = BinarySearch_iteration(array, 10, 9);
			Assert::AreEqual(9, index);

			index = BinarySearch_iteration(array, 10, 10);
			Assert::AreEqual(-1, index);
			delete[] tempArray;
		}
	};


	TEST_CLASS(BinarySearchTreeTest)
	{
		TEST_METHOD(searchTreeTest)
		{
			int* tempArray = new int[10] {5, 3, 2, 7, 8, 6, 4, 1, 9};
			
			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 10; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			for (int i = 0; i < 10; ++i) {
				Assert::IsTrue(binarySearchTree.contains(i));
			}
			Assert::IsFalse(binarySearchTree.contains(10));

			delete[] tempArray;

		}

		TEST_METHOD(preOrdeTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8};
			int* aimArray = new int[6]{ 5,3,2,4,6,8 };
			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i <6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			std::vector<int>outPut= binarySearchTree.preOrder();
			for (int i=0;i<6;++i)
			{
				Assert::AreEqual(aimArray[i], outPut[i]);
			}
			delete[] tempArray;

		}

		TEST_METHOD(preOrdeNrTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };
			int* aimArray = new int[6]{ 5,3,2,4,6,8 };
			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			std::vector<int>outPut = binarySearchTree.preOrderNR();
			for (int i = 0; i < 6; ++i)
			{
				Assert::AreEqual(aimArray[i], outPut[i]);
			}
			delete[] tempArray;

		}

		TEST_METHOD(levelOrdeNrTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };
			int* aimArray = new int[6]{ 5,3,6,2,4,8 };
			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			std::vector<int>outPut = binarySearchTree.levelOrder();
			for (int i = 0; i < 6; ++i)
			{
				Assert::AreEqual(aimArray[i], outPut[i]);
			}
			delete[] tempArray;
			delete[] aimArray;
		}

		TEST_METHOD(MaximumTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };
			
			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			int value= binarySearchTree.maximum();
			Assert::AreEqual(8, value);
			delete[] tempArray;

		}

		TEST_METHOD(MinimumTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };

			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			int value = binarySearchTree.minimum();
			Assert::AreEqual(2, value);
			delete[] tempArray;

		}

		TEST_METHOD(removeMinTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };

			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			std::vector<int>outPuts;
			for (int i = 0; i < 6; ++i)
				outPuts.push_back(binarySearchTree.removeMin());

			for (int i = 1; i < 6; ++i)
				Assert::IsTrue(outPuts[i] > outPuts[i - 1]);
		}

		TEST_METHOD(removeMaxTest)
		{
			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };

			BinarySearchTree<int>binarySearchTree;
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}

			std::vector<int>outPuts;
			for (int i = 0; i < 6; ++i)
				outPuts.push_back(binarySearchTree.removeMax());

			for (int i = 1; i < 6; ++i)
				Assert::IsTrue(outPuts[i] < outPuts[i - 1]);
			delete[] tempArray;
		}
		
		TEST_METHOD(removeTest)
		{
			

			_CrtSetBreakAlloc(155);

			int* tempArray = new int[6]{ 5, 3, 6,2,4,8 };
			int* aimArray_1 = new int[6]{ 8,6,5,4,3,2 };
			int* aimArray_2 = new int[5]{8,6,4,3,2 };

			BinarySearchTree<int>binarySearchTree;
			
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}
			
			binarySearchTree.remove(9);
			
			int size = binarySearchTree.size();
			std::vector<int>outPuts;
			for (int i = 0; i < 6; ++i)
				outPuts.push_back(binarySearchTree.removeMax());

			
			Assert::AreEqual(6, size);

			for (int i = 0; i < size; ++i)
				Assert::AreEqual(aimArray_1[i],outPuts[i]);


			
			for (int i = 0; i < 6; ++i)
			{
				binarySearchTree.add(tempArray[i]);
			}
			binarySearchTree.remove(5);
			size = binarySearchTree.size();
			outPuts.clear();
			Assert::AreEqual(5, size);
			for (int i = 0; i < 5; ++i)
				Assert::AreEqual(aimArray_2[i], binarySearchTree.removeMax());
			delete[] tempArray;
			delete[] aimArray_1;
			delete[] aimArray_2;
			

			
		}

	};


	int* createIntReverseArray(int size)
	{
		int* array = new int[size];

		for (int i = 0; i<size; ++i)
		{
			array[i] = size - i;
		}
		return array;
	}

	int* createRandomIntArray(int size)
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

	void makeSpectialArray(int array[],int sourceArray[],int left,int right,int i)
	{
		if (left > right)
			return;
		array[left] = sourceArray[i];
		makeSpectialArray(array, sourceArray, left+1, right, i + 1);
		std::swap(array[left], array[(left + right) / 2]);
	}

	
}


