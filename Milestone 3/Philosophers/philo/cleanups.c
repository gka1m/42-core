/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:28:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/19 14:29:28 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_status *status, size_t num_philo)
{
	size_t	i;

	i = 0;
	if (status->forks)
	{
		while (i < num_philo)
		{
			pthread_mutex_destroy(&status->forks[i]);
			i++;
		}
		free(status->forks);
	}
	pthread_mutex_destroy(&status->print_lock);
	pthread_mutex_destroy(&status->status_lock);
	pthread_mutex_destroy(&status->start);
	if (status->philos)
		free(status->philos);
}

void	status_cleanup(t_status *status, int thread_num)
{
	if (thread_num >= 1)
		pthread_mutex_destroy(&status->print_lock);
	if (thread_num >= 2)
		pthread_mutex_destroy(&status->status_lock);
	if (thread_num >= 3)
		pthread_mutex_destroy(&status->start);
}