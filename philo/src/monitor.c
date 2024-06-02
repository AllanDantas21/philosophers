/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:50:03 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/02 12:25:59 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	check_is_alive(t_philo	*p)
{
	long long now;

	now = get_time() - p->start_simulation;
	if (now - p->last_eat > p->time_die)
	{
		pthread_mutex_lock(&p->table->mutex);
		p->table->is_all_alive = false;
		pthread_mutex_unlock(&p->table->mutex);
		print_status(p, DEAD);
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
	while (data->is_all_alive)
	{
		if (check_philo_death(data))
			return (1);
		usleep(1200);
	}
	return (0);
}

