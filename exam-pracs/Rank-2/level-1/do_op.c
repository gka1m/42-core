#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int do_op(char *num1, char operator, char *num2)
{
	int n1 = atoi(num1);
	int n2 = atoi(num2);
	int result;

	switch(operator)
	{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			if (n2 == 0)
			{
				printf("Zero division error\n");
				return 1;
			}
			result = n1 / n2;
			break;
		case '%':
			if (n2 == 0)
			{
				printf("Zero modulo error\n");
				return 1;
			}
			result = n1 % n2;
			break;
		default:
			printf("Unknown operator\n");
			return 1;
	}
	printf("%d\n", result);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("\n");
		return 0;
	}
	do_op(argv[1], argv[2][0], argv[3]);
	return 0;
}