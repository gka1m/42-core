/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:04:23 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/25 15:10:39 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_input_file(char *file)
{
	if (access(file, F_OK) != 0)
	{
		ft_printf("Error: Input file %s not found.\n", file);
		return (-1);
	}
	if (access(file, R_OK) != 0)
	{
		ft_printf("Error: Input file %s not found.\n", file);
		return (-1);
	}
	return (0);
}

char *check_cmd(char *cmd)
{
	if (ft_strncmp(cmd, "./", 2) == 0 && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char **extract_var(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (ft_split(*env + 6, ':'));
		env++;
	}
	return (NULL);
}

char *join_paths(const char *dir, const char *cmd)
{
	size_t	dir_len;
	size_t	cmd_len;
	size_t	full_len;
	char	*full_path;

	dir_len = ft_strlen(dir);
	cmd_len = ft_strlen(cmd);
	full_len = dir_len + cmd_len;
	full_path = malloc(full_len * sizeof(char));
	if (full_path == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	ft_strcpy(full_path, dir);
	ft_strcpy(full_path, "/");
	ft_strcpy(full_path, cmd);
	return (full_path);
}

char *search_paths(char *cmd, char **paths)
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