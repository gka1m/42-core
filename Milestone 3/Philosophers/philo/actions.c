/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:34:50 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/30 16:09:03 by kagoh            ###   ########.fr       */
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

void	philo_sleep(t_philo *philo)
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
		if (philo->status->sim_over)
			break;
		eat(philo);
		unlock_forks(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}
