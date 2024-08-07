#include <unistd.h>
#include <stdlib.h>

void search_and_replace(char *str, char to_find, char to_replace)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == to_find)
		{
			write(1, &to_replace, 1);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		exit(1);
	}
	if (argv[2][1] != '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		exit(1);
	}
	
	search_and_replace(argv[1], *argv[2], *argv[3]);
	exit(0);
}