/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:46:52 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/12 17:15:15 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}		t_player;

typedef struct s_map
{
	char	**map_array;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		player;
}	t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
}	t_game;

char	**read_file(char *mapfile);
void	error_msg(t_map *map, const char *message);
void	check_structure(t_map *map, char *mapfile);
void	check_elements(t_map *map);
int		check_map(t_map *map, char *mapfile);
void	dfs(char **map, int i, int j);
void	floodfill(char **map);
char	**ft_split(char const *s, char c);
char	**validate_map(t_map *map, char *mapfile);

#endif
