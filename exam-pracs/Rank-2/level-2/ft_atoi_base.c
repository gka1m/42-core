/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int value;

	if (str_base < 2 || str_base > 16)
	{
		return 0;
	}
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
	*str == '\f' || *str == '\r')
		str++;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			value = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			value = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			value = *str - 'A' + 10;
		else
			break;
		result = result * str_base + value;
		str++;
	}
	return (result * sign);
}