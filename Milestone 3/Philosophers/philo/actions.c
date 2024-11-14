/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:34:50 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/14 16:22:46 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	log_message(t_philo *philo, char *message)
{
	size_t	timestamp;

	pthread_mutex_lock(&philo->status->print_lock);
	timestamp = get_time() - philo->status->start_time;
	printf("%zu %zu %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&philo->status->print_lock);
}

void	nom(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0)
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	else
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	pthread_mutex_lock(first);
	log_message(philo, "has taken a fork");
	pthread_mutex_lock(second);
	log_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->status->status_lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	log_message(philo, "is eating");
	pthread_mutex_unlock(&philo->status->status_lock);
	usleep(philo->status->time_to_eat * 1000);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

void	sleep_think(t_philo *philo)
{
	log_message(philo, "is sleeping");
	usleep(philo->status->time_to_sleep * 1000);
	log_message(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->status->num_philo == 1)
	{
		dead_boi(philo);
		return (NULL);
	}
	while (1)
	{
		nom(philo);
		sleep_think(philo);
	}
	return (arg);
}
