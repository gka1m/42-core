/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:03 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/19 15:42:07 by kagoh            ###   ########.fr       */
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
	size_t			last_meal;
	int				meal_count;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	struct s_status	*status;
}					t_philo;

typedef struct s_status
{
	size_t			num_philo;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			start_time;
	int				max_meals;
	int				sim_over;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	status_lock;
	pthread_mutex_t	start;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_status;

/* input validation checks */
int		ft_atoi(const char *str);
int		is_digit(const char *str);
int		validate_input(int ac, char **av);

/* initialization of threads and cleanup */
void	init_status(t_status *status, char **av);
void	init_forks(t_status *status);
void	init_philo(t_status *status);
void	cleanup(t_status *status, size_t num_philo);
void	status_cleanup(t_status *status, int thread_num);

/* actions and monitoring */
size_t	get_time(void);
void	*routine_monitor(void *arg);
void	nom(t_philo *philo);
void	sleep_think(t_philo *philo);
void	*philo_routine(void *arg);
void	start_sim(t_status *status);
void	log_message(t_philo *philo, char *message);
int		everybardi_full(t_status *status);
int		is_dead(t_status *status);
void	dead_boi(t_philo *philo);

#endif