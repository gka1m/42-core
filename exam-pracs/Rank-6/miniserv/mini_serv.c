#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int getmsg(char **buffer, char **msg)
{
    char *b;
    int i = 0;

    *msg = 0;
    if (*buffer == 0)
        return 0;
    while ((*buffer)[i])
    {
        if ((*buffer)[i] == '\n')
        {
            b = calloc(1, sizeof(*b) * (strlen(*buffer + i + 1) + 1));\
            if (b == 0)
                return -1;
            strcpy(b, *buffer + i + 1);
            *msg = *buffer;
            (*msg)[i + 1] = 0;
            *buffer = b;
            return 1;
        }
        i++;
    }
    return 0;
}

char *joinstr(char *str, char *addon)
{
    char *res;
    int len;

    if (str == 0)
        len = 0;
    else
        len = strlen(str);
    res = malloc((len + strlen(addon) + 1) * sizeof(res));
    if (!res)
        return NULL;
    res[0] = 0;
    if (str != 0)
        strcat(res, str);
    free(str);
    strcat(res, addon);
    return res;
}

static int gid[FD_SETSIZE];
static char *buffer[FD_SETSIZE];
static int gnext = 0;
static int gmax = 0;
static int fdset, gread, gmaster;

