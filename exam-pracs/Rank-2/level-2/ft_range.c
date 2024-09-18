/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
	int *result;
	int len;

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
			result[i] = start;
			start++;
		}
		else
		{
			result[i] = start;
			start--;
		}
		i++;
	}
	return result;
}
