/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/19 13:43:31 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// Free the validated map
// void	free_validated_map(char **validated_map)
// {
//     int i;

// 	i = 0;
//     if (validated_map)
//     {
//         while (validated_map[i])
//         {
//             free(validated_map[i]);
//             i++;
//         }
//         free(validated_map);
//     }
// }

int	main(int argc, char **argv)
{
	t_map	map;

	// Check for correct number of arguments
	if (argc != 2)
	{
		printf("Usage: ./map_test <mapfile>\n");
		return (1);
	}

	// Initialize the map structure fields to 0 or NULL
	map.map_array = NULL;
	map.width = 0;
	map.height = 0;
	map.collectibles = 0;
	map.exit = 0;
	map.player = 0;

	// Validate the map using the validate_map function
	if (validate_map(&map, argv[1]) == 0)
	{
		printf("Map is valid!\n");
	}
	else
	{
		printf("Map is invalid!\n");
	}

	// Free the original map array if it was allocated
	// if (map.map_array)
	// {
	// 	int i = 0;
	// 	while (map.map_array[i])
	// 	{
	// 		free(map.map_array[i]);
	// 		i++;
	// 	}
	// 	free(map.map_array);
	// }

	return (0);
}
