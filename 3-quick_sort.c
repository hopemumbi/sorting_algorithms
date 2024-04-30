#include "sort.h"
/**
 * swap -  Swaps the values of two integers.
 * @x: A pointer to the first integer to swap.
 * @y: A pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Partition an array using Lomuto partition scheme.
 *
 * @array: A pointer to the array to partition
 * @size: Number of elements in the array.
 * @hi: The index of the high element
 * @lo: The index of the low elelment
 *
 * Return: The final pivot index;
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int i, j;
	int pivot = array[hi]; /*Choose the last elelment as pivot*/

	/*Temporary pivot index*/
	i = lo;
	for (j = lo; j < hi; ++j)
	{
		/*If the current element is less than the pivot*/
		if (array[j] < pivot)
		{
			/*Swap only if i < j to avoid unnecessary swaps*/
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			/*Move the temporary pivot index forward*/
			++i;
		}
	}
	if (array[i] > pivot)
	{
		swap(&array[i], &array[hi]);
		print_array(array, size);
	}
	/*Return the final index of the pivot element*/
	return (i);
}
/**
 * quick_sort_r - Recursive function to implement quicksort
 *
 * @array: An array of integers to be sorted.
 * @size: Number of elements in the array.
 * @lo: The index of the low element
 * @hi: The index of the high element
 */
void quick_sort_r(int *array, size_t size, int lo, int hi)
{
	int p;

	/* Ensure indices are in correct order */
	if (lo >= hi)
		return;

	/* Partition array and get the pivot index */
	p = partition(array, size, lo, hi);

	/* Sort the two partitions */
	quick_sort_r(array, size, lo, p - 1); /* Left side of pivot*/
	quick_sort_r(array, size, p + 1, hi); /* Right side of pivot*/
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using Quick sort algorithm.
 *
 * @array: An array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_r(array, size, 0, size - 1);
}
