/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

#include <stddef.h>

int max(int *tab, unsigned int len)
{
	if (tab == NULL || len == 0)
		return 0;
	int highest = tab[0];
	for (unsigned int i = 0; i < len; i++)
	{
		if (tab[i] > highest)
			highest = tab[i];
	}
	return highest;
}
