/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:04:23 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/25 15:10:39 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_input_file(char *file)
{
	if (access(file, F_OK) != 0)
	{
		ft_printf("Error: Input file %s not found.\n", file);
		return (-1);
	}
	if (access(file, R_OK) != 0)
	{
		ft_printf("Error: Input file %s not found.\n", file);
		return (-1);
	}
	return (0);
}
