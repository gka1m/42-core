/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

#include <unistd.h>

int is_duplicate(char *str, char c, int index)
{
	int i = 0;

	while (i < index)
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int in_str(char *s, char c)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void union_str(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (!is_duplicate(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;

	while (s2[i] != '\0')
	{
		if (!is_duplicate(s2, s2[i], i) && !in_str(s1, s2[i]))
			write(1, &s2[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 1;
	}
	union_str(argv[1], argv[2]);
	return 0;
}