/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdio.h>

char *ft_strrev(char *str)
{
    int length = 0;
    int i = 0;
    char temp;

    // Calculate the length of the string
    while (str[length] != '\0')
        length++;

    // Reverse the string in-place
    while (i < length / 2)
    {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
        i++;
    }

    return str;
}
