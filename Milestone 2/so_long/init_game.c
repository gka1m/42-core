/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:24:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/08/26 13:53:04 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(1);
	game->width = 800;
	game->height = 600;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->height,
			"Game");
	if (!game->win_ptr)
		exit(1);
	mlx_loop(game->mlx_ptr);
}

void	init_player(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
}

void	init_map(t_game *game, const char *map)
{
}

void	init_images(t_game *game)
{
}

void	init_game(t_game *game, const char *map)
{
	init_window(game);
	init_player(game);
	init_map(game, map);
	init_images(game);
}