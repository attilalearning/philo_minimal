/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:03:28 by aistok            #+#    #+#             */
/*   Updated: 2025/07/28 12:14:09 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

/*
 *	Minimal error checking
 *
 * 	NOTE: Should print to stderr! (TO-DO)
 */
int	args_check(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s NOP WP|TTD\n", argv[arg_progname]);
		printf("  NOP - number of philosophers\n");
		printf("  WP  - a positive number indicating which philosophers should die (starting from 1)\n");
		printf("  TTD - a negative number, indicating after how many milliseconds a philosophers should die\n");
		printf("\n");
		printf("  Either WP or TTD to be given!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
