/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/30 14:52:07 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->p_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_img);
	mlx_destroy_image(game->mlx_ptr, game->exit_img);
	mlx_destroy_image(game->mlx_ptr, game->floor_img);
	mlx_destroy_image(game->mlx_ptr, game->c_img);
}

int	handle_close(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long <filename>\n"), 1);
	if (validate_map(&map, argv[1]) == 0)
	{
		init_window(&game, map.width * 64, map.height * 64);
		load_assets(&game);
		map.map_array = read_file(argv[1]);
		game.map = map;
		render_map(&game, &map);
		find_player(&game);
		game.moves = 1;
		mlx_key_hook(game.win_ptr, handle_key, &game);
		mlx_hook(game.win_ptr, 17, 0, handle_close, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		return (ft_printf("Invalid map\n"), 1);
	cleanup(&game);
	return (0);
}
