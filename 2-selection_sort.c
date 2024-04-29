#include "sort.h"

/**
 * swap - swap the values of two integers
 *
 * @x: A pointer to the first integer to be swapped
 * @y: A pointer to the second integer
 */
void swap(int *x, int *y)
{
	int temp = *x; /*A temporary variable to store the value of x*/
	*x = *y;
	*y = temp;

}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using Selection sort algorithm.
 *
 * @array: A pointer to an array of integers
 * @size: The number of integers in the array
 *
 * Description - print the array each time a swap happens
 */
void selection_sort(int *array, size_t size)
{
	/**
	 * i: outer loop counter for the number of passes
	 * j: inner loop counter to iterate through unsorted elements
	 * min_idx: index of the current minimum element found so far
	 * length: copy of the size of the array
	 */
	size_t i, j, min_idx, length = size;

	/* Outer loop: Iterate for each pass */
	for (i = 0; i < length - 1; i++)
	{
		min_idx = i; /* Assuming the first element is the minimum */

		/* Inner loop: iterate through the unsorted part*/
		for (j = i + 1; j < length; j++)
		{
			/* If element at j is less than the current minimum element*/
			if (array[j] < array[min_idx])
				/*Update min_idx to the index of the new minimum*/
				min_idx = j;
		}

		/*Only if the new minimum is not at the current position*/
		if (min_idx != i)
		{
			/*Swap the value at current i with one at min_idx*/
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
