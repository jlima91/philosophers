/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:08:01 by jlima             #+#    #+#             */
/*   Updated: 2022/07/26 11:53:54 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_arg_error(int num)
{
	if (num == 1)
	{
		printf(ANSI_COLOR_GREEN);
		printf("1 argument must be:\tnumber of philosophers.\n");
		printf("2 argument must be:\ttime to die.\n");
		printf("3 argument must be:\ttime to eat.\n");
		printf("4 argument must be:\ttime to sleep.\n");
		printf("\n5 argument is optional, but must be:\ttimes to eat.\n");
		printf(ANSI_COLOR_RESET);
	}
	if (num == 2)
	{
		printf(ANSI_COLOR_RED "Please input a valid number of Philosophers.\n");
		printf(ANSI_COLOR_RESET);
	}
	if (num == 3)
		printf(ANSI_COLOR_RED "Please input a valid time.\n" ANSI_COLOR_RESET);
	if (num == 4)
	{
		printf(ANSI_COLOR_RED "Please input a valid number for times to eat.\n");
		printf(ANSI_COLOR_RESET);
	}
	return (0);
}

int	ft_check_args(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (ft_arg_error(1));
	if (!check_is_number(argv[1]))
		return (ft_arg_error(2));
	if (!check_is_number(argv[2]) || !check_is_number(argv[3])
		|| !check_is_number(argv[4]))
		return (ft_arg_error(3));
	if (argv[5] && !check_is_number(argv[5]))
		return (ft_arg_error(4));
	return (1);
}
