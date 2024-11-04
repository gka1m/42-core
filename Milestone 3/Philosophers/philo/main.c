/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:39:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/04 15:58:20 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sim(t_status *status)
{
	size_t		i;
	pthread_t	monitor;

	i = 0;
	while (i < status->num_philo)
	{
		pthread_create(&status->philos[i].thread, NULL, philo_routine,
			&status->philos[i]);
		i++;
	}
	pthread_create(&monitor, NULL, routine_monitor, status);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < status->num_philo)
	{
		pthread_join(status->philos[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_status	status;

	if (validate_input(ac, av) != 0)
		return (1);
	init_status(&status, av);
	status.start_time = get_time();
	start_sim(&status);
	cleanup(&status, status.num_philo);
	return (0);
}
