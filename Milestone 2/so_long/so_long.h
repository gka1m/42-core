/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:46:52 by kagoh             #+#    #+#             */
/*   Updated: 2024/08/26 12:55:48 by kagoh            ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COIN 'C'

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define ESC 65307

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

#endif