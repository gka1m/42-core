#include <stdio.h>
#include <stdlib.h>

void fprime(int n)
{
	if (n == 1)
	{
		printf("1");
	}

	int first = 1;
	for (int i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			if (!first)
				printf("*");
			printf("%d", i);
			n /= i;
			first = 0;
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return 0;
	}
	fprime(atoi(argv[1]));
	return 0;
}