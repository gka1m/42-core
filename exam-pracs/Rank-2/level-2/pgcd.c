#include <stdio.h>
#include <stdlib.h>

int gcd(int n1, int n2)
{
	while (n2 != 0)
	{
		int temp = n2;
		n2 = n1 % n2;
		n1 = temp;
	}
	return n1;
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return 0;
	}
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);

	int result = gcd (n1, n2);
	printf("%d\n", result);
	return 0;
}