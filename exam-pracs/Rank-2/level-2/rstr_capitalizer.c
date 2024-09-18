/*Subject
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

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