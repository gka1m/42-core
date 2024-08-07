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