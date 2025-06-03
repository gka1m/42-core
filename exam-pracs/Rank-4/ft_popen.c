#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int ft_popen(char *cmd, char **envp)
{
    int pipefd[2];
    
    if (pipe(pipefd) == -1)
        return -1;
    
    pid_t pid = fork();
    if (pid == -1)
        return -1;

    if (pid == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        char *argv[4] = {"/bin/sh", "-c", cmd, NULL};
        execve("/bin/sh", argv, envp);
        exit(1);
    }
    close(pipefd[1]);
    return pipefd[0];
}

void read_from_fd(int fd)
{
	char buffer[1024];
	ssize_t bytes;

	while ((bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
		buffer[bytes] = '\0';
		write(STDOUT_FILENO, buffer, bytes);
	}
}

void test_ft_popen(char *cmd, char **envp)
{
	printf("\n==== ft_popen OUTPUT ====\n");
	int fd = ft_popen(cmd, envp);
	if (fd < 0) {
		perror("ft_popen");
		return;
	}
	read_from_fd(fd);
	close(fd);
}

void test_real_popen(char *cmd)
{
	printf("\n==== real popen OUTPUT ====\n");
	FILE *fp = popen(cmd, "r");
	if (!fp) {
		perror("popen");
		return;
	}
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), fp)) {
		fputs(buffer, stdout);
	}
	pclose(fp);
}

int main(int argc, char **argv, char **envp)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s \"<command>\"\n", argv[0]);
		return 1;
	}

	char *cmd = argv[1];
	test_ft_popen(cmd, envp);
	test_real_popen(cmd);

	return 0;
}