/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:07:17 by kagoh             #+#    #+#             */
/*   Updated: 2024/08/01 14:08:03 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pipex.h"

char	*get_path(char *cmd, char **env)
{
	char	*execpath;
	char	**paths;
	char	**tmp;

	execpath = check_cmd(cmd);
	if (execpath)
		return (execpath);
	paths = extract_var(env);
	if (!paths)
		return (NULL);
	execpath = search_paths(cmd, paths);
	tmp = paths;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(paths);
	return (execpath);
}

void	first_fork(char *cmd, char **env, int in_fd, int (*pipe1)[2])
{
	pid_t	pid;
	char	*exec_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		dup2((*pipe1)[1], STDOUT_FILENO);
		close((*pipe1[0]));
		close((*pipe1[1]));
		exec_path = get_path(cmd, env);
		if (exec_path == NULL)
		{
			ft_printf("Error: Command %s not found\n", cmd);
			exit(1);
		}
		execve(exec_path, ft_split(cmd, ' '), env);
		perror("execve");
		exit(1);
	}
}

void	second_fork(char *cmd, char **env, int out_fd, int (*pipe1)[2])
{
	pid_t	pid;
	char	*exec_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(out_fd, STDIN_FILENO);
		dup2((*pipe1)[1], STDOUT_FILENO);
		close((*pipe1[0]));
		close((*pipe1[1]));
		exec_path = get_path(cmd, env);
		if (exec_path == NULL)
		{
			ft_printf("Error: Command %s not found\n", cmd);
			exit(1);
		}
		execve(exec_path, ft_split(cmd, ' '), env);
		perror("execve");
		exit(1);
	}
}
