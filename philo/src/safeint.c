/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safeint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:01:04 by aistok            #+#    #+#             */
/*   Updated: 2025/07/28 12:02:01 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		safeint_get_value(t_safeint	si)
{
	int	value;

	pthread_mutex_lock(&si.mutex);
	value = si.value;
	pthread_mutex_unlock(&si.mutex);
	return (value);
}

void	safeint_set_value(t_safeint	*si, int value)
{
	pthread_mutex_lock(&si->mutex);
	si->value = value;
	pthread_mutex_unlock(&si->mutex);
}

void	safeint_inc_value(t_safeint	*si, int step)
{
	pthread_mutex_lock(&si->mutex);
	si->value += step;
	pthread_mutex_unlock(&si->mutex);
}
