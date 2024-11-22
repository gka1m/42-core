/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:31:00 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/22 16:27:47 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_boi(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	log_message(philo, "has taken a fork");
	usleep(philo->status->time_to_die * 1000);
	// log_message(philo, "died");
	pthread_mutex_unlock(philo->l_fork);
}

int	everybardi_full(t_status *status)
{
	size_t	i;
	size_t	full;

	full = 0;
	i = 0;
	if (status->max_meals == -1)
		return (0);
	while (i < status->num_philo)
	{
		pthread_mutex_lock(&status->status_lock);
		if (status->philos[i].meal_count == status->max_meals)
			full++;
		pthread_mutex_unlock(&status->status_lock);
		i++;
	}
	if (full == status->num_philo)
	{
		pthread_mutex_lock(&status->status_lock);
		status->sim_over = 1;
		pthread_mutex_unlock(&status->status_lock);
		return (1);
	}
	return (0);
}

int	is_dead(t_status *status)
{
	size_t	i;

	i = 0;
	while (i < status->num_philo)
	{
		pthread_mutex_lock(&status->status_lock);
		if ((get_time() - status->philos[i].last_meal) > status->time_to_die)
		{
			log_message(status->philos, "died");
			status->sim_over = 1;
			return (pthread_mutex_unlock(&status->status_lock), 1);
		}
		pthread_mutex_unlock(&status->status_lock);
		i++;
	}
	return (0);
}

void	*routine_monitor(void *arg)
{
	t_status	*status;

	status = (t_status *)arg;
	while (1)
	{
		if (is_dead(status) || everybardi_full(status))
			break ;
	}
	pthread_mutex_lock(&status->status_lock);
	status->sim_over = 1;
	pthread_mutex_unlock(&status->status_lock);
	return (arg);
}
