/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/05 17:11:56 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
    int size;
} t_stack;

#endif