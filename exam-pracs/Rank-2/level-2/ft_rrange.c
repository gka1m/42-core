/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int len;
	int *result;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	
	result = malloc(len * sizeof(int));
	if (result == NULL)
		return NULL;
	
	int i = 0;
	while (i < len)
	{
		if (start < end)
		{
			result[i] = end;
			end--;
		}
		else
		{
			result[i] = end;
			end++;
		}
		i++;
	}
	return result;
}