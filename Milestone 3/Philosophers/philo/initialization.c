/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:58:14 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/29 12:41:28 by kagoh            ###   ########.fr       */
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
	init_forks(status);
	init_philo(status);
}

void	init_forks(t_status *status)
{
	size_t	i;

	i = 0;
	status->forks = malloc(status->num_philo * sizeof(pthread_mutex_t));
	if (!status->forks)
		return ;
	while (i < status->num_philo)
	{
		pthread_mutex_init(&status->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_status *status)
{
	size_t	i;

	i = 0;
	status->philos = malloc(status->num_philo * sizeof(t_philo));
	if (!status->philos)
		return ;
	while (i < status->num_philo)
	{
		status->philos[i].id = i + 1;
		status->philos[i].sleep_time = status->time_to_sleep;
		status->philos[i].eat_time = status->time_to_eat;
		status->philos[i].die_time = status->time_to_die;
		status->philos[i].last_meal = 0;
		status->philos[i].meal_count = 0;
		status->philos[i].dead = 0;
		status->philos[i].status = status;
		status->philos[i].lock = &status->status_lock;
		status->philos[i].l_fork = &status->forks[i];
		status->philos[i].r_fork = &status->forks[(i + 1) % status->num_philo];
		i++;
	}
}

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
	if (status->philos)
		free(status->philos);
}

// int main(int argc, char **argv)
// {
//     t_status status;

//     // Validate input arguments
//     if (validate_input(argc, argv) != 0)
//     {
//         printf("Invalid input.\n");
//         return (1);
//     }

//     // Initialize the status and philosophers structures
//     init_status(&status, argv);

//     // Display initialized values to check if everything was set correctly
//     printf("Simulation Setup:\n");
//     printf("Number of Philosophers: %zu\n", status.num_philo);
//     printf("Time to Die: %zu\n", status.time_to_die);
//     printf("Time to Eat: %zu\n", status.time_to_eat);
//     printf("Time to Sleep: %zu\n", status.time_to_sleep);
//     if (status.max_meals != (size_t)-1)
//         printf("Max Meals: %zu\n", status.max_meals);
//     else
//         printf("Max Meals: No limit\n");

//     // Check each philosopher's setup
//     for (size_t i = 0; i < status.num_philo; i++)
//     {
//         printf("\nPhilosopher %zu:\n", status.philos[i].id);
//         printf("  Left Fork: %p\n", (void*)status.philos[i].l_fork);
//         printf("  Right Fork: %p\n", (void*)status.philos[i].r_fork);
//         printf("  Last Meal: %zu\n", status.philos[i].last_meal);
//         printf("  Meal Count: %d\n", status.philos[i].meal_count);
//     }

//     // Clean up resources after the test
//     cleanup(&status, status.num_philo);

//     return (0);
// }