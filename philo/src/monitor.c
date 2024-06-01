/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:50:03 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/01 14:11:23 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_is_alive(t_philo	*philo)
{
	long long now;

	now = get_time() - philo->table->time_simulation;
	if (now - philo->last_eat > philo->table->time_die)
	{
		print_status(philo, DEAD);
		philo->table->is_all_alive = false;
		return (-1);
	}
	return (0);
}

static int	check_philo_death(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		if (check_is_alive(data->array_philos[i]))
			return (-1);
	}
	return (0);
}

int	monitor_routine(t_data *data)
{
	while (data->is_all_alive == true)
	{
		if (check_philo_death(data))
		{
			data->is_all_alive = false;
			return (1);
		}
		usleep(100);
	}
	return (0);
}

