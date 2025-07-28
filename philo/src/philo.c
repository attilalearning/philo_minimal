#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "philo.h"

/*
		ALLOWED FUNCTIONS:
		===================

		memset,
		printf, write,

		malloc, free,

		usleep, gettimeofday,

		pthread_create, pthread_detach, pthread_join,

		pthread_mutex_init, pthread_mutex_destroy,
		pthread_mutex_lock, pthread_mutex_unlock
*/

void	*philo_life_cycle(void *arg)
{
	t_philo_env		*pe;
	t_philo			*philo;
	int				i;
	int				idle_time_micros;

	pe = (t_philo_env *)arg;
	i = pe->philo_idx;
	philo = &pe->sim->philos[i];
	idle_time_micros = 10000 * (10 / philo->name);
	safeint_set_value(&philo->idle_time, idle_time_micros);
	safeint_set_value(&philo->total_time_lived_micros, 0);
	printf("philo %d -- thread created, waiting for start\n",
			philo->name);
	while (!safeint_get_value(pe->sim->is_running))
		usleep(100);
	printf("philo %d -- NOW RUNNING " \
		"(idle time set to %d micro seconds)...\n",
			philo->name, idle_time_micros);
	while (1)
	{
		if (!safeint_get_value(pe->sim->is_running)
			|| safeint_get_value(philo->is_deceased))
			break ;
		printf("philo %d -- 'while loop' or 'living' AND " \
			"usleep-ing %d micro seconds", philo->name, idle_time_micros);
		safeint_inc_value(&philo->total_time_lived_micros, idle_time_micros);
		printf(" (ttl_micros = %d)\n",
			safeint_get_value(philo->total_time_lived_micros));
		usleep(idle_time_micros);
	}
	printf("philo %d -- thread ended!\n", philo->name);
	free(pe);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;
	int				i;
	int				random_ttd_ms;
	t_philo			*philo;

	if (failed(args_check(argc, argv)))
		return (EXIT_FAILURE);
	
	ft_atoi(argv[arg_no_of_philos], &sim.no_of_philos);
	sim.philo_to_die = 0;
	sim.ttd_ms = 0;
	if (argv[arg_2nd_arg][0] == '-')
	{
		ft_atoi(argv[arg_2nd_arg], &sim.ttd_ms);
		sim.ttd_ms *= -1;
		printf("A philosopher will die after %d ms have elapsed\n",
			sim.ttd_ms);
	}
	else
	{
		ft_atoi(argv[arg_2nd_arg], &sim.philo_to_die);
		srand(time(NULL));
		random_ttd_ms = (rand() % 10 + 1) * 1000;
		printf("Philosopher %d will die after %d ms (choosen randomly) have elapsed\n",
			sim.philo_to_die, random_ttd_ms);
	}

	pthread_mutex_init(&sim.printf_mutex, NULL);
	pthread_mutex_init(&sim.is_running.mutex, NULL);

	safeint_set_value(&sim.is_running, false);
	create_simple_philo_threads(&sim);
	safeint_set_value(&sim.is_running, true);

	i = 0;
	while (1)
	{
		philo = &sim.philos[i];
		if ((sim.ttd_ms
			&& safeint_get_value(philo->total_time_lived_micros) >= sim.ttd_ms * 1000)
			|| (sim.philo_to_die && i == sim.philo_to_die
			&& safeint_get_value(philo->total_time_lived_micros) >= random_ttd_ms * 1000))
		{
			safeint_set_value(&philo->is_deceased, true);
			safeint_set_value(&sim.is_running, false);
			break ;
		}
		usleep(10000);
		i++;
		if (i >= sim.no_of_philos)
			i = 0;
	}

	printf("philo %d died!\n", philo->name);

	printf("Waiting to join all philo threads...\n");
	join_simple_philo_threads(&sim);
	pthread_mutex_destroy(&sim.printf_mutex);
	pthread_mutex_destroy(&sim.is_running.mutex);

	printf("All done, clean exit.\n");
	return (EXIT_SUCCESS);
}
