#include <unistd.h>

void repeat_alpha(char *str)
{
	int i = 0;
	int count;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			count = str[i] - 'A';
		else
		{
			write(1, &str[i], 1);
			i++;
			continue;
		}
		for(int j = 0; j <= count; j++)
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

	repeat_alpha(argv[1]);
	return 0;
}