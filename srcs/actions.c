/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:56 by jlima             #+#    #+#             */
/*   Updated: 2022/07/26 11:49:03 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *ptr)
{
	pthread_mutex_lock(&ptr->tab->forks[ptr->left_fork]);
	ft_write_message(ptr, FORK);
	pthread_mutex_lock(&ptr->tab->forks[ptr->right_fork]);
	ft_write_message(ptr, FORK);
	ft_write_message(ptr, EAT);
	usleep(ptr->tab->time_to_eat * 1000);
	pthread_mutex_unlock(&ptr->tab->forks[ptr->left_fork]);
	pthread_mutex_unlock(&ptr->tab->forks[ptr->right_fork]);
}

void	ft_sleeping(t_philo *ptr)
{
	ft_write_message(ptr, SLEEP);
	usleep(ptr->tab->time_to_sleep * 1000);
}

void	ft_thinking(t_philo *ptr)
{
	ft_write_message(ptr, THINK);
}
