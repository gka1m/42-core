/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:03 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/28 16:16:27 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			sleep_time;
	size_t			die_time;
	size_t			eat_time;
	size_t			last_meal;
	int				meal_count;
	int				dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*lock;
	struct s_status	*status;

}					t_philo;

typedef struct s_status
{
	size_t			num_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			max_meals;
	size_t			start_time;
	int				sim_over;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	status_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_status;

/* input validation checks */
int	ft_atoi(const char *str);
int	is_digit(const char *str);
int	validate_input(int ac, char **av);

/* initialization of threads */

#endif