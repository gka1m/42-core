#include <unistd.h>

void first_word(const char *str)
{
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;

	if (str[i] == '\0')
	{
		write(1, "\n", 1);
		return;
	}
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	first_word(av[1]);
	return 0;
}