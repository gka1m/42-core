/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilalization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:24:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/23 16:25:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	init_window(t_game *game, int width, int height)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		printf("Failed to initialize connection\n");
		return ;
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (game->win_ptr == NULL)
	{
		printf("Window creation failed\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return ;
	}
}

void	load_assets(t_game *game)
{
	game->p_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player.xpm",
			64, 64);
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm",
			64, 64);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/door-open.xpm", 64, 64);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm",
			64, 64);
	game->c_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/collectible.xpm", 64, 64);
	if (!game->p_img || game->wall_img || game->exit_img || game->floor_img
		|| game->c_img)
	{
		printf("Error: Failed to load assets\n");
		exit(1);
	}
}

void	render_map(t_game *game, t_map *map, int i, int j)
{
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall_img, i * 64, j * 64);
			else if (map->map_array[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->floor_img, i * 64, j * 64);
			else if (map->map_array[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->c_img, i * 64, j * 64);
			else if (map->map_array[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->exit_img, i * 64, j * 64);
			else if (map->map_array[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->p_img, i * 64, j * 64);
			j++;
		}
		i++;
	}
}


// int main(void)
// {
//     t_game game;
//     int width = 100;
//     int height = 100;

//     // Initialize the game structure to ensure no garbage values
//     game.mlx_ptr = NULL;
//     game.win_ptr = NULL;

//     // Initialize the window
//     init_window(&game, width, height);

//     // Check for failure
//     if (!game.mlx_ptr || !game.win_ptr)
//     {
//         printf("Window initialization failed\n");
//         return (1);
//     }

//     // Start the MLX loop
//     mlx_loop(game.mlx_ptr);

//     // Proper cleanup after mlx_loop exits
//     if (game.win_ptr)
//         mlx_destroy_window(game.mlx_ptr, game.win_ptr);
//     if (game.mlx_ptr)
//     {
//         mlx_destroy_display(game.mlx_ptr);
//         free(game.mlx_ptr);
//     }

//     return (0);
// }
