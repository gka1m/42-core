/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/13 17:30:51 by kagoh            ###   ########.fr       */
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

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	error = check_map(&map, argv[1]);
	if (error)
		return (1);

	printf("Map elements are present\n");

	validated_map = validate_map(&map, argv[1]);
	if (validated_map == NULL)
	{
		printf("Error validating map\n");
		return (1);
	}

	// Print out the result of the map after it has been floodfilled
	for (int i = 0; validated_map[i]; i++)
	{
		printf("%s\n", validated_map[i]);
	}

	// Don't forget to free the validated_map
	for (int i = 0; validated_map[i]; i++)
		free(validated_map[i]);
	free(validated_map);

	for (int j = 0; j < map.height; j++)
		free(map.map_array[j]);
	free(map.map_array);
	return 0;
}
