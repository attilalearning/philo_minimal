/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:35:37 by username          #+#    #+#             */
/*   Updated: 2025/07/28 13:28:15 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <aio.h>
# include <stdbool.h>
# include <pthread.h>

enum e_prog_args
{
	arg_progname = 0,
	arg_no_of_philos,
	arg_2nd_arg
};

typedef struct s_safeint
{
	pthread_mutex_t	mutex;
	int				value;
}	t_safeint;

typedef struct s_philo
{
	int				name;
	t_safeint		idle_time;
	t_safeint		total_time_lived_micros;
	t_safeint		is_deceased;
	pthread_t		thread;
}   t_philo;

typedef struct s_simulation
{
	t_philo			*philos;
	int				no_of_philos;
	int				philo_to_die;
	int				ttd_ms;
	pthread_mutex_t	printf_mutex;
	t_safeint		is_running;
}	t_simulation;

typedef struct s_philo_env
{
	t_simulation	*sim;
	int				philo_idx;
}	t_philo_env;

bool	ft_atoi(const char *nptr, int *number);
int		ft_isspace(const char c);
int		ft_isdigit(int c);

int		failed(int ret_code);

int		safeint_get_value(t_safeint	si);
void	safeint_set_value(t_safeint	*si, int value);
void	safeint_inc_value(t_safeint	*si, int step);

void	*philo_life_cycle(void *arg);

void	philo_mutexes_init(t_simulation *sim);
void	philo_mutexes_destroy(t_simulation *sim);

void	create_simple_philo_threads(t_simulation *sim);
void	join_simple_philo_threads(t_simulation *sim);

int		args_check(int argc, char **argv);

#endif
