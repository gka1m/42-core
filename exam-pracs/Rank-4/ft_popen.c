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
