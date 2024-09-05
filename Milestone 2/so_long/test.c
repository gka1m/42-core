/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/05 15:17:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_map map;
    t_player player;

    // Initialize player position (you can hardcode it for testing)
    player.x = 0;
    player.y = 0;

    // Load the map from file
    if (check_map(&map, "map1.ber") == 1)
    {
        error_msg(&map, "Invalid map");
        return 1;
    }

    // Test the find_valid_path function
    int valid_path = find_valid_path(&map, &player);
    if (valid_path == 1)
        printf("Valid path found!\n");
    else
        printf("No valid path found.\n");

    // Free the map memory
    for (int i = 0; i < map.height; i++)
        free(map.map_array[i]);
    free(map.map_array);

    return 0;
}