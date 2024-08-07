#include <stdlib.h>

char *ft_strdup(char *src)
{
	int len = 0;
	char *result;
	char *temp = src;

	while (*temp)
	{
		len++;
		temp++;
	}
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	for (int i = 0; i <= len; i++)
	{
		result[i] = src[i];
	}
	return result;
}