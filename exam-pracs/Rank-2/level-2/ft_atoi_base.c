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