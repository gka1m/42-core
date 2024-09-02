/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:07:17 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/02 14:44:34 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pipex.h"

char	*get_path(char *cmd, char **env)
{
	char	*execpath;
	char	**paths;
	char	**tmp;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	execpath = check_cmd(cmd_args[0]);
	if (execpath)
		return (execpath);
	paths = extract_var(env);
	if (!paths)
		return (NULL);
	execpath = search_paths(cmd_args[0], paths);
	tmp = paths;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(paths);
	free(cmd_args);
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
			exit(1);
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
		dup2((*pipe1)[0], STDIN_FILENO);
		dup2(out_fd, STDOUT_FILENO);
		close((*pipe1)[0]);
		close((*pipe1)[1]);
		exec_path = get_path(cmd, env);
		if (exec_path == NULL)
			exit(1);
		execve(exec_path, ft_split(cmd, ' '), env);
		perror("execve");
		exit(1);
	}
}
