/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:34:50 by kagoh             #+#    #+#             */
/*   Updated: 2025/03/11 12:53:22 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_boi(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	log_message(philo, "has taken a fork");
	usleep(philo->status->time_to_die * 1000);
	pthread_mutex_unlock(philo->l_fork);
}

void	bon_appetit(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 != 0 && philo->id == philo->status->num_philo)
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	else if (philo->id % 2 == 0)
	{
		usleep(2000);
		first = philo->r_fork;
		second = philo->l_fork;
	}
	else
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	nom(philo, first, second);
}

void	nom(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	log_message(philo, "has taken a fork");
	pthread_mutex_lock(second);
	log_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->status->status_lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->status->status_lock);
	log_message(philo, "is eating");
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
	pthread_mutex_lock(&philo->status->start);
	philo->last_meal = philo->status->start_time;
	pthread_mutex_unlock(&philo->status->start);
	if (philo->status->num_philo == 1)
	{
		dead_boi(philo);
		return (NULL);
	}
	while (1)
	{
		bon_appetit(philo);
		sleep_think(philo);
		pthread_mutex_lock(&philo->status->status_lock);
		if (philo->status->sim_over)
		{
			pthread_mutex_unlock(&philo->status->status_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->status->status_lock);
	}
	return (arg);
}
