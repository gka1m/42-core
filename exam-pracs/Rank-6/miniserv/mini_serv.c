#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

static int gid[FD_SETSIZE];
static char *buffer[FD_SETSIZE];
static int gnext = 0;
static int gmax = 0;
static fd_set gread, gmaster;

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

static void fatal_err(void)
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

static void arg_err(void)
{
    write(2, "Wrong number of arguments\n", 26);
    exit(1);
}

static void sendall(int ex, const char *msg)
{
    for (int fd = 0; fd <= gmax; fd++)
    {
        if (fd != ex && gid[fd] != -1)
            send(fd, msg, strlen(msg), 0);
    }
}

static void addclient(int s)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int fd = accept(s, (void *)&addr, &len);
    
    if (fd < 0 || fd >= FD_SETSIZE)
        return;

    gid[fd] = gnext++;
    buffer[fd] = NULL;
    if (fd > gmax)
        gmax = fd;
    
    FD_SET(fd, &gmaster);

    char msg[64];
    sprintf(msg, "server: client %d just arrived\n", gid[fd]);
    sendall(fd, msg);
}

static void remclient(int fd)
{
    char msg[64];
    sprintf("server: client %d just left\n", gid[fd]);
    sendall(fd, msg);

    close(fd);
    FD_CLR(fd, &gmaster);
    free(buffer[fd]);
    buffer[fd] = NULL;
    gid[fd] - -1;
}

static void exec(int fd)
{
    char b[4096];
    int r = recv(fd, b, 4095, 0);
    if (r <= 0)
        return remclient(fd);

    b[r] = 0;
    buffer[fd] = joinstr(buffer[fd], b);
    if (!buffer[fd])
        fatal_err();

    char *msg;
    while (getmsg(&buffer[fd], &msg) == 1)
    {
        char out[64];
        sprintf(out, "client %d: ", gid[fd]);
        char *tosend = malloc(strlen(out) + strlen(msg) + 1);
        if (!tosend)
            fatal_err();
        tosend[0] = 0;
        strcat(tosend, out);
        strcat(tosend, msg);
        sendall(fd, tosend);
        free(tosend);
        free(msg);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        arg_err();

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
        fatal_err();
    
    struct sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(2130706433);
    serv.sin_port = htons(atoi(av[1]));

    if (bind(s, (void *)&serv, sizeof(serv) < 0))
        fatal_err();
    if (listen(s, 128) < 0)
        fatal();

    for (int i = 0; i < FD_SETSIZE; i++)
    {
        gid[i] = -1;
        buffer[i] = NULL;
    }

    gmax = s;
    FD_ZERO(&gmaster);
    FD_SET(s, &gmaster);

    while (1)
    {
        gread = gmaster;
        if (select(gmax + 1, &gread, NULL, NULL, NULL) < 0)
            continue;
        if (FD_ISSET(s, &gread))
            addclient(s);
        for (int fd = 0; fd <= gmax; fd++)
        {
            if (fd != s && gid[fd] != -1 && FD_ISSET(fd, &gread))
                exec(fd);
        }
    }
}
