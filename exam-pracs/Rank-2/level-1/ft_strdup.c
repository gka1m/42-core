/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>

char *ft_strdup(char *src)
{
	int len = 0;
	char *s = src;
	while (*s)
	{
		len++;
		s++;
	}
	char *result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return NULL;
	
	for (int i = 0; src[i] != '\0'; i++)
		result[i] = src[i];
	return result;
}