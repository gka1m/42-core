/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

int ft_strlen(char *str)
{
	int count = 0;
	
	for (int i = 0; str[i] != '\0'; i++)
		count++;
	return count;
}
