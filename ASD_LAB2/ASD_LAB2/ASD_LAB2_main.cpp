#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Algorithms_for_LAB2.h"

using namespace std;

int main()
{
	int search = 8;
	const int size_array_quicksort = 10;
	int array_quicksort[size_array_quicksort] = { 1, -2, 5, 8, -7, 4, 9, 12, 15, 0 };
	cout << "Unsorted array: ";
	for (int index_array = 0; index_array < size_array_quicksort; index_array++)
	{
		cout << array_quicksort[index_array] << " ";
	}
	cout << "\n";
	cout << "Sorted array by algorithm QuickSort: ";
	QuickSort(array_quicksort, 0, size_array_quicksort - 1); // QuickSort algorithm
	for (int index_array = 0; index_array < size_array_quicksort; index_array++)
	{
		cout << array_quicksort[index_array] << " ";
	}
	cout << "\n";
	cout << "Index of the element with the value " << search << ": ";
	try
	{
		cout << BinarySearsh(array_quicksort, size_array_quicksort, search);
	}
	catch (const invalid_argument error)
	{
		cout << error.what();
	}
	cout << "\n\n";

	const int size_array_insertionsort = 10;
	int array_insertionsort[size_array_insertionsort] = { 15, 0, 4, 1, -7, 12, 6, 11, 5, 2 };
	search = 11;
	cout << "Unsorted array: ";
	for (int index_array = 0; index_array < size_array_insertionsort; index_array++)
	{
		cout << array_insertionsort[index_array] << " ";
	}
	cout << "\n";
	cout << "Sorted array by algorithm InsertionSort: ";
	InsertionSort(array_insertionsort, size_array_insertionsort);
	for (int index_array = 0; index_array < size_array_insertionsort; index_array++)
	{
		cout << array_insertionsort[index_array] << " ";
	}
	cout << "\n";
	cout << "Index of the element with the value " << search << ": ";
	try
	{
		cout << BinarySearsh(array_insertionsort, size_array_insertionsort, search);
	}
	catch (const invalid_argument error)
	{
		cout << error.what();
	}
	cout << "\n\n";

	const int size_array_bogosort = 10;
	int array_bogosort[size_array_bogosort] = { 3, 1, -5, -8, 7, 10, 2, 0, 18, 5 };
	search = 5;
	cout << "Unsorted array: ";
	for (int index_array = 0; index_array < size_array_bogosort; index_array++)
	{
		cout << array_bogosort[index_array] << " ";
	}
	cout << "\n";
	cout << "Sorted array by algorithm BogoSort: ";
	BogoSort(array_bogosort, size_array_bogosort - 1);
	for (int index_array = 0; index_array < size_array_bogosort; index_array++)
	{
		cout << array_bogosort[index_array] << " ";
	}
	cout << "\n";
	cout << "Index of the element with the value " << search << ": ";
	try
	{
		cout << BinarySearsh(array_bogosort, size_array_bogosort, search);
	}
	catch (const invalid_argument error)
	{
		cout << error.what();
	}
	cout << "\n\n";

	const int size_array_countingsort = 10;
	char array_countingsort[size_array_countingsort] = { 'b', 'j','e', 'i', 'g', 'd', 'h', 'f', 'c', 'a' };
	cout << "Unsorted array: ";
	for (int index_array = 0; index_array < size_array_countingsort; index_array++)
	{
		cout << array_countingsort[index_array] << " ";
	}
	cout << "\n";
	cout << "Sorted array by algorithm CountingSort: ";
	CountingSort(array_countingsort, size_array_countingsort);
	for (int index_array = 0; index_array < size_array_countingsort; index_array++)
	{
		cout << array_countingsort[index_array] << " ";
	}
	cout << "\n\n";

	cout << "Comparison of the time complexity of QuickSort and InsertionSort algorithms:\n";
	ComparisonAlgorithms();

	return 0;
}