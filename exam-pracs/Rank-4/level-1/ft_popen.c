/* Name: ft_popen
Allowed functions: pipe, fork, dup2, execvp, close, exit
--------------------------------------------------------------------------------
Write the following function:

int ft_popen(const char *file, const char *argv[], char type);

The function must launch the executable file with the arguments argv (using execvp).
If type is 'r' the function must return a file descriptor connected to the output of the command.
If type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

For example the function could be used like that:

int main()
{
    int fd = ft_popen("ls", (const char *[]) {"ls", NULL}, 'r');
    char *line;
    while ((line = get_next_line(fd)))
        ft_putstr(line);
}

Hints:
Do not leak file descriptors. */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int ft_popen(const char *file, const char *argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	int pipefd[2];
	if (pipe(pipefd) == -1)
		return -1;
	pid_t pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(pipefd[0]);
			if (dup2(pipefd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		if (type == 'w')
		{
			close(pipefd[1]);
			if (dup2(pipefd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(pipefd[0]);
		close(pipefd[1]);
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(pipefd[1]);
		return pipefd[0];
	}
	else if (type == 'w')
	{
		close(pipefd[0]);
		return pipefd[1];
	}
	return -1;
}

void test_read()
{
    printf("=== TEST READ MODE ===\n");

    // Using ft_popen
    int fd = ft_popen("ls", (const char *[]){"ls", "-1", NULL}, 'r');
    if (fd == -1)
    {
        perror("ft_popen (r)");
        return;
    }
    printf("[ft_popen output]\n");
    char buf[128];
    ssize_t n;
    while ((n = read(fd, buf, sizeof(buf) - 1)) > 0)
    {
        buf[n] = '\0';
        fputs(buf, stdout);
    }
    close(fd);

    // Using system popen
    FILE *fp = popen("ls -1", "r");
    if (!fp)
    {
        perror("popen (r)");
        return;
    }
    printf("\n[popen output]\n");
    while (fgets(buf, sizeof(buf), fp))
        fputs(buf, stdout);
    pclose(fp);
}

void test_write()
{
    printf("\n=== TEST WRITE MODE ===\n");

    // Using ft_popen
    int fd = ft_popen("wc", (const char *[]){"wc", "-l", NULL}, 'w');
    if (fd == -1)
    {
        perror("ft_popen (w)");
        return;
    }
    printf("[ft_popen output]\n");
    const char *msg = "hello\nworld\nthis\nis\na\ntest\n";
    write(fd, msg, strlen(msg));
    close(fd);

    // Using system popen
    FILE *fp = popen("wc -l", "w");
    if (!fp)
    {
        perror("popen (w)");
        return;
    }
    printf("[popen output]\n");
    fputs(msg, fp);
    pclose(fp);
}

int main()
{
    test_read();
    test_write();
    return 0;
}