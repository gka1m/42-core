/*Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int do_op(char *num1, char operator, char *num2)
{
	int n1 = atoi(num1);
	int n2 = atoi(num2);
	int result;

	switch (operator)
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
			printf("Invalid operator\n");
			return 1;
	}
	return result;
}
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("\n");
		return 1;
	}
	int res = do_op(argv[1], *argv[2], argv[3]);
	printf("%d\n", res);
	return 0;
}