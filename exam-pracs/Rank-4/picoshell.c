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
    wait(NULL);
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