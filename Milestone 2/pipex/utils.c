/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:04:23 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/02 14:57:44 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pipex.h"

int	check_input_file(char *file)
{
	if (access(file, F_OK) != 0)
	{
		ft_printf("no such file or directory: %s\n", file);
		return (-1);
	}
	if (access(file, R_OK) != 0)
	{
		ft_printf("Error: Input file %s not found.\n", file);
		return (-1);
	}
	return (0);
}

char	*check_cmd(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	**extract_var(char **env)
{
	char	*path;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			if (*path == '\0')
				return (NULL);
			return (ft_split(path, ':'));
		}
		env++;
	}
	return (NULL);
}

char	*join_paths(const char *dir, const char *cmd)
{
	size_t	dir_len;
	size_t	cmd_len;
	size_t	full_len;
	char	*full_path;

	dir_len = ft_strlen(dir);
	cmd_len = ft_strlen(cmd);
	full_len = dir_len + cmd_len + 2;
	full_path = malloc(full_len * sizeof(char));
	if (full_path == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	ft_strlcpy(full_path, dir, full_len);
	ft_strlcat(full_path, "/", full_len);
	ft_strlcat(full_path, cmd, full_len);
	return (full_path);
}

char	*search_paths(char *cmd, char **paths)
{
	char	*full_path;

	while (*paths)
	{
		full_path = join_paths(*paths, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		paths++;
	}
	return (NULL);
}
