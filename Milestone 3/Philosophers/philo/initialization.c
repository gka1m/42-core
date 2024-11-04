/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:58:14 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/04 15:26:40 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_status(t_status *status, char **av)
{
	status->num_philo = ft_atoi(av[1]);
	status->time_to_die = ft_atoi(av[2]);
	status->time_to_eat = ft_atoi(av[3]);
	status->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		status->max_meals = ft_atoi(av[5]);
	else
		status->max_meals = -1;
	status->sim_over = 0;
	status->start_time = get_time();
	pthread_mutex_init(&status->print_lock, NULL);
	pthread_mutex_init(&status->status_lock, NULL);
	init_forks(status);
	init_philo(status);
}

void	init_forks(t_status *status)
{
	size_t	i;

	i = 0;
	status->forks = malloc(status->num_philo * sizeof(pthread_mutex_t));
	if (!status->forks)
		return ;
	while (i < status->num_philo)
	{
		pthread_mutex_init(&status->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_status *status)
{
	size_t	i;

	i = 0;
	status->philos = malloc(status->num_philo * sizeof(t_philo));
	if (!status->philos)
		return ;
	while (i < status->num_philo)
	{
		status->philos[i].id = i + 1;
		status->philos[i].sleep_time = status->time_to_sleep;
		status->philos[i].eat_time = status->time_to_eat;
		status->philos[i].die_time = status->time_to_die;
		status->philos[i].last_meal = 0;
		status->philos[i].meal_count = 0;
		status->philos[i].dead = 0;
		status->philos[i].status = status;
		status->philos[i].lock = &status->status_lock;
		status->philos[i].l_fork = &status->forks[i];
		status->philos[i].r_fork = &status->forks[(i + 1) % status->num_philo];
		i++;
	}
}

void	cleanup(t_status *status, size_t num_philo)
{
	size_t	i;

	i = 0;
	if (status->forks)
	{
		while (i < num_philo)
		{
			pthread_mutex_destroy(&status->forks[i]);
			i++;
		}
		free(status->forks);
	}
	pthread_mutex_destroy(&status->print_lock);
	pthread_mutex_destroy(&status->status_lock);
	if (status->philos)
		free(status->philos);
}
