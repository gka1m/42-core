#include "bsq.h"

char *substr_own(char *arr, int start, int len)
{
    char *res = (char*)malloc(len + 1);
    if (!res)
        return (NULL);

    int i = 0;
    int j = 0;
    while (arr[i])
    {
        if (i >= start && j < len)
        {
            res[j] = arr[i];
            j++;
        }
        i++;
    }
    res[j] = '\0';
    return (res);
}

void free_map(char** arr)
{
    int i = 0;
    if (arr)
    {
        while (arr[i])
        {
            if (arr[i])
                free(arr[i]);
            i++;
        }
        free(arr);
    }
}

int check_elem(char **arr, char c1, char c2)
{
    int i = 0;
    while (arr[i])
    {
        int j = 0;
        while (arr[i][j] != '\0')
        {
            if (arr[i][j] != c1 && arr[i][j] != c2)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int findmin(int n1, int n2, int n3)
{
    int min = n1;
    if (n2 < min)
        min = n2;
    if (n3 < min)
        min = n3;
    return (min);
}
