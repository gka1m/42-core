/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:26:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/25 14:53:23 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *string);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_len);
char	*ft_strcpy(char *dest, const char *src);
int     check_input_file(char *file);
char    *check_cmd(char *cmd);
char    **extract_var(char **env);
char    *join_paths(const char *dir, const char *cmd);
char    *search_paths(char *cmd, char **paths);

#endif