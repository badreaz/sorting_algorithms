#include "sort.h"

void count_sort(int *array, size_t size, int num, int *mem);

/**
 * radix_sort - sorts an array of integers using radix sort algorithm
 * @array: array to sort.
 * @size: array size.
 */
void radix_sort(int *array, size_t size)
{
	int *tmp, max, i;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	for (max = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (i = 1; max / i > 0; i *= 10)
	{
		count_sort(array, size, i, tmp);
		print_array(array, size);
	}
	free(tmp);
}

/**
 * count_sort - sort an array using sorting algorithm
 * @array: array to sort.
 * @size: array size.
 * @num: number of digits.
 * @mem: buffer that handle sorted array.
 */
void count_sort(int *array, size_t size, int num, int *mem)
{
	int digit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i, index;

	for (i = 0; i < size; i++)
		digit[(array[i] / num) % 10] += 1;
	for (i = 1; i < 10; i++)
		digit[i] += digit[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		index = digit[(array[i] / num) % 10];
		mem[index - 1] = array[i];
		digit[(array[i] / num) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = mem[i];
}
