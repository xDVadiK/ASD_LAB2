#pragma once
#include <iostream>

using namespace std;

// BinarySearsh algorithm
int BinarySearsh(int* array, int size, int search)
{
	int index_array = size - 1;
	while (index_array > 0) // Checking the array for sorting
	{
		if (array[index_array - 1] < array[index_array])
		{
			index_array--;
		}
		else throw invalid_argument("Binary searsh cannot be applied to unsorted array");
	}
	int min_index = 0;
	int max_index = size - 1;
	int middle_index;
	bool element_is_found(false); 
	while (max_index >= min_index && !element_is_found)
	{
		middle_index = min_index + (max_index - min_index) / 2;
		if (array[middle_index] > search)
		{
			max_index = middle_index - 1;
		}
		else if (array[middle_index] < search)
		{
			min_index = middle_index + 1;
		}
		else
		{
			element_is_found = true;
		}
	}
	if (element_is_found)
	{
		return middle_index;
	}
	else throw invalid_argument("The element with this value is missing in the array");
}

// QuickSort algorithm
void QuickSort(int* array, int first_index, int last_index)
{
	if (first_index < last_index)
	{
		int left_index = first_index;
		int right_index = last_index;
		int support_element = array[(left_index + right_index) / 2]; // Calculation of the reference element
		do
		{
			while (array[left_index] < support_element) // Searching for an element larger than the reference element
			{
				left_index++;
			}
			while (array[right_index] > support_element) // Finding an element smaller than the reference element
			{
				right_index--;
			}
			if (left_index <= right_index)
			{
				swap(array[left_index], array[right_index]);
				left_index++;
				right_index--;
			}
		} while (left_index < right_index);
		// Recursive function calls for subarrays
		QuickSort(array, first_index, right_index); 
		QuickSort(array, left_index, last_index);
	}
}

// InsertionSort algorithm
void InsertionSort(int* array, int size)
{
	if (size > 1)
	{
		for (int index_array = 1; index_array < size; index_array++)
		{
			int selected_item = array[index_array]; 
			int index_sorted_part = index_array - 1;
			while (index_sorted_part >= 0 && array[index_sorted_part] > selected_item) // Finding the position to insert the selected element
			{
				array[index_sorted_part + 1] = array[index_sorted_part];
				array[index_sorted_part] = selected_item;
				index_sorted_part--;
			}
		}
	}
	else throw invalid_argument("To sort, the array must contain at least 2 elements");
}

// BogoSort algorithm
void BogoSort(int* array, int index_last)
{
	if (index_last > 0)
	{
		int index_array = index_last;
		while (index_array > 0) // Checking the array for sorting
		{
			if (array[index_array - 1] > array[index_array]) 
			{
				for (int i = 0; i <= index_last; i++)
				{
					swap(array[i], array[(rand() % index_last)]); // Shuffling the values of all array elements
				}
				index_array = index_last;
			}
			else index_array--;
		}
	}
	else throw invalid_argument("To sort, the array must contain at least 2 elements");
}

// CountingSort algorithm for type char
void CountingSort(char* array, int size)
{
	if (size > 1)
	{
		char max_element = array[0]; 
		char min_element = array[0]; 
		for (int array_index = 0; array_index < size; array_index++)
		{
			if (array[array_index] > max_element) // Calculating the maximum element in an array
			{
				max_element = array[array_index];
			}
			if (array[array_index] < min_element) // Calculating the minimum element in an array
			{
				min_element = array[array_index];
			}
		}
		int range_of_values = (int)max_element - (int)min_element + 1; // Range of values in the array
		int* counter_array = new int[range_of_values];
		for (int index_element = 0; index_element < range_of_values; index_element++)
		{
			counter_array[index_element] = 0;
		}
		for (int array_index = 0; array_index < size; array_index++)
		{
			counter_array[(int)array[array_index] - (int)min_element]++; // The number of occurrences of each element from the array
		}
		int counter = 0;
		for (int i = 0; i < range_of_values; i++)
		{
			for (int j = 0; j < counter_array[i]; j++)
			{
				array[counter] = (char)i + min_element;
				counter++;
			}
		}
	}
	else throw invalid_argument("To sort, the array must contain at least 2 elements");
}

// Comparison of the time complexity of QuickSort and InsertionSort algorithms
void ComparisonAlgorithms()
{
	srand(time(NULL));
	double average_time_quicksort;
	for (int degree_size = 1; degree_size < 6; degree_size++) // The degree of dimensionality of the data
	{
		int size_array_quicksort = (int)pow(10, degree_size); // Setting the data dimension
		int* array_quicksort = new int[size_array_quicksort];
		average_time_quicksort = 0;
		for (int launch_number = 0; launch_number < 10; launch_number++) // A cycle of ten runs for each dimension value
		{
			for (int index_array = 0; index_array < size_array_quicksort; index_array++)
			{
				array_quicksort[index_array] = rand() % 10000; // Filling an array with random values
			}
			clock_t begin = clock();
			QuickSort(array_quicksort, 0, size_array_quicksort - 1); // QuickSort algorithm
			clock_t end = clock();
			double seconds = double((double)end - (double)begin) / CLOCKS_PER_SEC; // Calculation of execution time in seconds
			average_time_quicksort += seconds;
		}
		average_time_quicksort /= 10; // Calculating the average value for ten runs
		cout << "QuickSort with array size: " << size_array_quicksort << ". Time in seconds: " << average_time_quicksort << "\n";
	}
	cout << "\n";

	double average_time_insertsort;
	for (int degree_size = 1; degree_size < 6; degree_size++) // The degree of dimensionality of the data
	{
		int size_array_insertionsort = (int)pow(10, degree_size); // Setting the data dimension
		int* array_insertionsort = new int[size_array_insertionsort];
		average_time_insertsort = 0;
		for (int launch_number = 0; launch_number < 10; launch_number++) // A cycle of ten runs for each dimension value
		{
			for (int index_array = 0; index_array < size_array_insertionsort; index_array++)
			{
				array_insertionsort[index_array] = rand() % 10000; // Filling an array with random values
			}
			clock_t begin = clock();
			InsertionSort(array_insertionsort, size_array_insertionsort); // InsertionSort algorithm
			clock_t end = clock();
			double seconds = double((double)end - (double)begin) / CLOCKS_PER_SEC; // Calculation of execution time in seconds
			average_time_insertsort += seconds;
		}
		average_time_insertsort /= 10; // Calculating the average value for ten runs
		cout << "InsertionSort with array size: " << size_array_insertionsort << ". Time in seconds: " << average_time_insertsort << "\n";
	}
}