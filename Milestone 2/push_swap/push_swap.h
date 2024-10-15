/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/15 16:40:59 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

/* stack operations */
void	push(t_stack *src, t_stack *dest);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rev_rot(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* initial checks and input validation */
// int		ft_isdigit(char c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		valid_num(char *str);
int		validate_store(char **nums, int *unique, int *count);
void	free_split(char **split);
int		validate_input(int ac, char **av, int *unique);

/* initializing stack and pushing inputs to stack */
t_node	*new_node(int value);
void	init_stack(t_stack *stack);
void	to_stack(t_stack *stack, int value);
void	free_stack(t_stack *stack);
t_stack	*initialize(int ac, char **av);

/* sorting the chunks */
int		check_sorted(t_stack *stack);
void	rank_nums(t_stack *stack);
int		calc_bits(int max);
void	radix_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
#endif