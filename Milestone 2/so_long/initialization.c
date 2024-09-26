/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:24:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/24 18:11:01 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void init_window(t_game *game, int width, int height)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf("Failed to initialize connection\n");
		return;
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (game->win_ptr == NULL)
	{
		ft_printf("Window creation failed\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return;
	}
}

void load_single(t_game *game, void **img_ptr, char *filename)
{
	int width;
	int height;

	*img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, filename, &width, &height);
	if (!*img_ptr)
		ft_printf("Error: Failed to load %s\n", filename);
}

void load_assets(t_game *game)
{
	load_single(game, &game->p_img, "textures/player.xpm");
	load_single(game, &game->wall_img, "textures/wall.xpm");
	load_single(game, &game->c_img, "textures/collectible.xpm");
	load_single(game, &game->floor_img, "textures/floor.xpm");
	load_single(game, &game->exit_img, "textures/door-opened.xpm");
	if (!game->p_img || !game->wall_img || !game->c_img || !game->floor_img || !game->exit_img)
	{
		if (game->p_img)
			mlx_destroy_image(game->mlx_ptr, game->p_img);
		if (game->wall_img)
			mlx_destroy_image(game->mlx_ptr, game->wall_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx_ptr, game->exit_img);
		if (game->floor_img)
			mlx_destroy_image(game->mlx_ptr, game->floor_img);
		if (game->c_img)
			mlx_destroy_image(game->mlx_ptr, game->c_img);
		ft_printf("Error: Failed to load assets\n");
		exit(1);
	}
}

void render_map(t_game *game, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->wall_img, j * 64, i * 64);
			else if (map->map_array[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->floor_img, j * 64, i * 64);
			else if (map->map_array[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->c_img, j * 64, i * 64);
			else if (map->map_array[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->exit_img, j * 64, i * 64);
			else if (map->map_array[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
										game->p_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
