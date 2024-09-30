/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:17:27 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/30 14:49:55 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_array[i][j] == 'P')
			{
				game->px = j;
				game->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	valid_movement(t_game *game, int newy, int newx)
{
	if (newx < 0 || newx >= game->map.width - 1 || newy < 0
		|| newy >= game->map.height - 1)
		return (0);
	if (game->map.map_array[newy][newx] == '1')
		return (0);
	return (1);
}

int	handle_key(int key, t_game *game)
{
	int	newx;
	int	newy;

	newx = game->px;
	newy = game->py;
	if (key == UP_KEY || key == W_KEY)
		newy--;
	else if (key == DOWN_KEY || key == S_KEY)
		newy++;
	else if (key == RIGHT_KEY || key == D_KEY)
		newx++;
	else if (key == LEFT_KEY || key == A_KEY)
		newx--;
	else if (key == ESC_KEY)
	{
		cleanup(game);
		exit(0);
	}
	move(game, newy, newx);
	return (0);
}

void	move(t_game *game, int newy, int newx)
{
	if (!valid_movement(game, newy, newx))
		return ;
	if (game->map.map_array[newy][newx] == 'C')
		game->map.collectibles--;
	if (game->map.map_array[newy][newx] == 'E' && game->map.collectibles == 0)
	{
		ft_printf("Success! You win\n");
		cleanup(game);
		exit(0);
	}
	if (game->map.map_array[game->py][game->px] == 'P'
		&& (game->map.map_array[game->py][game->px] != 'E'))
		game->map.map_array[game->py][game->px] = '0';
	else if (game->map.map_array[game->py][game->px] == 'P')
		game->map.map_array[game->py][game->px] = 'E';
	game->px = newx;
	game->py = newy;
	if (game->map.map_array[newy][newx] != 'E')
		game->map.map_array[newy][newx] = 'P';
	ft_printf("Moves: %d\n", game->moves++);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_map(game, &game->map);
}

void	cleanup(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_map(game->map.map_array);
	free(game->mlx_ptr);
}
