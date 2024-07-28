/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:07:17 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/27 14:07:17 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(char *cmd, char **env)
{
    char    *execpath;
    char    **paths;
    char    **tmp;

    execpath = check_cmd(cmd);
    if (execpath)
        return execpath;
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

void    set_pipes(int *pipe1[2], int *pipe2[2])
{
    if (pipe(*pipe1) == -1 || pipe(*pipe2) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void    first_fork(char *cmd, char **env, int in_fd, int *pipe1[2])
{
    pid_t   pid;
    char    *exec_path;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
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
            ft_printf("Error: Command  %s not found\n", cmd);
            exit(EXIT_FAILURE);
        }
        execve(exec_path, ft_split(cmd, ' '), env);
        perror('execve');
        exit(EXIT_FAILURE);
    }  
}

void    second_fork(char *cmd, char **env, int out_fd, int *pipe1[2])
{
    pid_t   pid;
    char    *exec_path;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
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
            ft_printf("Error: Command  %s not found\n", cmd);
            exit(EXIT_FAILURE);
        }
        execve(exec_path, ft_split(cmd, ' '), env);
        perror('execve');
        exit(EXIT_FAILURE);
    }  
}

