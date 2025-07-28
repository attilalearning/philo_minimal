/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:55:01 by aistok            #+#    #+#             */
/*   Updated: 2025/07/24 21:11:36 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <errno.h>
#include "philo.h"

/*
 *	DESCRIPTION
 *	The atoi() function converts the initial portion of the string pointed
 *	to by nptr to int, and stores it to the pointer pointed to by *number.
 *	The behavior is similar to
 *		strtol(nptr, NULL, 10);
 *
 *	RETURN VALUE
 *	Returns true if the conversion is fully successful, and the number will be
 *	the value obtained until the error ocurred.
 *	And, it will return false if a letter was detected during conversion.
 */
bool	ft_atoi(const char *nptr, int *number)
{
	char	sign;

	sign = 1;
	*number = 0;
	while (*nptr != 0 && ft_isspace(*nptr))
		nptr++;
	if (*nptr != 0 && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = sign * (-1);
		nptr++;
	}
	while (*nptr != 0 && ft_isdigit(*nptr))
	{
		*number = *number * 10 + (*nptr - '0');
		nptr++;
	}
	*number = *number * sign;
	if (*nptr != 0 && !ft_isdigit(*nptr))
		return (errno = EINVAL, false);
	return (true);
}
