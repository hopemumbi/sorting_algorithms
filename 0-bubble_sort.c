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
	size_t i;
	size_t length = size; /*Store the value of size*/
	bool swapped;
	/*Check if array is NULL or its size less than 2*/
	if (array == NULL || size < 2)
		return;

	/*Initialize swapped to true*/
	swapped = true;

	/* Keep passing through the array as long swapped is true */
	while (swapped == true)
	{
		/*Initialize swapped to false to indicate no swap yet*/
		swapped = false;
		/*Iterate through the array upto length - 1 */
		for (i = 0; i < length - 1; i++)
		{
			/* If the current element is greater than the next */
			if (array[i] > array[i + 1])
			{
				/*swap the elements; print the array; set swapped to true*/
				swap(&array[i], &array[i + 1]);
				print_array(array, size); /*Use size instead of length*/
				swapped = true;
			}
		}
		/*Decrement to skip last sorted element*/
		length--;
	}
}
