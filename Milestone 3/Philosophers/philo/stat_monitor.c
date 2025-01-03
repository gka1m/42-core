/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:31:00 by kagoh             #+#    #+#             */
/*   Updated: 2025/01/03 17:08:22 by kagoh            ###   ########.fr       */
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

	pthread_mutex_lock(&philo->status->status_lock);
	pthread_mutex_lock(&philo->status->print_lock);
	if (!philo->status->sim_over)
	{
		timestamp = get_time() - philo->status->start_time;
		printf("%zu %zu %s\n", timestamp, philo->id, message);
	}
	pthread_mutex_unlock(&philo->status->print_lock);
	pthread_mutex_unlock(&philo->status->status_lock);
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
		// pthread_mutex_lock(&status->statu`s_lock);
		// status->sim_over = 1;
		// pthread_mutex_unlock(&status->status_lock);
		return (1);
	}
	return (0);
}

int	is_dead(t_status *status)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&status->status_lock);
	while (i < status->num_philo)
	{
		if ((get_time() - status->philos[i].last_meal) > status->time_to_die)
		{
			// status->sim_over = 1;
			pthread_mutex_unlock(&status->status_lock);
			log_message(&status->philos[i], "died");
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&status->status_lock);
	return (0);
}

void	*routine_monitor(void *arg)
{
	t_status	*status;

	status = (t_status *)arg;
	pthread_mutex_lock(&status->start);
	usleep(10000);
	pthread_mutex_unlock(&status->start);
	while (1)
	{
		if (is_dead(status) == 1 || everybardi_full(status) == 1)
		{
			pthread_mutex_lock(&status->status_lock);
			status->sim_over = 1;
			pthread_mutex_unlock(&status->status_lock);
			break ;
		}
	}
	return (arg);
}
