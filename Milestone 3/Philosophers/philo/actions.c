/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:34:50 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/29 14:05:27 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	printf("Philo %zu is eating\n", philo->id);
	pthread_mutex_unlock(philo->lock);
	usleep(philo->eat_time * 1000);
}

void	sleep(t_philo *philo)
{
	printf("Philo %zu is sleeping\n", philo->id);
	usleep(philo->sleep_time * 1000);
}

void	think(t_philo *philo)
{
	printf("Philo %zu is thinking\n", philo->id);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->status->sim_over)
	{
		lock_forks(philo);
		eat(philo);
		unlock_forks(philo);
		sleep(philo);
		think(philo);
	}
	return (NULL);
}
