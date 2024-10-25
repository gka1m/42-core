/*
Assignment: ft_printf
Expected files: ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end 
----------------------------------------------------------------------------

Prototype: int ft_printf(const char *, ...);
Write a function named ft_printf that will mimic the real printf but only manage the following conversions:
1. s(string)
2. d (decimal)
3. x (lowercase hexadecimal)

Output examples:

call: ft_printf("%s\n", "toto")
out: toto$

call: ft_printf("Magic %s is %d", "number", 42)
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42)
out: Hexadecimal for 42 is 2a$
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// manage %s conversion
int printstr(const char *str)
{
	int count = 0;
	
	if (str == NULL)
	{
		write(1, "(null)", 6);
		count += 6;
	}
	else
	{
		for (int i = 0; str[i] != '\0'; i++)
			write(1, &str[i], 1);
	}
	return count;
}

// manage %d conversion
int printnumber(int n)
{
	int count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n > 9)
		printnumber(n / 10);
	char res = n % 10 + '0';
	write(1, &res, 1);
	count++;
	return count;
}

// manage %x conversion
int printhex(unsigned int n)
{
	int count = 0;
	char hex[] = "0123456789abcdef";

	if (n >= 16)
		printhex(n /16);
	write(1, &hex[n % 16], 1);
	count++;
	return count;
}

int specifier(const char *converter, va_list args)
{
	int count = 0;
	if (*converter == 's')
		count += printstr(va_arg(args, char *));
	else if (*converter == 'd')
		count += printnumber(va_arg(args, int));
	else if (*converter == 'x')
		count += printhex(va_arg(args, unsigned int));
	return count;
}

int ft_printf(const char *text, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, text);
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			i++;
			if (text[i] == '\0')
				break;
			count += specifier(&text[i], args);
		}
		else
		{
			write(1, &text[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return count;
}

// int main(void)
// {
// 	ft_printf("Ft_printf: %s\n", "toto");
// 	printf("Actual printf: %s\n", "toto");
// 	ft_printf("Ft_printf: Magic %s is %d\n", "number", 42);
// 	printf("Actual printf: Magic %s is %d\n", "number", 42);
// 	ft_printf("Ft_printf: Hexadecimal for %d is %x\n", 42, 42);
// 	printf("Actual printf: Hexadecimal for %d is %x\n", 42, 42);
// }