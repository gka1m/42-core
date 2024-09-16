/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/16 15:47:46 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// Free the validated map
void free_validated_map(char **validated_map)
{
    int i = 0;
    if (validated_map)
    {
        while (validated_map[i])
        {
            free(validated_map[i]);
            i++;
        }
        free(validated_map);
    }
}

// Free the original map
void free_map(t_map *map)
{
    int i = 0;
    if (map->map_array)
    {
        while (i < map->height)
        {
            free(map->map_array[i]);
            i++;
        }
        free(map->map_array);
    }
}

int main(int argc, char *argv[])
{
    t_map map;
    char **validated_map;
    // int error;
    int i;

    // Check if the user provided the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }

    // Check the map and structure, return 1 if an error occurs
    // error = check_map(&map, argv[1]);
    // if (error)
    // {
    //     free_map(&map);  // Free map if check_map fails
    //     return (1);
    // }

    // printf("Map elements are present\n");

    // Validate the map with floodfill
    validated_map = validate_map(&map, argv[1]);
    if (validated_map == NULL)
    {
        printf("Error: Map validation failed. The map is invalid (unreachable collectibles or exit)\n");

        // Free memory for map.map_array if validation fails
        free_map(&map);
        return (1);
    }

    printf("Map is valid!\n");

    // Print the validated (floodfilled) map
    i = 0;
    printf("Floodfilled Map:\n");
    while (validated_map[i])
    {
        printf("%s\n", validated_map[i]);
        i++;
    }

    // Free memory for validated_map
    free_validated_map(validated_map);

    // Free memory for the original map
    free_map(&map);

    return 0;
}
