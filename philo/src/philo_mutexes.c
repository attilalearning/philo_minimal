/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:02:45 by aistok            #+#    #+#             */
/*   Updated: 2025/07/28 12:03:09 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_mutexes_init(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->no_of_philos)
	{
		pthread_mutex_init(&sim->philos[i].idle_time.mutex, NULL);
		pthread_mutex_init(&sim->philos[i].is_deceased.mutex, NULL);
		pthread_mutex_init(&sim->philos[i].total_time_lived_micros.mutex, NULL);
	}
}

void	philo_mutexes_destroy(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->no_of_philos)
	{
		pthread_mutex_destroy(&sim->philos[i].idle_time.mutex);
		pthread_mutex_destroy(&sim->philos[i].is_deceased.mutex);
		pthread_mutex_destroy(&sim->philos[i].total_time_lived_micros.mutex);
	}
}
