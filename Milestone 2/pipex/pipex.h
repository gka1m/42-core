/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:26:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/29 16:52:33 by kagoh            ###   ########.fr       */
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
int		check_input_file(char *file);
char	*check_cmd(char *cmd);
char	**extract_var(char **env);
char	*join_paths(const char *dir, const char *cmd);
char	*search_paths(char *cmd, char **paths);
char	*get_path(char *cmd, char **env);
void	set_pipes(int (*pipe1)[2], int (*pipe2)[2]);
void	first_fork(char *cmd, char **env, int in_fd, int (*pipe1)[2]);
void	second_fork(char *cmd, char **env, int out_fd, int (*pipe1)[2]);
void	prelim_pipex(char **argv, int *in_fd, int *out_fd, int (*pipe1)[2],
			int (*pipe2)[2]);
void	pipex(char **argv, char **env);

#endif