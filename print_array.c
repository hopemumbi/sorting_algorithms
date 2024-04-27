#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;
	
	i = 0;
	/*while array is not NULL and i < no of elements in array*/
	while (array && i < size)
	{
		/*Add comma and space after first element*/
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		/*preincrement then execute following code*/
		++i;
	}
	printf("\n");
}
