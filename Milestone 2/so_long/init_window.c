/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:24:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/08/17 14:24:07 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

void *init_window(void *mlx_ptr, int width, int height)
{
    void *win_ptr;

    win_ptr = mlx_new_window(mlx_ptr, width, height, "Gkaim");
    if (!win_ptr)
        exit(1);
    return (win_ptr);
}
