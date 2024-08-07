#include <unistd.h>

char capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return c;
}

char decapitalize(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

int ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

void rstr_capitalizer(char *str)
{
	int i = 0;
	int start = 1;
	int last = -1;

	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
		{
			str[i] = decapitalize(str[i]);
			last = i;
			if (!ft_isalpha(str[i + 1]))
			{
				str[i] = capitalize(str[i]);
				start = 1;
			}
			else
				start = 0;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char  **argv)
{
	if (argc < 2)	
	{
		write(1, "\n", 1);
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		rstr_capitalizer(argv[i]);
		write(1, "\n", 1);
	}
	return 0;
}