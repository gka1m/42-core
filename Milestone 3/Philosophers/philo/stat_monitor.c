/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:31:00 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/29 14:05:10 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("Philo %zu has taken left fork\n", philo->id);
	pthread_mutex_lock(philo->r_fork);
	printf("Philo %zu has taken right fork\n", philo->id);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine_monitor(void *arg)
{
	t_status	*status;
	size_t		i;

	status = (t_status *)arg;
	i = 0;
	while (1)
	{
		i = 0;
		while (i < status->num_philo)
		{
			pthread_mutex_lock(&status->status_lock);
			if ((get_time()
					- status->philos[i].last_meal) > status->time_to_die)
			{
				status->sim_over = 1;
				printf("Philo %zu has died\n", status->philos[i].id);
				pthread_mutex_unlock(&status->status_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&status->status_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
