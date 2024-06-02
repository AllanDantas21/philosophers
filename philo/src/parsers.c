/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:08:36 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/27 19:05:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/philosophers.h"

static int	check_limits(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i++]) > 2147483647)
			return (1);
	}
	return (0);
}

int	check_args(char **av)
{
	av++;
	if (check_input_digit(av) || check_limits(av))
	{
		printf(RED"parse error: incorrect input"RESET);
		return(-1);
	}
	return (0);
}

int	parse_data(t_data *data, char **av)
{
	data->philo_nbr = ft_atol(av[1]);
	data->time_die = ft_atol(av[2]);
	data->time_eat = ft_atol(av[3]);
	data->time_sleep = ft_atol(av[4]);
	if (av[5])
		data->eats_total = ft_atol(av[5]);
	 else
		data->eats_total = -1;
	data->is_all_alive = true;
	data->count_full = 0;
	data->start_simulation = get_time();
	if (pthread_mutex_init(&data->mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&data->print_mtx, NULL))
		return (-1);
	data->array_forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	data->array_philos = malloc(sizeof(t_philo *) * data->philo_nbr);
	if (!data->array_forks || !data->array_forks)
		return (-1);
	return (0);
}
