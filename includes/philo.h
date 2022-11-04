/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:20:03 by jlima             #+#    #+#             */
/*   Updated: 2022/07/26 16:02:23 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

/* *********************************STRUCTURES****************************** */

typedef struct s_philo
{
	int				philosopher_id;
	int				left_fork;
	int				right_fork;
	int				next_dying_time;
	int				times_eaten;
	pthread_mutex_t	eating;
	struct s_env	*tab;
}					t_philo;

typedef struct s_env
{
	pthread_t		*threads;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				starting_time;
	int				times_to_eat;
	int				breaker;
	struct timeval	current_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	pthread_mutex_t	death;
	t_philo			*philosopher;
}					t_env;

/* **********************************FUNTIONS******************************* */

void				ft_eating(t_philo *ptr);
void				ft_sleeping(t_philo *ptr);
void				ft_thinking(t_philo *ptr);
void				ft_destroy_mutex(t_philo *ptr);
void				ft_write_message(t_philo *ptr, int num);
int					ft_current_time(t_philo *ptr);
int					ft_check_args(int argc, char *argv[]);
int					ft_arg_error(int num);
void				ft_clean(t_philo *ptr);

#endif