/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:58:14 by kagoh             #+#    #+#             */
/*   Updated: 2024/12/23 16:39:09 by kagoh            ###   ########.fr       */
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
	if (pthread_mutex_init(&status->print_lock, NULL) != 0)
		status_cleanup(status, 0);
	if (pthread_mutex_init(&status->status_lock, NULL) != 0)
		status_cleanup(status, 1);
	if (pthread_mutex_init(&status->start, NULL) != 0)
		status_cleanup(status, 2);
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
		if (pthread_mutex_init(&status->forks[i], NULL) != 0)
		{
			while (--i > 0)
				pthread_mutex_destroy(&status->forks[i]);
			free(status->forks);
			status->forks = NULL;
			return ;
		}
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
		memset(&status->philos[i], 0, sizeof(t_philo));
		status->philos[i].id = i + 1;
		status->philos[i].status = status;
		status->philos[i].l_fork = &status->forks[i];
		status->philos[i].r_fork = &status->forks[(i + 1) % status->num_philo];
		i++;
	}
}
