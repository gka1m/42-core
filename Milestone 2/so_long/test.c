/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/14 22:19:16 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	t_map map;
	char **validated_map;
	int error;
	int i;

	// Check if the user provided the correct number of arguments
	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	// Check the map and structure, return 1 if an error occurs
	error = check_map(&map, argv[1]);
	if (error)
		return (1);

	printf("Map elements are present\n");

	// Validate the map with floodfill
	validated_map = validate_map(&map, argv[1]);
	if (validated_map == NULL)
	{
		printf("Error: Map validation failed. The map is invalid (unreachable collectibles or exit)\n");

		// Free memory for map.map_array if validation fails
		for (i = 0; i < map.height; i++)
			free(map.map_array[i]);
		free(map.map_array);
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
	i = 0;
	while (validated_map[i])
	{
		free(validated_map[i]);
		i++;
	}
	free(validated_map);

	// Free memory for original map
	for (i = 0; i < map.height; i++)
		free(map.map_array[i]);
	free(map.map_array);

	return 0;
}
