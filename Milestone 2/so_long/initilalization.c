/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilalization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:24:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/17 17:05:11 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// initialize connection and create window
void	init_window(t_game *game, int width, int height, char *title)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf("Failed to initialize connection\n");
		return ;
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, title);
	if (game->win_ptr == NULL)
	{
		ft_printf("Window creation failed\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return ;
	}
}

