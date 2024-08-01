/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:21:10 by kagoh             #+#    #+#             */
/*   Updated: 2024/08/01 13:39:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pipex.h"

void	prelim_pipex(char **argv, int *in_fd, int *out_fd, int (*pipe1)[2])
{
	if (check_input_file(argv[1]) == -1)
		exit(1);
	*in_fd = open(argv[1], O_RDONLY);
	if (*in_fd == -1)
	{
		perror("Input file error");
		exit(1);
	}
	*out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*out_fd == -1)
	{
		perror("Output file error");
		close(*in_fd);
		exit(1);
	}
	if (pipe(*pipe1) == -1)
	{
		perror("Pipe Error");
		close(*in_fd);
		close(*out_fd);
		exit(1);
	}
}

void	pipex(char **argv, char **env)
{
	int	in_fd;
	int	out_fd;
	int	pipe1[2];

	prelim_pipex(argv, &in_fd, &out_fd, &pipe1);
	first_fork(argv[2], env, in_fd, &pipe1);
	second_fork(argv[3], env, out_fd, &pipe1);
	close(pipe1[0]);
	close(pipe1[1]);
	close(in_fd);
	close(out_fd);
	wait(NULL);
	wait(NULL);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	pipex(argv, env);
	return (0);
}
