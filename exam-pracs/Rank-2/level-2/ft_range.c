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
