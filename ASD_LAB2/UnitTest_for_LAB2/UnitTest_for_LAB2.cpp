#include "pch.h"
#include "CppUnitTest.h"
#include "..\ASD_LAB2\Algorithms_for_LAB2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforLAB2
{
	TEST_CLASS(UnitTestforLAB2)
	{
	public:

		// Checking the execution of a binary search for an element in an unsorted array
		TEST_METHOD(BinarySearsh_Unsorted_Array)
		{
			try 
			{
				int search = 9;
				const int size = 10;
				int array[size] = { 1, -2, 5, 8, -7, 4, 9, 12, 15, 0 };
				int index_search = BinarySearsh(array, size, search);
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("Binary searsh cannot be applied to unsorted array", error.what());
			}
		}

		// Checking the binary search for a missing element in an array
		TEST_METHOD(BinarySearsh_Missing_Element)
		{
			try
			{
				int search = 15;
				const int size = 10;
				int array[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
				int index_search = BinarySearsh(array, size, search);
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("The element with this value is missing in the array", error.what());
			}
		}

		// Checking the binary search for an element in a sorted array
		TEST_METHOD(BinarySearsh_Array)
		{
			int search = 8;
			const int size = 10;
			int array[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int index_search = BinarySearsh(array, size, search);
			Assert::IsTrue(index_search == 8);
		}

		// Checking the execution of quick array sorting
		TEST_METHOD(QuickSort_Array)
		{
			const int size = 10;
			int array[size] = { 1, -2, 5, 8, -7, 4, 9, 12, 15, 0 };
			QuickSort(array, 0, size - 1);
			stringstream output;
			for (int index_array = 0; index_array < size; index_array++)
			{
				output << array[index_array] << " ";
			}
			Assert::IsTrue(output.str() == "-7 -2 0 1 4 5 8 9 12 15 ");
		}

		// Checking the execution of the sorting algorithm by inserting an array of one element
		TEST_METHOD(InsertionSort_Single_Element) 
		{
			try
			{
				const int size = 1;
				int array[size] = { 0 };
				InsertionSort(array, size);
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("To sort, the array must contain at least 2 elements", error.what());
			}
		}

		// Checking the execution of the array sorting algorithm by inserts.
		TEST_METHOD(InsertionSort_Array) 
		{
			const int size = 10;
			int array[size] = { 1, -2, 5, 8, -7, 4, 9, 12, 15, 0 };
			InsertionSort(array, size);
			stringstream output;
			for (int index_array = 0; index_array < size; index_array++)
			{
				output << array[index_array] << " ";
			}
			Assert::IsTrue(output.str() == "-7 -2 0 1 4 5 8 9 12 15 ");
		}

		// Checking the execution of the algorithm for bogosort of an array of one element
		TEST_METHOD(BogoSort_Single_Element) 
		{
			try
			{
				const int size = 1;
				int array[size] = { 0 };
				BogoSort(array, size - 1);
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("To sort, the array must contain at least 2 elements", error.what());
			}
		}

		// Checking the execution of the array bogosort algorithm.
		TEST_METHOD(BogoSort_Array) 
		{
			const int size = 10;
			int array[size] = { 1, -2, 5, 8, -7, 4, 9, 12, 15, 0 };
			BogoSort(array, size - 1);
			stringstream output;
			for (int index_array = 0; index_array < size; index_array++)
			{
				output << array[index_array] << " ";
			}
			Assert::IsTrue(output.str() == "-7 -2 0 1 4 5 8 9 12 15 ");
		}

		// Checking the execution of the sorting algorithm by counting for the char type for an array of one element
		TEST_METHOD(CountingSort_Single_Element)
		{
			try
			{
				const int size = 1;
				char array[size] = { 'a' };
				CountingSort(array, size);
			}
			catch (const invalid_argument error)
			{
				Assert::AreEqual("To sort, the array must contain at least 2 elements", error.what());
			}
		}

		// Checking the execution of the array sorting algorithm by counting for the char type
		TEST_METHOD(CountingSort_Array)
		{
			const int size = 10;
			char array[size] = { 'b', 'j','e', 'i', 'g', 'd', 'h', 'f', 'c', 'a'};
			CountingSort(array, size);
			stringstream output;
			for (int index_array = 0; index_array < size; index_array++)
			{
				output << array[index_array] << " ";
			}
			Assert::IsTrue(output.str() == "a b c d e f g h i j ");
		}
	};
}