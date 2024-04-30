#include "sort.h"

void swap_int(int *num1, int *num2);
int lom_partition(int *array, size_t size, int l, int r);
void lom_sort(int *array, size_t size, int l, int r);
void quick_sort(int *array, size_t size);

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
 * lom_partition - Order array of ints using lomuto partition scheme
 *
 * @array: Array of ints
 * @size: size of array
 * @l: start
 * @r: end
 *
 * Return: the last index
 */
int lom_partition(int *array, size_t size, int l, int r)
{
	int *p, a, b;

	p = array + r;
	for (a = b = l; b < r; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_int(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *p)
	{
		swap_int(array + a, p);
		print_array(array, size);
	}
	return (a);
}

/**
 * lom_sort - Implement algorithm using recursion
 *
 * @array: Array of ints
 * @size: size of array
 * @l: beginning
 * @r: end
 */
void lom_sort(int *array, size_t size, int l, int r)
{
	int p;

	if (r - l > 0)
	{
		p = lom_partition(array, size, l, r);
		lom_sort(array, size, l, p - 1);
		lom_sort(array, size, p + 1, r);
	}
}

/**
 * quick_sort - Sorts ints using quicksort algorithm
 *
 * @array: array of ints
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lom_sort(array, size, 0, size - 1);
}
