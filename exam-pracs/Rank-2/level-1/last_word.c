/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <unistd.h>

void last_word(char *str)
{
    int i = 0;

    // Find the end of the string
    while (str[i] != '\0')
        i++;

    // Move backwards to find the start of the last word
    while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t'))
        i--;

    // If we reached the start of the string, there are no words
    if (i == 0)
    {
        write(1, "\n", 1);
        return;
    }

    // Move backwards to find the start of the last word
    int start = i;
    while (start > 0 && (str[start - 1] != ' ' || str[start - 1] != '\t'))
        start--;

    // Write the last word
    while (start < i)
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
		return 1;
	}
	last_word(argv[1]);
	return 0;
}