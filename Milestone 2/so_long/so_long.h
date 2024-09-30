/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:46:52 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/30 14:42:54 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100

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
int			check_invalid_c(t_map *map);
void		put_image(t_game *game, void *img, int x, int y);

void		init_window(t_game *game, int width, int height);
void		load_single(t_game *game, void **img_ptr, char *filename);
void		load_assets(t_game *game);
void		render_map(t_game *game, t_map *map);

void		find_player(t_game *game);
int			valid_movement(t_game *game, int newx, int newy);
int			handle_key(int key, t_game *game);
void		move(t_game *game, int newx, int newy);
void		destroy_images(t_game *game);
void		cleanup(t_game *game);
int			handle_close(t_game *game);

#endif
