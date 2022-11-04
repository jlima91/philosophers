/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:21:38 by jlima             #+#    #+#             */
/*   Updated: 2022/09/19 10:09:29 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Method created.
 * A loop is created that is true until the current time is bigger than the
 * philo's next time to eat, meaning he didin't eat so he is dead.
 */

void	*check_death(void *arg)
{
	t_philo	*ptr;

	ptr = (t_philo *)arg;
	while (ptr->tab->breaker)
	{
		usleep(10);
		if (ft_current_time(ptr)
			- ptr->tab->starting_time >= ptr->next_dying_time)
		{
			ptr->tab->breaker = 0;
			pthread_mutex_lock(&ptr->tab->death);
			pthread_mutex_lock(&ptr->eating);
			usleep(1000);
			pthread_mutex_unlock(&ptr->tab->message);
			ft_destroy_mutex(ptr);
			usleep(500);
			printf("%i\t%i died\n", ptr->next_dying_time, ptr->philosopher_id);
		}
	}
	return (0);
}

/**
 * Method created.
 * First the even number philosophers are ordered to sleep 30 micro seconds,
 * so that the odd ones start eating first.
 * A new thread is created to check when a philo dies. That thread is detached
 * so it can run independent. We choose to detach it because we don't need it
 * to finish, we just want it to run until it triggers.
 * The method then enter a loop that it's true until a death or number of times
 * to eat is fullfilled.
 */

void	*dinner(void *arg)
{
	t_philo		*ptr;
	pthread_t	death;

	ptr = (t_philo *)arg;
	if (ptr->philosopher_id % 2 == 0)
		usleep(30000);
	if (pthread_create(&death, NULL, check_death, ptr) != 0)
		return (0);
	pthread_detach(death);
	while (ptr->tab->breaker)
	{
		ft_eating(ptr);
		if (++ptr->times_eaten == ptr->tab->times_to_eat)
			break ;
		ft_sleeping(ptr);
		ft_thinking(ptr);
	}
	return (0);
}

/**
 * Allocating memory for each philosopher.
 * Initializing struct variables for each philosopher.
 * Asigning philosopher' struct pointer to the universe struct.
 */

t_philo	*ft_init_philo(t_env *table)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * table->num_of_philos);
	if (!philo)
		return (NULL);
	i = -1;
	while (table->num_of_philos > ++i)
	{
		philo[i].philosopher_id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = i + 1;
		philo[i].times_eaten = 0;
		philo[i].next_dying_time = table->time_to_die + 1;
		pthread_mutex_init(table->forks + i, NULL);
		pthread_mutex_init(&(philo[i]).eating, NULL);
		philo[i].tab = table;
	}
	philo[--i].right_fork = 0;
	table->philosopher = philo;
	return (philo);
}

/**
 * Initializing the universe struct variables.
 * Initializing the mutex for the universe.
 */

void	ft_init_env(char *argv[], t_env *table)
{
	int	num;

	num = atoi(argv[1]);
	table->num_of_philos = num;
	table->threads = malloc(sizeof(pthread_t) * num);
	table->forks = malloc(sizeof(pthread_mutex_t) * num);
	table->time_to_die = atoi(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]);
	table->times_to_eat = 0;
	if (argv[5])
		table->times_to_eat = atoi(argv[5]);
	table->breaker = 1;
	pthread_mutex_init(&table->message, NULL);
	pthread_mutex_init(&table->death, NULL);
}

/**
 * Checking arguments inputed by user.
 * Initialize struct variables for the universe and for the philosopher.
 * Loop for creating multiple threads.
 * Loop for creating thread_join.
 * Cleaning memory and destroying mutex.
 */

int	main(int argc, char *argv[])
{
	t_env	table;
	t_philo	*philo;
	int		i;

	if (!ft_check_args(argc, argv))
		return (0);
	ft_init_env(argv, &table);
	philo = ft_init_philo(&table);
	table.starting_time = ft_current_time(philo);
	i = -1;
	while (++i < table.num_of_philos)
	{
		if (pthread_create(&table.threads[i], NULL, &dinner, philo + i) != 0)
			return (1);
	}
	i = -1;
	while (++i < table.num_of_philos)
	{
		if (pthread_join(table.threads[i], NULL) != 0)
			return (1);
	}
	philo->tab->breaker = 0;
	ft_clean(philo);
	usleep(10000);
	return (0);
}

/**
 * pthread_join:
 * Join is a synchronization method that blocks the calling thread (that is,
 * the thread that calls the method, in this case the main funtion) until the
 * thread whose join method is called has completed. This ensures our main 
 * funtion doesn't reach "return" until the new threads finish.
 * Use this method to ensure that a thread has been terminated. The caller
 * will block indefinitely if the thread does not terminate.
 */

/**
 * pthread_detach:
 * Detaches the thread represented by the object from the calling thread,
 * allowing them to execute independently from each other. Both threads
 * continue without blocking nor synchronizing in any way. Note that when
 * either one ends execution, its resources are released.
 */

/**
 * A mutex can only be destroyed by the thread that created it.
 */