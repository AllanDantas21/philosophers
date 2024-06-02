/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/29 02:34:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/philosophers.h"

static int  philos_inits(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = data->philo_nbr;
	while (--i >= 0 )
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (-1);
		philo->id = i + 1;
		philo->is_full = false;
		philo->nbr_eats = 0;
		philo->eats_total = data->eats_total;
		philo->last_eat = 0;
		philo->time_sleep = data->time_sleep;
		philo->time_eat = data->time_eat;
		philo->time_die = data->time_die;
		philo->start_simulation = data->start_simulation;
		philo->thread = 0;
		philo->left_fork = data->array_forks + i;
		philo->right_fork = data->array_forks + ((i + 1) % data->philo_nbr);
		philo->table = data;
		data->array_philos[i] = philo;
	}
	return (0);
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&data->array_forks[i], NULL))
			return (-1);
	}
	return (0);
}

static int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_simulation = get_time();
	while (++i < data->philo_nbr)
	{
		if (pthread_create(&data->array_philos[i]->thread, NULL, routine, data->array_philos[i]))
			return (1);
	}
	return (0);
}

int	init_data(t_data *data)
{
	if (philos_inits(data))
		return (-1);
	if (init_mutex(data))
		return (-1);
	if (init_threads(data))
		return (-1);
	return (0);
}
