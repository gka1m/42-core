#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
/* mine */
#include <sys/select.h>

static int gid[FD_SETSIZE];
static char *buffer[FD_SETSIZE];
static int gnext = 0;
static int gmax = 0;
static fd_set gread, gmaster;
/* end of mine */

/* note: extract_message and str_join are given in the subject, as well as main */
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}
/* end of given functions */

/* mine */
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
    buffer[fd] = str_join(buffer[fd], b);
    if (!buffer[fd])
        fatal_err();

    char *msg;
    while (extract_message(&buffer[fd], &msg) == 1)
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
/* end of mine */

/*this main is given*/

// int main() {
// 	int sockfd, connfd, len;
// 	struct sockaddr_in servaddr, cli;

// 	// socket create and verification
// 	sockfd = socket(AF_INET, SOCK_STREAM, 0);
// 	if (sockfd == -1) {
// 		printf("socket creation failed...\n");
// 		exit(0);
// 	}
// 	else
// 		printf("Socket successfully created..\n");
// 	bzero(&servaddr, sizeof(servaddr));

// 	// assign IP, PORT
// 	servaddr.sin_family = AF_INET;
// 	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
// 	servaddr.sin_port = htons(8081);

// 	// Binding newly created socket to given IP and verification
// 	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
// 		printf("socket bind failed...\n");
// 		exit(0);
// 	}
// 	else
// 		printf("Socket successfully binded..\n");
// 	if (listen(sockfd, 10) != 0) {
// 		printf("cannot listen\n");
// 		exit(0);
// 	}
// 	len = sizeof(cli);
// 	connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
// 	if (connfd < 0) {
// 		printf("server acccept failed...\n");
// 		exit(0);
// 	}
// 	else
// 		printf("server acccept the client...\n");
// }