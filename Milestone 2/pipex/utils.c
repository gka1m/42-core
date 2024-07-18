/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:04:23 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/17 17:04:32 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* setting up of environment */

void error_exit(const char *msg)
{
    perror(msg);
    exit(1);
}

void init_env(const char *file1, const char *file2, int *fd_in.int *fd_out)
{
    *fd_in = open(file1, O_RDONLY);
    if (*fd_in < 0)
    {
        perror("Error opening file1");
        exit(1);
    }
    *fd_out = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*fd_out < 0)
    {
        perror("Error in creating file2");
        exit(1);
    }
}

void create_pipe(int *pipe_fd)
{
}