/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 14:48:23 by kagoh            ###   ########.fr       */
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

/* Utilities (ft functions) */
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *string);
int		ft_lstsize(t_stack *stack);

/* initial checks and input validation */
int		valid_num(char *str);
int		has_duplicates(char **nums);
char	**split_input(int ac, char **av);
void	free_split(char **split);
char	**validate_input(int ac, char **av);

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
int		find_max_rank(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
#endif