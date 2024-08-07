#include <unistd.h>

void rotone(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] == 'z')
				str[i] = 'a';
			else
				str[i]++;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] == 'Z')
				str[i] = 'A';
			else
				str[i]++;
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 1;
	}
	rotone(argv[1]);
	return 0;
}