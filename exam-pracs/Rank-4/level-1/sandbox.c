/* Assignment name		:	sandbox
Expected files		:	sandbox.c
Allowed functions	:	fork, waitpid, exit, alarm, sigaction, kill,
						printf, strsignal, errno
===============================================================================

Write the following function:

#include <stdbool.h>
int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)

This function must test if the function f is a nice function or a bad function,
you will return 1 if f is nice , 0 if f is bad or -1 in case of an error in
your function.

A function is considered bad if it is terminated or stopped by a signal
(segfault, abort...), if it exit with any other exit code than 0 or if it
times out.

If verbose is true, you must write the appropriate message among the following:

"Nice function!\n"
"Bad function: exited with code <exit_code>\n"
"Bad function: <signal description>\n"
"Bad function: timed out after <timeout> seconds\n"

You must not leak processes (even in zombie state, this will be checked using
wait).

We will test your code with very bad functions. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int g_signal;

void timeout_handler(int sig)
{
    if (SIGALRM == sig)
        g_signal = 1;
}

// int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
// {
//     int status;
//     struct sigaction sa;
//     int exit_status;

//     pid_t pid = fork();
//     if (pid == -1)
//         return -1;
//     if (pid == 0)
//     {
//         f();
//         exit(0);
//     }
//     sa.sa_handler = timeout_handler;
//     sigaction(SIGALRM, &sa, NULL);
//     alarm(timeout);
//     if (waitpid(pid, &status, 0) == -1)
//     {
//         while (1)
//         {
//             if (errno == 4)
//             {
//                 if (g_signal == 1)
//                 {
//                     if (verbose)
//                         printf("Bad function: timed out after %u seconds\n", timeout);
//                     kill(pid, SIGKILL);
//                     if (waitpid(pid, &status, 0) == -1)
//                         return -1;
//                     return 0;
//                 }
//                 continue;
//             }
//             else
//                 return -1;
//             break;
//         }
//     }
//     if (WIFSIGNALED(status))
//     {
//         exit_status = WTERMSIG(status);
//         if (verbose)
//             printf("Bad function: bad signal %s\n", strsignal(exit_status));
//         return 0;
//     }
//     if (WIFEXITED(status))
//     {
//         exit_status = WEXITSTATUS(status);
//         if (exit_status)
//         {
//             if (verbose)
//                 printf("Bad function: exited with code %d\n", exit_status);
//             return 0;
//         }
//         else
//         {
//             if (verbose)
//                 printf("Nice function!\n");
//             return 1;
//         }
//     }
//     return -1;
// }

static int setup_alarm_handler(void (*handler)(int))
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGALRM, &sa, NULL) == -1)
		return -1;
	return 0;
}

static int handle_timeout(pid_t pid, int timeout, bool verbose)
{
	if (g_signal)
	{
		if (verbose)
			printf("Bad function: timed out after %u seconds\n", timeout);
		kill(pid, SIGKILL);
		int status;
		if (waitpid(pid, &status, 0) == -1)
			return -1;
		return 0;
	}
	return -1; // Not a timeout, just some other waitpid error
}

static int analyze_child_status(int status, bool verbose)
{
	if (WIFSIGNALED(status))
	{
		int sig = WTERMSIG(status);
		if (verbose)
			printf("Bad function: %s\n", strsignal(sig));
		return 0;
	}
	else if (WIFEXITED(status))
	{
		int code = WEXITSTATUS(status);
		if (code != 0)
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", code);
			return 0;
		}
		else
		{
			if (verbose)
				printf("Nice function!\n");
			return 1;
		}
	}
	return -1;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	if (setup_alarm_handler(timeout_handler) == -1)
		return -1;

	pid_t pid = fork();
	if (pid == -1)
		return -1;

	if (pid == 0)
	{
		f();
		exit(0);
	}

	alarm(timeout);

	int status;
	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
		{
			if (handle_timeout(pid, timeout, verbose) == 0)
				return 0;
			continue;
		}
		return -1; // Some other error
	}

	return analyze_child_status(status, verbose);
}

 void good(void)
 {

 }

 void segfault_bad(void)
 {
    int *p = NULL;
    *p = 42;
 }

 void exit_nonzero(void)
 {
    exit(1);
 }

 void abort_fn(void)
 {
    abort();
 }

 void timeout_fn(void)
 {
    while (1);
 }

 int main(void)
{
    printf("Testing nice_function:\n");
    sandbox(good, 2, true);

    printf("Testing segfault_function:\n");
    sandbox(segfault_bad, 2, true);

    printf("Testing exit_nonzero_function:\n");
    sandbox(exit_nonzero, 2, true);

    printf("Testing abort_function:\n");
    sandbox(abort_fn, 2, true);

    printf("Testing timeout_function:\n");
    sandbox(timeout_fn, 2, true);

    return 0;
}