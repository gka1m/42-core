#include <unistd.h>

void last_word(char *str)
{
	int i = 0;
	int end = 0;
	int start = 0;

	while (str[i] != '\0')
		i++;
	
	i--;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	
	end = i;

	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	
	start = i + 1;

	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	last_word(argv[1]);
	return 0;
}