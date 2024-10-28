/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:58:14 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/28 17:51:45 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_status(t_status *status, char **av)
{
	status->num_philo = ft_atoi(av[1]);
	status->time_to_die = ft_atoi(av[2]);
	status->time_to_eat = ft_atoi(av[3]);
	status->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		status->max_meals = ft_atoi(av[5]);
	else
		status->max_meals = -1;
	status->sim_over = 0;
	status->start_time = 0;
	pthread_mutex_init(&status->print_lock, NULL);
	pthread_mutex_init(&status->status_lock, NULL);
}
