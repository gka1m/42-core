/* Allowed functions: close, fork, wait, exit, execvp, dup2, pipe
--------------------------------------------------------------------------------
Write the followingfunction

int picoshell(char **cmds[]);

The goal of this function is to execute a pipeline.
It must execute each commands of cmds and connect the output of one to the input
of the next command (just like a shell)

Cmds contains a null-terminated list of valid commands.
Each rows of cmds are an argv array directly useable for a call to execvp.
The first arguments of each command is the command name or path and can be
passed directly as the first argument of execvp.

If any error occur, the function must return 1 (you must of course close all the
open fds before), otherwise the function must wait all child processes and return 0

You will find in this directory a file main.c which contain something to help you
test your function.

For example this should work:
$>./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell

$>./picoshell echo 'squalala!' "|" cat "|" sed 's/a/b/g'
squblblb!

Hints:
Do not leak file descriptors */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
    int pipefd[2];
    int prev_fd = -1;
    pid_t pid;

    for (int i = 0; cmds[i]; i++)
    {
        if (cmds[i + 1] && pipe(pipefd) == -1)
            return 1;
        pid = fork();
        if (pid == -1)
            return 1;
        if (pid == 0)
        {
            if (prev_fd != -1)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (cmds[i + 1])
            {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
                close(pipefd[0]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        if (prev_fd != -1)
            close(prev_fd);
        if (cmds[i + 1])
        {
            close(pipefd[1]);
            prev_fd = pipefd[0];
        }
    }
    int status;
    while (wait(&status) > 0)
        ;
    return 0;
}

int main()
{
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd2[] = {"grep", "c", NULL};
    char *cmd3[] = {"wc", "-l", NULL};
    char **cmds[] = {cmd1, cmd2, cmd3, NULL};

    if (picoshell(cmds) == 1)
        return 1;
    return 0;
}