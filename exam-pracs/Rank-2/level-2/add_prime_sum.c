/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <stdlib.h>
#include <unistd.h>

int ft_isprime(int n)
{
	if (n <= 1)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int add_prime_sum(int num)
{
	int sum = 0;
	for (int i = 2; i <= num; i++)
	{
		if (ft_isprime(i) == 1)
			sum += i;
	}
	return (sum);
}

void ft_putnbr(int n)
{
	long num = n;
	
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	char res = num % 10 + '0';
	write(1, &res, 1);
}
int ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		exit(1);
	}
	if (argv[1] < 0)
	{
		write(1, "0\n", 2);
		exit(1);
	}
	int result = add_prime_sum(ft_atoi(argv[1]));
	ft_putnbr(result);
	write(1, "\n", 1);
	exit(0);
}