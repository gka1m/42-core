/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h>

void write_word(char *start, char *end)
{
    while (start < end)
    {
        write(1, start, 1);
        start++;
    }
}

void rostring(char *str)
{
    int i = 0;
    int len = 0;
    char *first_start;
    char *first_end;
    char *start;
    char *end;

    // Skip leading spaces and tabs
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Find the first word
    first_start = &str[i];
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    first_end = &str[i];

    // Skip spaces/tabs after the first word
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Print the remaining words
    while (str[i])
    {
        start = &str[i];
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
        end = &str[i];

        // Print the word followed by a space
        if (start < end)
        {
            write_word(start, end);
            write(1, " ", 1);
        }

        // Skip spaces/tabs between words
        while (str[i] == ' ' || str[i] == '\t')
            i++;
    }

    // Print the first word if it exists
    if (first_start < first_end)
        write_word(first_start, first_end);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        rostring(argv[1]);
    }
    write(1, "\n", 1);
    return 0;
}
