/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:31:00 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/04 16:14:55 by kagoh            ###   ########.fr       */
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
	if (philo->status->num_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		log_message(philo, "has taken a fork");
		usleep(philo->die_time * 1000);
		log_message(philo, "died");
		pthread_mutex_unlock(philo->l_fork);
		philo->status->sim_over = 1;
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	log_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	log_message(philo, "has taken a fork");
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
		i = -1;
		while (++i < status->num_philo)
		{
			pthread_mutex_lock(&status->status_lock);
			if ((get_time()
					- status->philos[i].last_meal) > status->time_to_die)
			{
				status->philos[i].dead = 1;
				status->sim_over = 1;
				pthread_mutex_unlock(&status->status_lock);
				printf("hellol--------------->\n");
				return (NULL);
			}
			pthread_mutex_unlock(&status->status_lock);
		}
		usleep(1000);
	}
	return (NULL);
}
