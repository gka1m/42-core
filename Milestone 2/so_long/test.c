/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/12 17:17:01 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// Print the final state of the map after floodfill
void print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

// Test function for maps
void test_map(char *mapfile)
{
	t_map map;
	char **copy;

	// Validate the map (reading file, checking structure, and floodfill)
	copy = validate_map(&map, mapfile);

	if (copy)
		printf("Map %s is valid.\n", mapfile);
	else
	{
		printf("Map %s is invalid.\n", mapfile);
		return;
	}

	// Print the final state of the map copy after floodfill
	printf("Final map state after floodfill:\n");
	print_map(copy);

	// Free the copy after printing
	// int i = 0;
	// while (copy[i])
	// 	free(copy[i]);
	// free(copy);
}

int main(void)
{
    // Test the valid map
    printf("Testing map1 (valid):\n");
    test_map("map1.ber");

    // Test the invalid map
    printf("\nTesting map2 (invalid):\n");
    test_map("map2.ber");

    return 0;
}