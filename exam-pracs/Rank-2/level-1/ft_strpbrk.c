/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <stddef.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		const char *temp = s2;
		while(*temp)
		{
			if (*s1 == *temp)
				return (char *)s1;
			temp++;
		}
		s1++;
	}
	return NULL;
}