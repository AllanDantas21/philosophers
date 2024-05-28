/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:00:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/28 01:34:27 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/philosophers.h"

static int  philos_inits(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = data->philo_nbr;
	data->array_forks = malloc(sizeof(pthread_mutex_t)
			* data->philo_nbr);
	data->array_philos = malloc(sizeof(t_philo *) * data->philo_nbr);
	if (!data->array_forks || !data->array_forks)
		return (-1);
	while (--i >= 0 )
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (-1);
		philo->id = i;
		philo->thread = 0 ;
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

int	init_data(t_data *data)
{
	if (philos_inits(data))
		return (-1);
	if (init_mutex(data))
		return (-1);
	return (0);
}