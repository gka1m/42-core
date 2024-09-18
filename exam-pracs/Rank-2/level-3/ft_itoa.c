/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int numlen(int n)
{
	int count = 0;

	if (n == 0)
	{
		count = 1;
		return (count);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			count++;
		}
		while (n != 0)
		{
			count++;
			n /= 10;
		}
	}
	return count;
}

char *ft_itoa(int nbr)
{
	char *result;
	int length = numlen(nbr);
	long number = nbr;
	int i = length - 1;

	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return NULL;
	result[length] = '\0';

	if (nbr == 0)
		result[0] = '0';
	
	else if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		result[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	return result;
}