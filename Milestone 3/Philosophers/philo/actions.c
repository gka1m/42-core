/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:34:50 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/04 16:03:20 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	log_message(philo, "is eating");
	pthread_mutex_unlock(philo->lock);
	usleep(philo->eat_time * 1000);
}

void	philo_sleep(t_philo *philo)
{
	log_message(philo, "is sleeping");
	usleep(philo->sleep_time * 1000);
}

void	think(t_philo *philo)
{
	log_message(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->status->sim_over)
	{
		lock_forks(philo);
		if (philo->status->sim_over)
			break ;
		eat(philo);
		unlock_forks(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	log_message(t_philo *philo, const char *message)
{
	size_t	timestamp;

	pthread_mutex_lock(&philo->status->print_lock);
	timestamp = get_time() - philo->status->start_time;
	printf("%zu %zu %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&philo->status->print_lock);
}
