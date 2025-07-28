/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:06:28 by aistok            #+#    #+#             */
/*   Updated: 2025/07/28 12:14:41 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

void	create_simple_philo_threads(t_simulation *sim)
{
	int			i;
	t_philo_env	*pe;

	sim->philos = malloc(sizeof(t_philo) * sim->no_of_philos);
	philo_mutexes_init(sim);
	i = -1;
	while (++i < sim->no_of_philos)
	{
		sim->philos[i].name = i + 1;
		pe = malloc(sizeof(t_philo_env));
		pe->sim = sim;
		pe->philo_idx = i;
		pthread_create(&sim->philos[i].thread, NULL, philo_life_cycle, pe);
	}
}

void	join_simple_philo_threads(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->no_of_philos)
		pthread_join(sim->philos[i].thread, NULL);
	philo_mutexes_destroy(sim);
	free(sim->philos);
}
