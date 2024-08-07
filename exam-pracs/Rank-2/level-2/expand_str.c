#include <unistd.h>

void expand_str(char *str)
{
	int i = 0;
	int start = 0;
	int word_start = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (word_start)
				write(1, "   ", 3);
			
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			{
				write(1, &str[i], 1);
				i++;
			}
			word_start = 1;
		}
		else
		{
			while (str[i]== ' ' || str[i] == '\t')
				i++;
		}
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
	expand_str(argv[1]);
	return 0;
}