#include "sort.h"
#include <stdio.h>
#include <stdbool.h>
/**
 * swap - Swaps two integers.
 *
 * @x: Pointer to the first integer.
 * @y: Pointer to the seconde integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sorts an array of integers using bubble sort algorithm
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	/* Pass through the array (size - 1) times */
	for (i = 0; i < size - 1; i++)
	{
		/* Initialize swapped to false at the start of each pass */
		swapped = false;
		/* Iterate through the array upto size - i - 1 */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If the current element is greater than the next */
			if (array[j] > array[j + 1])
			{
				/*swap the elements; set swapped to true; print the array*/
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		/*If swapped is false at the end of the inner loop*/
		if (swapped == false)
		{
			/*Print the array; Break out of the loop*/
			print_array(array, size);
			break;
		}
	}
}
