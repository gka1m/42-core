/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:46:52 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/23 16:26:16 by kagoh            ###   ########.fr       */
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

typedef struct s_map
{
	char	**map_array;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		player;
}			t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p_img;
	void	*wall_img;
	void	*exit_img;
	void	*floor_img;
	void	*c_img;
	int		px;
	int		py;
	int		moves;
}			t_game;

char		**read_file(char *mapfile);
void		handle_error(t_map *map, const char *message);
void		init_dims(t_map *map);
int			is_rect(t_map *map);
int			surrounded(t_map *map);
void		count_elems(t_map *map);
int			validate_elem(t_map *map);
void		dfs(char **map, int i, int j);
void		floodfill(char **map);
int			check_path(t_map *map, char **map_arr);
char		**ft_split(char const *s, char c);
int			validate_map(t_map *map, char *mapfile);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		free_map(char **map_array);
int			validate_str(t_map *map);

void		init_window(t_game *game, int width, int height);
void		load_assets(t_game *game);
void		render_map(t_game *game, t_map *map, int i, int j);

#endif
