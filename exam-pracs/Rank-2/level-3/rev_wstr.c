#include <stdlib.h>
#include <unistd.h>

void rev_wstr(char *str)
{
	int i = 0;
	int start = 0;
	int end = 0;

	while (str[end] != '\0')
		end++;
	end--;
		
	while (end >= 0)
	{
		while (end >= 0 && (str[end] == ' ' || str[end] == '\t'))
			end--;
		start = end;
		while (start >= 0 && str[start] != ' ' && str[start] != '\t')
			start--;
		
		int word_start = start + 1;
		while (word_start <= end)
		{
			write(1, &str[word_start], 1);
			word_start++;
		}

		if (start > 0)
			write(1, " ", 1);
		
		end = start - 1;
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
	rev_wstr(argv[1]);
	return 0;
}