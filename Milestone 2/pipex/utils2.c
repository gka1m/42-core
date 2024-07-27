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

