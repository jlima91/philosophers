/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:21:18 by jlima             #+#    #+#             */
/*   Updated: 2022/07/26 16:01:57 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write_message(t_philo *ptr, int num)
{
	int	time;

	if (!ptr->tab->breaker)
		return ;
	pthread_mutex_lock(&ptr->tab->message);
	time = ft_current_time(ptr) - ptr->tab->starting_time;
	if (num == 1)
		printf("%i\t%i has taken a fork\n", time, ptr->philosopher_id);
	else if (num == 2)
	{
		pthread_mutex_lock(&ptr->eating);
		ptr->next_dying_time = time + ptr->next_dying_time;
		printf("%i\t%i is eating\n", time, ptr->philosopher_id);
		pthread_mutex_unlock(&ptr->eating);
	}
	else if (num == 3)
		printf("%i\t%i is sleeping\n", time, ptr->philosopher_id);
	else if (num == 4)
		printf("%i\t%i is thinking\n", time, ptr->philosopher_id);
	pthread_mutex_unlock(&ptr->tab->message);
}

/**
 * The user inputs time in miliseconds and we need to output it in
 * miliseconds also.
 * Struct timeval outputs time in seconds or microseconds, therefore a
 * conversion is needed.
 * The gettimeofday() function gets the system’s clock time.
 * The timeval structure represents a calendar time. It has two members:
 * tv_sec: It is the number of seconds since the epoch.
 * tv_usec: It is additional microseconds after number of seconds calculation
 * since the epoch. 
 * tv_sec is multiplied for 1000 to convert seconds in miliseconds.
 * tv_usec is divided for 1000 to convert microseconds to miliseconds.
 */

int	ft_current_time(t_philo *ptr)
{
	gettimeofday(&ptr->tab->current_time, NULL);
	return ((ptr->tab->current_time.tv_sec * 1000)
		+ (ptr->tab->current_time.tv_usec / 1000));
}

void	ft_destroy_mutex(t_philo *ptr)
{
	int	i;

	ptr->tab->time_to_eat = 0;
	ptr->tab->time_to_sleep = 0;
	i = -1;
	while (ptr->tab->num_of_philos > ++i)
	{
		pthread_mutex_unlock(ptr->tab->forks + i);
		pthread_mutex_destroy(ptr->tab->forks + i);
	}
	pthread_mutex_unlock(&ptr->tab->message);
	pthread_mutex_destroy(&ptr->tab->message);
}

void	ft_clean_memory(t_philo *ptr)
{
	free(ptr->tab->forks);
	free(ptr->tab->threads);
	free(ptr);
}

void	ft_clean(t_philo *ptr)
{
	ft_destroy_mutex(ptr);
	ft_clean_memory(ptr);
}
