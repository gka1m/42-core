/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void ft_putnbr(int num)
{
    long nbr = num;

    if (nbr > 10)
        ft_putnbr(nbr / 10);
    char res = nbr % 10 + '0';
    write(1, &res, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}

void tab_mult(int n)
{
    int result = 0;

    for (int i = 1; i <= 9; i++)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(n);
        write(1, " = ", 3);
        ft_putnbr(i * n);
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return 1;
    }
    tab_mult(ft_atoi(argv[1]));
    return 0;
}