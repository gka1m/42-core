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

char **parse_command(char *cmd, char **env)
{
    char **args;

    args = ft_split(cmd, ' ');
    if (args == NULL || args[0] == NULL)
        return (NULL);
}

char **get_path(char **env)
{
    while (*env)
    {
        if (ft_strncmp(*env, "PATH", 4) == 0)
            break;
        env++;
    }
    return (ft_split(*env + 5, ':'));
}
