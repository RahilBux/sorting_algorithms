#include "sort.h"

/**
 * swap_int - Swaps two ints
 *
 * @num1: First int
 * @num2: Second int
 */
void swap_int(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * selection_sort - Sorts an array of ints in ascending order
 *
 * @array: The array to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mini = array + i;
		for (j = i + 1; j < size; j++)
			mini = (array[j] < *mini) ? (array + j) : mini;
		if ((array + i) != mini)
		{
			swap_int(array + i, mini);
			print_array(array, size);
		}
	}
}
