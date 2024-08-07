int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n % 2 != 0)
		return 0;
	return (is_power_of_2(n /2));
}