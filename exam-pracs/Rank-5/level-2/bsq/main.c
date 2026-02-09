#include "bsq.h"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        if (exec(stdin) == -1)
            fprintf(stderr, "map error1\n");
    }
    else
    {
        for (int i = 1; i < ac; i++)
        {
            if (convert_file(av[i]) == -1)
                fprintf(stderr, "map error2\n");
            if (i < ac - 1)
                fprintf(stdout, "\n");
        }
    }
    return (0);
}