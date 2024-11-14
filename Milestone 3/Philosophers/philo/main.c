/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:39:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/14 16:23:31 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sim(t_status *status)
{
	size_t		i;
	pthread_t	monitor;

	i = -1;
	if (pthread_create(&monitor, NULL, &routine_monitor, status) != 0)
		cleanup(status, status->num_philo);
	while (++i < status->num_philo)
	{
		if (pthread_create(&status->philos[i].thread, NULL, &philo_routine,
				&status->philos[i]) != 0)
			cleanup(status, status->num_philo);
	}
	if (pthread_join(monitor, NULL) != 0)
		cleanup(status, status->num_philo);
	i = -1;
	while (++i < status->num_philo)
	{
		if (pthread_join(status->philos[i].thread, NULL) != 0)
			cleanup(status, status->num_philo);
	}
}

int	main(int ac, char **av)
{
	t_status	status;

	if (validate_input(ac, av) != 0)
		return (1);
	init_status(&status, av);
	status.start_time = get_time();
	pthread_mutex_lock(&status.start);
	start_sim(&status);
	pthread_mutex_unlock(&status.start);
	cleanup(&status, status.num_philo);
	return (0);
}
